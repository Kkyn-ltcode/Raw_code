static void restore_cs_variables ( FILE * sql_file , const char * delimiter ) {
 fprintf ( sql_file , "/*!50003 SET character_set_client = @saved_cs_client */ %s\n" "/*!50003 SET character_set_results = @saved_cs_results */ %s\n" "/*!50003 SET collation_connection = @saved_col_connection */ %s\n" , ( const char * ) delimiter , ( const char * ) delimiter , ( const char * ) delimiter ) ;
 }