static inline my_bool general_log_or_slow_log_tables ( const char * db , const char * table ) {
 return ( ! my_strcasecmp ( charset_info , db , "mysql" ) ) && ( ! my_strcasecmp ( charset_info , table , "general_log" ) || ! my_strcasecmp ( charset_info , table , "slow_log" ) ) ;
 }