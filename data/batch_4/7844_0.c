static void restore_time_zone ( FILE * sql_file , const char * delimiter ) {
 fprintf ( sql_file , "/*!50003 SET time_zone = @saved_time_zone */ %s\n" , ( const char * ) delimiter ) ;
 }