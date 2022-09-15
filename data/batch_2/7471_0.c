REPLACE * init_replace ( char * * from , char * * to , uint count , char * word_end_chars ) {
 static const int SPACE_CHAR = 256 ;
 static const int END_OF_LINE = 258 ;
 uint i , j , states , set_nr , len , result_len , max_length , found_end , bits_set , bit_nr ;
 int used_sets , chr , default_state ;
 char used_chars [ LAST_CHAR_CODE ] , is_word_end [ 256 ] ;
 char * pos , * to_pos , * * to_array ;
 REP_SETS sets ;
 REP_SET * set , * start_states , * word_states , * new_set ;
 FOLLOWS * follow , * follow_ptr ;
 REPLACE * replace ;
 FOUND_SET * found_set ;
 REPLACE_STRING * rep_str ;
 DBUG_ENTER ( "init_replace" ) ;
 for ( i = result_len = max_length = 0 , states = 2 ;
 i < count ;
 i ++ ) {
 len = replace_len ( from [ i ] ) ;
 if ( ! len ) {
 errno = EINVAL ;
 DBUG_RETURN ( 0 ) ;
 }
 states += len + 1 ;
 result_len += ( uint ) strlen ( to [ i ] ) + 1 ;
 if ( len > max_length ) max_length = len ;
 }
 bzero ( ( char * ) is_word_end , sizeof ( is_word_end ) ) ;
 for ( i = 0 ;
 word_end_chars [ i ] ;
 i ++ ) is_word_end [ ( uchar ) word_end_chars [ i ] ] = 1 ;
 if ( init_sets ( & sets , states ) ) DBUG_RETURN ( 0 ) ;
 found_sets = 0 ;
 if ( ! ( found_set = ( FOUND_SET * ) my_malloc ( sizeof ( FOUND_SET ) * max_length * count , MYF ( MY_WME ) ) ) ) {
 free_sets ( & sets ) ;
 DBUG_RETURN ( 0 ) ;
 }
 ( void ) make_new_set ( & sets ) ;
 make_sets_invisible ( & sets ) ;
 used_sets = - 1 ;
 word_states = make_new_set ( & sets ) ;
 start_states = make_new_set ( & sets ) ;
 if ( ! ( follow = ( FOLLOWS * ) my_malloc ( ( states + 2 ) * sizeof ( FOLLOWS ) , MYF ( MY_WME ) ) ) ) {
 free_sets ( & sets ) ;
 my_free ( found_set ) ;
 DBUG_RETURN ( 0 ) ;
 }
 for ( i = 0 , states = 1 , follow_ptr = follow + 1 ;
 i < count ;
 i ++ ) {
 if ( from [ i ] [ 0 ] == '\\' && from [ i ] [ 1 ] == '^' ) {
 internal_set_bit ( start_states , states + 1 ) ;
 if ( ! from [ i ] [ 2 ] ) {
 start_states -> table_offset = i ;
 start_states -> found_offset = 1 ;
 }
 }
 else if ( from [ i ] [ 0 ] == '\\' && from [ i ] [ 1 ] == '$' ) {
 internal_set_bit ( start_states , states ) ;
 internal_set_bit ( word_states , states ) ;
 if ( ! from [ i ] [ 2 ] && start_states -> table_offset == ( uint ) ~ 0 ) {
 start_states -> table_offset = i ;
 start_states -> found_offset = 0 ;
 }
 }
 else {
 internal_set_bit ( word_states , states ) ;
 if ( from [ i ] [ 0 ] == '\\' && ( from [ i ] [ 1 ] == 'b' && from [ i ] [ 2 ] ) ) internal_set_bit ( start_states , states + 1 ) ;
 else internal_set_bit ( start_states , states ) ;
 }
 for ( pos = from [ i ] , len = 0 ;
 * pos ;
 pos ++ ) {
 follow_ptr -> chr = ( uchar ) * pos ;
 follow_ptr -> table_offset = i ;
 follow_ptr -> len = ++ len ;
 follow_ptr ++ ;
 }
 follow_ptr -> chr = 0 ;
 follow_ptr -> table_offset = i ;
 follow_ptr -> len = len ;
 follow_ptr ++ ;
 states += ( uint ) len + 1 ;
 }
 for ( set_nr = 0 , pos = 0 ;
 set_nr < sets . count ;
 set_nr ++ ) {
 set = sets . set + set_nr ;
 default_state = 0 ;
 for ( i = ( uint ) ~ 0 ;
 ( i = get_next_bit ( set , i ) ) ;
 ) {
 if ( ! follow [ i ] . chr ) {
 if ( ! default_state ) default_state = find_found ( found_set , set -> table_offset , set -> found_offset + 1 ) ;
 }
 }
 copy_bits ( sets . set + used_sets , set ) ;
 if ( ! default_state ) or_bits ( sets . set + used_sets , sets . set ) ;
 bzero ( ( char * ) used_chars , sizeof ( used_chars ) ) ;
 for ( i = ( uint ) ~ 0 ;
 ( i = get_next_bit ( sets . set + used_sets , i ) ) ;
 ) {
 used_chars [ follow [ i ] . chr ] = 1 ;
 if ( ( follow [ i ] . chr == SPACE_CHAR && ! follow [ i + 1 ] . chr && follow [ i ] . len > 1 ) || follow [ i ] . chr == END_OF_LINE ) used_chars [ 0 ] = 1 ;
 }
 if ( used_chars [ SPACE_CHAR ] ) for ( pos = word_end_chars ;
 * pos ;
 pos ++ ) used_chars [ ( int ) ( uchar ) * pos ] = 1 ;
 for ( chr = 0 ;
 chr < 256 ;
 chr ++ ) {
 if ( ! used_chars [ chr ] ) set -> next [ chr ] = chr ? default_state : - 1 ;
 else {
 new_set = make_new_set ( & sets ) ;
 set = sets . set + set_nr ;
 new_set -> table_offset = set -> table_offset ;
 new_set -> found_len = set -> found_len ;
 new_set -> found_offset = set -> found_offset + 1 ;
 found_end = 0 ;
 for ( i = ( uint ) ~ 0 ;
 ( i = get_next_bit ( sets . set + used_sets , i ) ) ;
 ) {
 if ( ! follow [ i ] . chr || follow [ i ] . chr == chr || ( follow [ i ] . chr == SPACE_CHAR && ( is_word_end [ chr ] || ( ! chr && follow [ i ] . len > 1 && ! follow [ i + 1 ] . chr ) ) ) || ( follow [ i ] . chr == END_OF_LINE && ! chr ) ) {
 if ( ( ! chr || ( follow [ i ] . chr && ! follow [ i + 1 ] . chr ) ) && follow [ i ] . len > found_end ) found_end = follow [ i ] . len ;
 if ( chr && follow [ i ] . chr ) internal_set_bit ( new_set , i + 1 ) ;
 else internal_set_bit ( new_set , i ) ;
 }
 }
 if ( found_end ) {
 new_set -> found_len = 0 ;
 bits_set = 0 ;
 for ( i = ( uint ) ~ 0 ;
 ( i = get_next_bit ( new_set , i ) ) ;
 ) {
 if ( ( follow [ i ] . chr == SPACE_CHAR || follow [ i ] . chr == END_OF_LINE ) && ! chr ) bit_nr = i + 1 ;
 else bit_nr = i ;
 if ( follow [ bit_nr - 1 ] . len < found_end || ( new_set -> found_len && ( chr == 0 || ! follow [ bit_nr ] . chr ) ) ) internal_clear_bit ( new_set , i ) ;
 else {
 if ( chr == 0 || ! follow [ bit_nr ] . chr ) {
 new_set -> table_offset = follow [ bit_nr ] . table_offset ;
 if ( chr || ( follow [ i ] . chr == SPACE_CHAR || follow [ i ] . chr == END_OF_LINE ) ) new_set -> found_offset = found_end ;
 new_set -> found_len = found_end ;
 }
 bits_set ++ ;
 }
 }
 if ( bits_set == 1 ) {
 set -> next [ chr ] = find_found ( found_set , new_set -> table_offset , new_set -> found_offset ) ;
 free_last_set ( & sets ) ;
 }
 else set -> next [ chr ] = find_set ( & sets , new_set ) ;
 }
 else set -> next [ chr ] = find_set ( & sets , new_set ) ;
 }
 }
 }
 if ( ( replace = ( REPLACE * ) my_malloc ( sizeof ( REPLACE ) * ( sets . count ) + sizeof ( REPLACE_STRING ) * ( found_sets + 1 ) + sizeof ( char * ) * count + result_len , MYF ( MY_WME | MY_ZEROFILL ) ) ) ) {
 rep_str = ( REPLACE_STRING * ) ( replace + sets . count ) ;
 to_array = ( char * * ) ( rep_str + found_sets + 1 ) ;
 to_pos = ( char * ) ( to_array + count ) ;
 for ( i = 0 ;
 i < count ;
 i ++ ) {
 to_array [ i ] = to_pos ;
 to_pos = strmov ( to_pos , to [ i ] ) + 1 ;
 }
 rep_str [ 0 ] . found = 1 ;
 rep_str [ 0 ] . replace_string = 0 ;
 for ( i = 1 ;
 i <= found_sets ;
 i ++ ) {
 pos = from [ found_set [ i - 1 ] . table_offset ] ;
 rep_str [ i ] . found = ! memcmp ( pos , "\\^" , 3 ) ? 2 : 1 ;
 rep_str [ i ] . replace_string = to_array [ found_set [ i - 1 ] . table_offset ] ;
 rep_str [ i ] . to_offset = found_set [ i - 1 ] . found_offset - start_at_word ( pos ) ;
 rep_str [ i ] . from_offset = found_set [ i - 1 ] . found_offset - replace_len ( pos ) + end_of_word ( pos ) ;
 }
 for ( i = 0 ;
 i < sets . count ;
 i ++ ) {
 for ( j = 0 ;
 j < 256 ;
 j ++ ) if ( sets . set [ i ] . next [ j ] >= 0 ) replace [ i ] . next [ j ] = replace + sets . set [ i ] . next [ j ] ;
 else replace [ i ] . next [ j ] = ( REPLACE * ) ( rep_str + ( - sets . set [ i ] . next [ j ] - 1 ) ) ;
 }
 }
 my_free ( follow ) ;
 free_sets ( & sets ) ;
 my_free ( found_set ) ;
 DBUG_PRINT ( "exit" , ( "Replace table has %d states" , sets . count ) ) ;
 DBUG_RETURN ( replace ) ;
 }