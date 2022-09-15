static int create_or_remove_cgroup ( bool do_remove , struct cgroup_mount_point * mp , const char * path , int recurse ) {
 int r , saved_errno = 0 ;
 char * buf = cgroup_to_absolute_path ( mp , path , NULL ) ;
 if ( ! buf ) return - 1 ;
 if ( do_remove ) {
 if ( recurse ) r = cgroup_rmdir ( buf ) ;
 else r = rmdir ( buf ) ;
 }
 else r = mkdir ( buf , 0777 ) ;
 saved_errno = errno ;
 free ( buf ) ;
 errno = saved_errno ;
 return r ;
 }