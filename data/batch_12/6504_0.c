static bfd_boolean srec_scan ( bfd * abfd ) {
 int c ;
 unsigned int lineno = 1 ;
 bfd_boolean error = FALSE ;
 bfd_byte * buf = NULL ;
 size_t bufsize = 0 ;
 asection * sec = NULL ;
 char * symbuf = NULL ;
 if ( bfd_seek ( abfd , ( file_ptr ) 0 , SEEK_SET ) != 0 ) goto error_return ;
 while ( ( c = srec_get_byte ( abfd , & error ) ) != EOF ) {
 if ( c != 'S' && c != '\r' && c != '\n' ) sec = NULL ;
 switch ( c ) {
 default : srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 case '\n' : ++ lineno ;
 break ;
 case '\r' : break ;
 case '$' : while ( ( c = srec_get_byte ( abfd , & error ) ) != '\n' && c != EOF ) ;
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 ++ lineno ;
 break ;
 case ' ' : do {
 bfd_size_type alc ;
 char * p , * symname ;
 bfd_vma symval ;
 while ( ( c = srec_get_byte ( abfd , & error ) ) != EOF && ( c == ' ' || c == '\t' ) ) ;
 if ( c == '\n' || c == '\r' ) break ;
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 alc = 10 ;
 symbuf = ( char * ) bfd_malloc ( alc + 1 ) ;
 if ( symbuf == NULL ) goto error_return ;
 p = symbuf ;
 * p ++ = c ;
 while ( ( c = srec_get_byte ( abfd , & error ) ) != EOF && ! ISSPACE ( c ) ) {
 if ( ( bfd_size_type ) ( p - symbuf ) >= alc ) {
 char * n ;
 alc *= 2 ;
 n = ( char * ) bfd_realloc ( symbuf , alc + 1 ) ;
 if ( n == NULL ) goto error_return ;
 p = n + ( p - symbuf ) ;
 symbuf = n ;
 }
 * p ++ = c ;
 }
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 * p ++ = '\0' ;
 symname = ( char * ) bfd_alloc ( abfd , ( bfd_size_type ) ( p - symbuf ) ) ;
 if ( symname == NULL ) goto error_return ;
 strcpy ( symname , symbuf ) ;
 free ( symbuf ) ;
 symbuf = NULL ;
 while ( ( c = srec_get_byte ( abfd , & error ) ) != EOF && ( c == ' ' || c == '\t' ) ) ;
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 if ( c == '$' ) {
 c = srec_get_byte ( abfd , & error ) ;
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 }
 symval = 0 ;
 while ( ISHEX ( c ) ) {
 symval <<= 4 ;
 symval += NIBBLE ( c ) ;
 c = srec_get_byte ( abfd , & error ) ;
 if ( c == EOF ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 }
 if ( ! srec_new_symbol ( abfd , symname , symval ) ) goto error_return ;
 }
 while ( c == ' ' || c == '\t' ) ;
 if ( c == '\n' ) ++ lineno ;
 else if ( c != '\r' ) {
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 break ;
 case 'S' : {
 file_ptr pos ;
 char hdr [ 3 ] ;
 unsigned int bytes , min_bytes ;
 bfd_vma address ;
 bfd_byte * data ;
 unsigned char check_sum ;
 pos = bfd_tell ( abfd ) - 1 ;
 if ( bfd_bread ( hdr , ( bfd_size_type ) 3 , abfd ) != 3 ) goto error_return ;
 if ( ! ISHEX ( hdr [ 1 ] ) || ! ISHEX ( hdr [ 2 ] ) ) {
 if ( ! ISHEX ( hdr [ 1 ] ) ) c = hdr [ 1 ] ;
 else c = hdr [ 2 ] ;
 srec_bad_byte ( abfd , lineno , c , error ) ;
 goto error_return ;
 }
 check_sum = bytes = HEX ( hdr + 1 ) ;
 min_bytes = 3 ;
 if ( hdr [ 0 ] == '2' || hdr [ 0 ] == '8' ) min_bytes = 4 ;
 else if ( hdr [ 0 ] == '3' || hdr [ 0 ] == '7' ) min_bytes = 5 ;
 if ( bytes < min_bytes ) {
 ( * _bfd_error_handler ) ( _ ( "%B:%d: byte count %d too small\n" ) , abfd , lineno , bytes ) ;
 bfd_set_error ( bfd_error_bad_value ) ;
 goto error_return ;
 }
 if ( bytes * 2 > bufsize ) {
 if ( buf != NULL ) free ( buf ) ;
 buf = ( bfd_byte * ) bfd_malloc ( ( bfd_size_type ) bytes * 2 ) ;
 if ( buf == NULL ) goto error_return ;
 bufsize = bytes * 2 ;
 }
 if ( bfd_bread ( buf , ( bfd_size_type ) bytes * 2 , abfd ) != bytes * 2 ) goto error_return ;
 -- bytes ;
 address = 0 ;
 data = buf ;
 switch ( hdr [ 0 ] ) {
 case '0' : case '5' : sec = NULL ;
 break ;
 case '3' : check_sum += HEX ( data ) ;
 address = HEX ( data ) ;
 data += 2 ;
 -- bytes ;
 case '2' : check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 -- bytes ;
 case '1' : check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 bytes -= 2 ;
 if ( sec != NULL && sec -> vma + sec -> size == address ) {
 sec -> size += bytes ;
 }
 else {
 char secbuf [ 20 ] ;
 char * secname ;
 bfd_size_type amt ;
 flagword flags ;
 sprintf ( secbuf , ".sec%d" , bfd_count_sections ( abfd ) + 1 ) ;
 amt = strlen ( secbuf ) + 1 ;
 secname = ( char * ) bfd_alloc ( abfd , amt ) ;
 strcpy ( secname , secbuf ) ;
 flags = SEC_HAS_CONTENTS | SEC_LOAD | SEC_ALLOC ;
 sec = bfd_make_section_with_flags ( abfd , secname , flags ) ;
 if ( sec == NULL ) goto error_return ;
 sec -> vma = address ;
 sec -> lma = address ;
 sec -> size = bytes ;
 sec -> filepos = pos ;
 }
 while ( bytes > 0 ) {
 check_sum += HEX ( data ) ;
 data += 2 ;
 bytes -- ;
 }
 check_sum = 255 - ( check_sum & 0xff ) ;
 if ( check_sum != HEX ( data ) ) {
 ( * _bfd_error_handler ) ( _ ( "%B:%d: Bad checksum in S-record file\n" ) , abfd , lineno ) ;
 bfd_set_error ( bfd_error_bad_value ) ;
 goto error_return ;
 }
 break ;
 case '7' : check_sum += HEX ( data ) ;
 address = HEX ( data ) ;
 data += 2 ;
 case '8' : check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 case '9' : check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 check_sum += HEX ( data ) ;
 address = ( address << 8 ) | HEX ( data ) ;
 data += 2 ;
 abfd -> start_address = address ;
 check_sum = 255 - ( check_sum & 0xff ) ;
 if ( check_sum != HEX ( data ) ) {
 ( * _bfd_error_handler ) ( _ ( "%B:%d: Bad checksum in S-record file\n" ) , abfd , lineno ) ;
 bfd_set_error ( bfd_error_bad_value ) ;
 goto error_return ;
 }
 if ( buf != NULL ) free ( buf ) ;
 return TRUE ;
 }
 }
 break ;
 }
 }
 if ( error ) goto error_return ;
 if ( buf != NULL ) free ( buf ) ;
 return TRUE ;
 error_return : if ( symbuf != NULL ) free ( symbuf ) ;
 if ( buf != NULL ) free ( buf ) ;
 return FALSE ;
 }