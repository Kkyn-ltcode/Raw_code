static struct cgroup_process_info * lxc_cgroup_process_info_getx ( const char * proc_pid_cgroup_str , struct cgroup_meta_data * meta ) {
 struct cgroup_process_info * result = NULL ;
 FILE * proc_pid_cgroup = NULL ;
 char * line = NULL ;
 size_t sz = 0 ;
 int saved_errno = 0 ;
 struct cgroup_process_info * * cptr = & result ;
 struct cgroup_process_info * entry = NULL ;
 proc_pid_cgroup = fopen_cloexec ( proc_pid_cgroup_str , "r" ) ;
 if ( ! proc_pid_cgroup ) return NULL ;
 while ( getline ( & line , & sz , proc_pid_cgroup ) != - 1 ) {
 char * colon1 ;
 char * colon2 ;
 char * endptr ;
 int hierarchy_number ;
 struct cgroup_hierarchy * h = NULL ;
 if ( ! line [ 0 ] ) continue ;
 if ( line [ strlen ( line ) - 1 ] == '\n' ) line [ strlen ( line ) - 1 ] = '\0' ;
 colon1 = strchr ( line , ':' ) ;
 if ( ! colon1 ) continue ;
 * colon1 ++ = '\0' ;
 colon2 = strchr ( colon1 , ':' ) ;
 if ( ! colon2 ) continue ;
 * colon2 ++ = '\0' ;
 endptr = NULL ;
 hierarchy_number = strtoul ( line , & endptr , 10 ) ;
 if ( ! endptr || * endptr ) continue ;
 if ( hierarchy_number > meta -> maximum_hierarchy ) {
 errno = EAGAIN ;
 goto out_error ;
 }
 h = meta -> hierarchies [ hierarchy_number ] ;
 if ( ! h ) {
 errno = EAGAIN ;
 goto out_error ;
 }
 if ( ! h -> used ) continue ;
 entry = calloc ( 1 , sizeof ( struct cgroup_process_info ) ) ;
 if ( ! entry ) goto out_error ;
 entry -> meta_ref = lxc_cgroup_get_meta ( meta ) ;
 entry -> hierarchy = h ;
 entry -> cgroup_path = strdup ( colon2 ) ;
 if ( ! entry -> cgroup_path ) goto out_error ;
 * cptr = entry ;
 cptr = & entry -> next ;
 entry = NULL ;
 }
 fclose ( proc_pid_cgroup ) ;
 free ( line ) ;
 return result ;
 out_error : saved_errno = errno ;
 if ( proc_pid_cgroup ) fclose ( proc_pid_cgroup ) ;
 lxc_cgroup_process_info_free ( result ) ;
 lxc_cgroup_process_info_free ( entry ) ;
 free ( line ) ;
 errno = saved_errno ;
 return NULL ;
 }