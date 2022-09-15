static char * adb_send_and_receive ( socket_handle_t sock , const char * adb_service , char * buffer , int buffer_length , gssize * data_length ) {
 gssize used_buffer_length ;
 gssize length ;
 gssize result ;
 char status [ 4 ] ;
 char tmp_buffer ;
 size_t adb_service_length ;
 adb_service_length = strlen ( adb_service ) ;
 result = send ( sock , adb_service , ( int ) adb_service_length , 0 ) ;
 if ( result != ( gssize ) adb_service_length ) {
 errmsg_print ( "ERROR: Error while sending <%s> to ADB daemon" , adb_service ) ;
 if ( data_length ) * data_length = 0 ;
 return NULL ;
 }
 used_buffer_length = 0 ;
 while ( used_buffer_length < 8 ) {
 result = recv ( sock , buffer + used_buffer_length , ( int ) ( buffer_length - used_buffer_length ) , 0 ) ;
 if ( result <= 0 ) {
 errmsg_print ( "ERROR: Broken socket connection while fetching reply status for <%s>" , adb_service ) ;
 return NULL ;
 }
 used_buffer_length += result ;
 }
 memcpy ( status , buffer , 4 ) ;
 tmp_buffer = buffer [ 8 ] ;
 buffer [ 8 ] = '\0' ;
 length = ( gssize ) g_ascii_strtoll ( buffer + 4 , NULL , 16 ) ;
 buffer [ 8 ] = tmp_buffer ;
 while ( used_buffer_length < length + 8 ) {
 result = recv ( sock , buffer + used_buffer_length , ( int ) ( buffer_length - used_buffer_length ) , 0 ) ;
 if ( result <= 0 ) {
 errmsg_print ( "ERROR: Broken socket connection while reading reply for <%s>" , adb_service ) ;
 return NULL ;
 }
 used_buffer_length += result ;
 }
 if ( data_length ) * data_length = used_buffer_length - 8 ;
 if ( memcmp ( status , "OKAY" , 4 ) ) {
 errmsg_print ( "ERROR: Error while receiving by ADB for <%s>" , adb_service ) ;
 if ( data_length ) * data_length = 0 ;
 return NULL ;
 }
 return buffer + 8 ;
 }