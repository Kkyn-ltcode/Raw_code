static void switch_sql_mode ( FILE * sql_file , const char * delimiter , const char * sql_mode ) {
 fprintf ( sql_file , "/*!50003 SET @saved_sql_mode = @@sql_mode */ %s\n" "/*!50003 SET sql_mode = '%s' */ %s\n" , ( const char * ) delimiter , ( const char * ) sql_mode , ( const char * ) delimiter ) ;
 }