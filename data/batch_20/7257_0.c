void create_script_for_cluster_analyze ( char * * analyze_script_file_name ) {
 FILE * script = NULL ;
 PQExpBufferData user_specification ;
 prep_status ( "Creating script to analyze new cluster" ) ;
 initPQExpBuffer ( & user_specification ) ;
 if ( os_info . user_specified ) {
 appendPQExpBufferStr ( & user_specification , "-U " ) ;
 appendShellString ( & user_specification , os_info . user ) ;
 appendPQExpBufferChar ( & user_specification , ' ' ) ;
 }
 * analyze_script_file_name = psprintf ( "%sanalyze_new_cluster.%s" , SCRIPT_PREFIX , SCRIPT_EXT ) ;
 if ( ( script = fopen_priv ( * analyze_script_file_name , "w" ) ) == NULL ) pg_fatal ( "Could not open file \"%s\": %s\n" , * analyze_script_file_name , getErrorText ( ) ) ;
 # ifndef WIN32 fprintf ( script , "#!/bin/sh\n\n" ) ;
 # else fprintf ( script , "@echo off\n" ) ;
 # endif fprintf ( script , "echo %sThis script will generate minimal optimizer statistics rapidly%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %sso your system is usable, and then gather statistics twice more%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %swith increasing accuracy. When it is done, your system will%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %shave the default level of optimizer statistics.%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo%s\n\n" , ECHO_BLANK ) ;
 fprintf ( script , "echo %sIf you have used ALTER TABLE to modify the statistics target for%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %sany tables, you might want to remove them and restore them after%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %srunning this script because they will delay fast statistics generation.%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo%s\n\n" , ECHO_BLANK ) ;
 fprintf ( script , "echo %sIf you would like default statistics as quickly as possible, cancel%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %sthis script and run:%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fprintf ( script , "echo %s \"%s/vacuumdb\" %s--all %s%s\n" , ECHO_QUOTE , new_cluster . bindir , user_specification . data , ( GET_MAJOR_VERSION ( old_cluster . major_version ) >= 804 ) ? "--analyze-only" : "--analyze" , ECHO_QUOTE ) ;
 fprintf ( script , "echo%s\n\n" , ECHO_BLANK ) ;
 fprintf ( script , "\"%s/vacuumdb\" %s--all --analyze-in-stages\n" , new_cluster . bindir , user_specification . data ) ;
 if ( GET_MAJOR_VERSION ( old_cluster . major_version ) < 804 ) fprintf ( script , "\"%s/vacuumdb\" %s--all\n" , new_cluster . bindir , user_specification . data ) ;
 fprintf ( script , "echo%s\n\n" , ECHO_BLANK ) ;
 fprintf ( script , "echo %sDone%s\n" , ECHO_QUOTE , ECHO_QUOTE ) ;
 fclose ( script ) ;
 # ifndef WIN32 if ( chmod ( * analyze_script_file_name , S_IRWXU ) != 0 ) pg_fatal ( "Could not add execute permission to file \"%s\": %s\n" , * analyze_script_file_name , getErrorText ( ) ) ;
 # endif termPQExpBuffer ( & user_specification ) ;
 check_ok ( ) ;
 }