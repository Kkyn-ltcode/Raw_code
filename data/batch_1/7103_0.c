PGconn * GetConnection ( void ) {
 PGconn * tmpconn ;
 int argcount = 7 ;
 int i ;
 const char * * keywords ;
 const char * * values ;
 const char * tmpparam ;
 bool need_password ;
 PQconninfoOption * conn_opts = NULL ;
 PQconninfoOption * conn_opt ;
 char * err_msg = NULL ;
 Assert ( dbname == NULL || connection_string == NULL ) ;
 i = 0 ;
 if ( connection_string ) {
 conn_opts = PQconninfoParse ( connection_string , & err_msg ) ;
 if ( conn_opts == NULL ) {
 fprintf ( stderr , "%s: %s" , progname , err_msg ) ;
 exit ( 1 ) ;
 }
 for ( conn_opt = conn_opts ;
 conn_opt -> keyword != NULL ;
 conn_opt ++ ) {
 if ( conn_opt -> val != NULL && conn_opt -> val [ 0 ] != '\0' && strcmp ( conn_opt -> keyword , "dbname" ) != 0 ) argcount ++ ;
 }
 keywords = pg_malloc0 ( ( argcount + 1 ) * sizeof ( * keywords ) ) ;
 values = pg_malloc0 ( ( argcount + 1 ) * sizeof ( * values ) ) ;
 for ( conn_opt = conn_opts ;
 conn_opt -> keyword != NULL ;
 conn_opt ++ ) {
 if ( conn_opt -> val != NULL && conn_opt -> val [ 0 ] != '\0' && strcmp ( conn_opt -> keyword , "dbname" ) != 0 ) {
 keywords [ i ] = conn_opt -> keyword ;
 values [ i ] = conn_opt -> val ;
 i ++ ;
 }
 }
 }
 else {
 keywords = pg_malloc0 ( ( argcount + 1 ) * sizeof ( * keywords ) ) ;
 values = pg_malloc0 ( ( argcount + 1 ) * sizeof ( * values ) ) ;
 }
 keywords [ i ] = "dbname" ;
 values [ i ] = dbname == NULL ? "replication" : dbname ;
 i ++ ;
 keywords [ i ] = "replication" ;
 values [ i ] = dbname == NULL ? "true" : "database" ;
 i ++ ;
 keywords [ i ] = "fallback_application_name" ;
 values [ i ] = progname ;
 i ++ ;
 if ( dbhost ) {
 keywords [ i ] = "host" ;
 values [ i ] = dbhost ;
 i ++ ;
 }
 if ( dbuser ) {
 keywords [ i ] = "user" ;
 values [ i ] = dbuser ;
 i ++ ;
 }
 if ( dbport ) {
 keywords [ i ] = "port" ;
 values [ i ] = dbport ;
 i ++ ;
 }
 need_password = ( dbgetpassword == 1 && dbpassword == NULL ) ;
 do {
 if ( need_password ) {
 if ( dbpassword ) free ( dbpassword ) ;
 dbpassword = simple_prompt ( _ ( "Password: " ) , 100 , false ) ;
 need_password = false ;
 }
 if ( dbpassword ) {
 keywords [ i ] = "password" ;
 values [ i ] = dbpassword ;
 }
 else {
 keywords [ i ] = NULL ;
 values [ i ] = NULL ;
 }
 tmpconn = PQconnectdbParams ( keywords , values , true ) ;
 if ( ! tmpconn ) {
 fprintf ( stderr , _ ( "%s: could not connect to server\n" ) , progname ) ;
 exit ( 1 ) ;
 }
 if ( PQstatus ( tmpconn ) == CONNECTION_BAD && PQconnectionNeedsPassword ( tmpconn ) && dbgetpassword != - 1 ) {
 PQfinish ( tmpconn ) ;
 need_password = true ;
 }
 }
 while ( need_password ) ;
 if ( PQstatus ( tmpconn ) != CONNECTION_OK ) {
 fprintf ( stderr , _ ( "%s: could not connect to server: %s" ) , progname , PQerrorMessage ( tmpconn ) ) ;
 PQfinish ( tmpconn ) ;
 free ( values ) ;
 free ( keywords ) ;
 if ( conn_opts ) PQconninfoFree ( conn_opts ) ;
 return NULL ;
 }
 free ( values ) ;
 free ( keywords ) ;
 if ( conn_opts ) PQconninfoFree ( conn_opts ) ;
 tmpparam = PQparameterStatus ( tmpconn , "integer_datetimes" ) ;
 if ( ! tmpparam ) {
 fprintf ( stderr , _ ( "%s: could not determine server setting for integer_datetimes\n" ) , progname ) ;
 PQfinish ( tmpconn ) ;
 exit ( 1 ) ;
 }
 # ifdef HAVE_INT64_TIMESTAMP if ( strcmp ( tmpparam , "on" ) != 0 ) # else if ( strcmp ( tmpparam , "off" ) != 0 ) # endif {
 fprintf ( stderr , _ ( "%s: integer_datetimes compile flag does not match server\n" ) , progname ) ;
 PQfinish ( tmpconn ) ;
 exit ( 1 ) ;
 }
 return tmpconn ;
 }