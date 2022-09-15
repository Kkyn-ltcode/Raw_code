void stats_config ( int item , const char * invalue ) {
 FILE * fp ;
 const char * value ;
 int len ;
 double old_drift ;
 # ifndef VMS const char temp_ext [ ] = ".TEMP" ;
 # else const char temp_ext [ ] = "-TEMP" ;
 # endif # ifdef SYS_WINNT char newvalue [ MAX_PATH ] , parameter [ MAX_PATH ] ;
 if ( ! ExpandEnvironmentStrings ( invalue , newvalue , MAX_PATH ) ) {
 switch ( item ) {
 case STATS_FREQ_FILE : strncpy ( parameter , "STATS_FREQ_FILE" , sizeof ( parameter ) ) ;
 break ;
 case STATS_LEAP_FILE : strncpy ( parameter , "STATS_LEAP_FILE" , sizeof ( parameter ) ) ;
 break ;
 case STATS_STATSDIR : strncpy ( parameter , "STATS_STATSDIR" , sizeof ( parameter ) ) ;
 break ;
 case STATS_PID_FILE : strncpy ( parameter , "STATS_PID_FILE" , sizeof ( parameter ) ) ;
 break ;
 default : strncpy ( parameter , "UNKNOWN" , sizeof ( parameter ) ) ;
 break ;
 }
 value = invalue ;
 msyslog ( LOG_ERR , "ExpandEnvironmentStrings(%s) failed: %m\n" , parameter ) ;
 }
 else {
 value = newvalue ;
 }
 # else value = invalue ;
 # endif switch ( item ) {
 case STATS_FREQ_FILE : if ( ! value || ( len = strlen ( value ) ) == 0 ) break ;
 stats_drift_file = erealloc ( stats_drift_file , len + 1 ) ;
 stats_temp_file = erealloc ( stats_temp_file , len + sizeof ( ".TEMP" ) ) ;
 memcpy ( stats_drift_file , value , ( size_t ) ( len + 1 ) ) ;
 memcpy ( stats_temp_file , value , ( size_t ) len ) ;
 memcpy ( stats_temp_file + len , temp_ext , sizeof ( temp_ext ) ) ;
 if ( ( fp = fopen ( stats_drift_file , "r" ) ) == NULL ) break ;
 if ( fscanf ( fp , "%lf" , & old_drift ) != 1 ) {
 msyslog ( LOG_ERR , "format error frequency file %s" , stats_drift_file ) ;
 fclose ( fp ) ;
 break ;
 }
 fclose ( fp ) ;
 loop_config ( LOOP_FREQ , old_drift ) ;
 prev_drift_comp = drift_comp ;
 break ;
 case STATS_STATSDIR : if ( strlen ( value ) >= sizeof ( statsdir ) ) {
 msyslog ( LOG_ERR , "statsdir too long (>%d, sigh)" , ( int ) sizeof ( statsdir ) - 1 ) ;
 }
 else {
 l_fp now ;
 int add_dir_sep ;
 int value_l = strlen ( value ) ;
 if ( value_l == 0 ) add_dir_sep = 0 ;
 else add_dir_sep = ( DIR_SEP != value [ value_l - 1 ] ) ;
 if ( add_dir_sep ) snprintf ( statsdir , sizeof ( statsdir ) , "%s%c" , value , DIR_SEP ) ;
 else snprintf ( statsdir , sizeof ( statsdir ) , "%s" , value ) ;
 get_systime ( & now ) ;
 if ( peerstats . prefix == & statsdir [ 0 ] && peerstats . fp != NULL ) {
 fclose ( peerstats . fp ) ;
 peerstats . fp = NULL ;
 filegen_setup ( & peerstats , now . l_ui ) ;
 }
 if ( loopstats . prefix == & statsdir [ 0 ] && loopstats . fp != NULL ) {
 fclose ( loopstats . fp ) ;
 loopstats . fp = NULL ;
 filegen_setup ( & loopstats , now . l_ui ) ;
 }
 if ( clockstats . prefix == & statsdir [ 0 ] && clockstats . fp != NULL ) {
 fclose ( clockstats . fp ) ;
 clockstats . fp = NULL ;
 filegen_setup ( & clockstats , now . l_ui ) ;
 }
 if ( rawstats . prefix == & statsdir [ 0 ] && rawstats . fp != NULL ) {
 fclose ( rawstats . fp ) ;
 rawstats . fp = NULL ;
 filegen_setup ( & rawstats , now . l_ui ) ;
 }
 if ( sysstats . prefix == & statsdir [ 0 ] && sysstats . fp != NULL ) {
 fclose ( sysstats . fp ) ;
 sysstats . fp = NULL ;
 filegen_setup ( & sysstats , now . l_ui ) ;
 }
 if ( protostats . prefix == & statsdir [ 0 ] && protostats . fp != NULL ) {
 fclose ( protostats . fp ) ;
 protostats . fp = NULL ;
 filegen_setup ( & protostats , now . l_ui ) ;
 }
 # ifdef AUTOKEY if ( cryptostats . prefix == & statsdir [ 0 ] && cryptostats . fp != NULL ) {
 fclose ( cryptostats . fp ) ;
 cryptostats . fp = NULL ;
 filegen_setup ( & cryptostats , now . l_ui ) ;
 }
 # endif # ifdef DEBUG_TIMING if ( timingstats . prefix == & statsdir [ 0 ] && timingstats . fp != NULL ) {
 fclose ( timingstats . fp ) ;
 timingstats . fp = NULL ;
 filegen_setup ( & timingstats , now . l_ui ) ;
 }
 # endif }
 break ;
 case STATS_PID_FILE : if ( ( fp = fopen ( value , "w" ) ) == NULL ) {
 msyslog ( LOG_ERR , "pid file %s: %m" , value ) ;
 break ;
 }
 fprintf ( fp , "%d" , ( int ) getpid ( ) ) ;
 fclose ( fp ) ;
 ;
 break ;
 case STATS_LEAP_FILE : if ( ( fp = fopen ( value , "r" ) ) == NULL ) {
 msyslog ( LOG_ERR , "leapseconds file %s: %m" , value ) ;
 break ;
 }
 if ( leap_file ( fp ) < 0 ) msyslog ( LOG_ERR , "format error leapseconds file %s" , value ) ;
 else mprintf_event ( EVNT_TAI , NULL , "%d leap %s expire %s" , leap_tai , fstostr ( leap_sec ) , fstostr ( leap_expire ) ) ;
 fclose ( fp ) ;
 break ;
 default : break ;
 }
 }