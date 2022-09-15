static long long millis_from_datetime ( PyObject * datetime ) {
 struct TM timeinfo ;
 long long millis ;
 timeinfo . tm_year = PyDateTime_GET_YEAR ( datetime ) - 1900 ;
 timeinfo . tm_mon = PyDateTime_GET_MONTH ( datetime ) - 1 ;
 timeinfo . tm_mday = PyDateTime_GET_DAY ( datetime ) ;
 timeinfo . tm_hour = PyDateTime_DATE_GET_HOUR ( datetime ) ;
 timeinfo . tm_min = PyDateTime_DATE_GET_MINUTE ( datetime ) ;
 timeinfo . tm_sec = PyDateTime_DATE_GET_SECOND ( datetime ) ;
 millis = timegm64 ( & timeinfo ) * 1000 ;
 millis += PyDateTime_DATE_GET_MICROSECOND ( datetime ) / 1000 ;
 return millis ;
 }