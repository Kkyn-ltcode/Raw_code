void replace_strings_append ( REPLACE * rep , DYNAMIC_STRING * ds , const char * str , int len __attribute__ ( ( unused ) ) ) {
 reg1 REPLACE * rep_pos ;
 reg2 REPLACE_STRING * rep_str ;
 const char * start , * from ;
 DBUG_ENTER ( "replace_strings_append" ) ;
 start = from = str ;
 rep_pos = rep + 1 ;
 for ( ;
 ;
 ) {
 DBUG_PRINT ( "info" , ( "Looping through states" ) ) ;
 while ( ! rep_pos -> found ) rep_pos = rep_pos -> next [ ( uchar ) * from ++ ] ;
 if ( ! ( rep_str = ( ( REPLACE_STRING * ) rep_pos ) ) -> replace_string ) {
 dynstr_append_mem ( ds , start , from - start - 1 ) ;
 DBUG_PRINT ( "exit" , ( "Found no more string to replace, appended: %s" , start ) ) ;
 DBUG_VOID_RETURN ;
 }
 DBUG_PRINT ( "info" , ( "found: %d, to_offset: %u, from_offset: %d, string: %s" , rep_str -> found , rep_str -> to_offset , rep_str -> from_offset , rep_str -> replace_string ) ) ;
 dynstr_append_mem ( ds , start , ( from - rep_str -> to_offset ) - start ) ;
 dynstr_append_mem ( ds , rep_str -> replace_string , strlen ( rep_str -> replace_string ) ) ;
 if ( ! * ( from -= rep_str -> from_offset ) && rep_pos -> found != 2 ) {
 DBUG_PRINT ( "exit" , ( "Found end of from string" ) ) ;
 DBUG_VOID_RETURN ;
 }
 DBUG_ASSERT ( from <= str + len ) ;
 start = from ;
 rep_pos = rep ;
 }
 }