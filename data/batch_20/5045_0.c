static double convert_timevalue_to_scalar ( Datum value , Oid typid ) {
 switch ( typid ) {
 case TIMESTAMPOID : return DatumGetTimestamp ( value ) ;
 case TIMESTAMPTZOID : return DatumGetTimestampTz ( value ) ;
 case ABSTIMEOID : return DatumGetTimestamp ( DirectFunctionCall1 ( abstime_timestamp , value ) ) ;
 case DATEOID : return date2timestamp_no_overflow ( DatumGetDateADT ( value ) ) ;
 case INTERVALOID : {
 Interval * interval = DatumGetIntervalP ( value ) ;
 # ifdef HAVE_INT64_TIMESTAMP return interval -> time + interval -> day * ( double ) USECS_PER_DAY + interval -> month * ( ( DAYS_PER_YEAR / ( double ) MONTHS_PER_YEAR ) * USECS_PER_DAY ) ;
 # else return interval -> time + interval -> day * SECS_PER_DAY + interval -> month * ( ( DAYS_PER_YEAR / ( double ) MONTHS_PER_YEAR ) * ( double ) SECS_PER_DAY ) ;
 # endif }
 case RELTIMEOID : # ifdef HAVE_INT64_TIMESTAMP return ( DatumGetRelativeTime ( value ) * 1000000.0 ) ;
 # else return DatumGetRelativeTime ( value ) ;
 # endif case TINTERVALOID : {
 TimeInterval tinterval = DatumGetTimeInterval ( value ) ;
 # ifdef HAVE_INT64_TIMESTAMP if ( tinterval -> status != 0 ) return ( ( tinterval -> data [ 1 ] - tinterval -> data [ 0 ] ) * 1000000.0 ) ;
 # else if ( tinterval -> status != 0 ) return tinterval -> data [ 1 ] - tinterval -> data [ 0 ] ;
 # endif return 0 ;
 }
 case TIMEOID : return DatumGetTimeADT ( value ) ;
 case TIMETZOID : {
 TimeTzADT * timetz = DatumGetTimeTzADTP ( value ) ;
 # ifdef HAVE_INT64_TIMESTAMP return ( double ) ( timetz -> time + ( timetz -> zone * 1000000.0 ) ) ;
 # else return ( double ) ( timetz -> time + timetz -> zone ) ;
 # endif }
 }
 elog ( ERROR , "unsupported type: %u" , typid ) ;
 return 0 ;
 }