static void write_footer ( FILE * sql_file ) {
 if ( opt_xml ) {
 fputs ( "</mysqldump>\n" , sql_file ) ;
 check_io ( sql_file ) ;
 }
 else if ( ! opt_compact ) {
 if ( opt_tz_utc ) fprintf ( sql_file , "/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
\n" ) ;
 fprintf ( sql_file , "\n/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
\n" ) ;
 if ( ! path ) {
 fprintf ( md_result_file , "\ /*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
\n" ) ;
 if ( ! opt_no_create_info ) {
 fprintf ( md_result_file , "\ /*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
\n" ) ;
 }
 }
 if ( opt_set_charset ) fprintf ( sql_file , "/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
\n" "/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
\n" "/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
\n" ) ;
 fprintf ( sql_file , "/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
\n" ) ;
 fputs ( "\n" , sql_file ) ;
 if ( opt_dump_date ) {
 char time_str [ 20 ] ;
 get_date ( time_str , GETDATE_DATE_TIME , 0 ) ;
 print_comment ( sql_file , 0 , "-- Dump completed on %s\n" , time_str ) ;
 }
 else print_comment ( sql_file , 0 , "-- Dump completed\n" ) ;
 check_io ( sql_file ) ;
 }
 }