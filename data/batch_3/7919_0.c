static void switch_cs_variables ( FILE * sql_file , const char * delimiter , const char * character_set_client , const char * character_set_results , const char * collation_connection ) {
 fprintf ( sql_file , "/*!50003 SET @saved_cs_client = @@character_set_client */ %s\n" "/*!50003 SET @saved_cs_results = @@character_set_results */ %s\n" "/*!50003 SET @saved_col_connection = @@collation_connection */ %s\n" "/*!50003 SET character_set_client = %s */ %s\n" "/*!50003 SET character_set_results = %s */ %s\n" "/*!50003 SET collation_connection = %s */ %s\n" , ( const char * ) delimiter , ( const char * ) delimiter , ( const char * ) delimiter , ( const char * ) character_set_client , ( const char * ) delimiter , ( const char * ) character_set_results , ( const char * ) delimiter , ( const char * ) collation_connection , ( const char * ) delimiter ) ;
 }