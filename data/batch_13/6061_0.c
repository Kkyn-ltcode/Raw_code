static int cgroup_recursive_task_count ( const char * cgroup_path ) {
 DIR * d ;
 struct dirent * dent_buf ;
 struct dirent * dent ;
 ssize_t name_max ;
 int n = 0 , r ;
 name_max = pathconf ( cgroup_path , _PC_NAME_MAX ) ;
 if ( name_max <= 0 ) name_max = 255 ;
 dent_buf = malloc ( offsetof ( struct dirent , d_name ) + name_max + 1 ) ;
 if ( ! dent_buf ) return - 1 ;
 d = opendir ( cgroup_path ) ;
 if ( ! d ) {
 free ( dent_buf ) ;
 return 0 ;
 }
 while ( readdir_r ( d , dent_buf , & dent ) == 0 && dent ) {
 const char * parts [ 3 ] = {
 cgroup_path , dent -> d_name , NULL }
 ;
 char * sub_path ;
 struct stat st ;
 if ( ! strcmp ( dent -> d_name , "." ) || ! strcmp ( dent -> d_name , ".." ) ) continue ;
 sub_path = lxc_string_join ( "/" , parts , false ) ;
 if ( ! sub_path ) {
 closedir ( d ) ;
 free ( dent_buf ) ;
 return - 1 ;
 }
 r = stat ( sub_path , & st ) ;
 if ( r < 0 ) {
 closedir ( d ) ;
 free ( dent_buf ) ;
 free ( sub_path ) ;
 return - 1 ;
 }
 if ( S_ISDIR ( st . st_mode ) ) {
 r = cgroup_recursive_task_count ( sub_path ) ;
 if ( r >= 0 ) n += r ;
 }
 else if ( ! strcmp ( dent -> d_name , "tasks" ) ) {
 r = count_lines ( sub_path ) ;
 if ( r >= 0 ) n += r ;
 }
 free ( sub_path ) ;
 }
 closedir ( d ) ;
 free ( dent_buf ) ;
 return n ;
 }