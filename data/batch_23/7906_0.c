uchar * get_table_key ( const char * entry , size_t * length , my_bool not_used __attribute__ ( ( unused ) ) ) {
 * length = strlen ( entry ) ;
 return ( uchar * ) entry ;
 }