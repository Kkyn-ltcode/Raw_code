static void cluster_all_databases ( bool verbose , const char * maintenance_db , const char * host , const char * port , const char * username , enum trivalue prompt_password , const char * progname , bool echo , bool quiet ) {
 PGconn * conn ;
 PGresult * result ;
 PQExpBufferData connstr ;
 int i ;
 conn = connectMaintenanceDatabase ( maintenance_db , host , port , username , prompt_password , progname ) ;
 result = executeQuery ( conn , "SELECT datname FROM pg_database WHERE datallowconn ORDER BY 1;
" , progname , echo ) ;
 PQfinish ( conn ) ;
 initPQExpBuffer ( & connstr ) ;
 for ( i = 0 ;
 i < PQntuples ( result ) ;
 i ++ ) {
 char * dbname = PQgetvalue ( result , i , 0 ) ;
 if ( ! quiet ) {
 printf ( _ ( "%s: clustering database \"%s\"\n" ) , progname , dbname ) ;
 fflush ( stdout ) ;
 }
 resetPQExpBuffer ( & connstr ) ;
 appendPQExpBuffer ( & connstr , "dbname=" ) ;
 appendConnStrVal ( & connstr , dbname ) ;
 cluster_one_database ( connstr . data , verbose , NULL , host , port , username , prompt_password , progname , echo ) ;
 }
 termPQExpBuffer ( & connstr ) ;
 PQclear ( result ) ;
 }