static bool init_global_datetime_format ( timestamp_type format_type , DATE_TIME_FORMAT * format ) {
 format -> format . length = strlen ( format -> format . str ) ;
 if ( parse_date_time_format ( format_type , format ) ) {
 fprintf ( stderr , "Wrong date/time format specifier: %s\n" , format -> format . str ) ;
 return true ;
 }
 return false ;
 }