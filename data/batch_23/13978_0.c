static void test_lc_time_sz ( ) {
 DBUG_ENTER ( "test_lc_time_sz" ) ;
 for ( MY_LOCALE * * loc = my_locales ;
 * loc ;
 loc ++ ) {
 uint max_month_len = 0 ;
 uint max_day_len = 0 ;
 for ( const char * * month = ( * loc ) -> month_names -> type_names ;
 * month ;
 month ++ ) {
 set_if_bigger ( max_month_len , my_numchars_mb ( & my_charset_utf8_general_ci , * month , * month + strlen ( * month ) ) ) ;
 }
 for ( const char * * day = ( * loc ) -> day_names -> type_names ;
 * day ;
 day ++ ) {
 set_if_bigger ( max_day_len , my_numchars_mb ( & my_charset_utf8_general_ci , * day , * day + strlen ( * day ) ) ) ;
 }
 if ( ( * loc ) -> max_month_name_length != max_month_len || ( * loc ) -> max_day_name_length != max_day_len ) {
 DBUG_PRINT ( "Wrong max day name(or month name) length for locale:" , ( "%s" , ( * loc ) -> name ) ) ;
 DBUG_ASSERT ( 0 ) ;
 }
 }
 DBUG_VOID_RETURN ;
 }