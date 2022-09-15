static int dump_databases ( char * * db_names ) {
 int result = 0 ;
 char * * db ;
 DBUG_ENTER ( "dump_databases" ) ;
 for ( db = db_names ;
 * db ;
 db ++ ) {
 if ( dump_all_tables_in_db ( * db ) ) result = 1 ;
 }
 if ( ! result && seen_views ) {
 for ( db = db_names ;
 * db ;
 db ++ ) {
 if ( dump_all_views_in_db ( * db ) ) result = 1 ;
 }
 }
 DBUG_RETURN ( result ) ;
 }