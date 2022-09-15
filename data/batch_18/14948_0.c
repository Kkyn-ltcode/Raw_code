static void test_client_character_set ( ) {
 MY_CHARSET_INFO cs ;
 char * csname = ( char * ) "utf8" ;
 char * csdefault = ( char * ) mysql_character_set_name ( mysql ) ;
 int rc ;
 myheader ( "test_client_character_set" ) ;
 rc = mysql_set_character_set ( mysql , csname ) ;
 DIE_UNLESS ( rc == 0 ) ;
 mysql_get_character_set_info ( mysql , & cs ) ;
 DIE_UNLESS ( ! strcmp ( cs . csname , "utf8" ) ) ;
 DIE_UNLESS ( ! strcmp ( cs . name , "utf8_general_ci" ) ) ;
 rc = mysql_set_character_set ( mysql , csdefault ) ;
 myquery ( rc ) ;
 }