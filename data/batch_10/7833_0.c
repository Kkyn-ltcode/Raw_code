static void switch_time_zone ( FILE * sql_file , const char * delimiter , const char * time_zone ) {
 fprintf ( sql_file , "/*!50003 SET @saved_time_zone = @@time_zone */ %s\n" "/*!50003 SET time_zone = '%s' */ %s\n" , ( const char * ) delimiter , ( const char * ) time_zone , ( const char * ) delimiter ) ;
 }