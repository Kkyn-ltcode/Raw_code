static bool cgroup_devices_has_allow_or_deny ( struct cgfs_data * d , char * v , bool for_allow ) {
 char * path ;
 FILE * devices_list ;
 char * line = NULL ;
 size_t sz = 0 ;
 bool ret = ! for_allow ;
 const char * parts [ 3 ] = {
 NULL , "devices.list" , NULL }
 ;
 if ( ! for_allow && strcmp ( v , "a" ) != 0 && strcmp ( v , "a *:* rwm" ) != 0 ) return false ;
 parts [ 0 ] = ( const char * ) lxc_cgroup_get_hierarchy_abs_path_data ( "devices" , d ) ;
 if ( ! parts [ 0 ] ) return false ;
 path = lxc_string_join ( "/" , parts , false ) ;
 if ( ! path ) {
 free ( ( void * ) parts [ 0 ] ) ;
 return false ;
 }
 devices_list = fopen_cloexec ( path , "r" ) ;
 if ( ! devices_list ) {
 free ( path ) ;
 return false ;
 }
 while ( getline ( & line , & sz , devices_list ) != - 1 ) {
 size_t len = strlen ( line ) ;
 if ( len > 0 && line [ len - 1 ] == '\n' ) line [ len - 1 ] = '\0' ;
 if ( strcmp ( line , "a *:* rwm" ) == 0 ) {
 ret = for_allow ;
 goto out ;
 }
 else if ( for_allow && strcmp ( line , v ) == 0 ) {
 ret = true ;
 goto out ;
 }
 }
 out : fclose ( devices_list ) ;
 free ( line ) ;
 free ( path ) ;
 return ret ;
 }