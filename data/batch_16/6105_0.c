static void * cgfs_init ( const char * name ) {
 struct cgfs_data * d ;
 d = malloc ( sizeof ( * d ) ) ;
 if ( ! d ) return NULL ;
 memset ( d , 0 , sizeof ( * d ) ) ;
 d -> name = strdup ( name ) ;
 if ( ! d -> name ) goto err1 ;
 d -> cgroup_pattern = lxc_global_config_value ( "lxc.cgroup.pattern" ) ;
 d -> meta = lxc_cgroup_load_meta ( ) ;
 if ( ! d -> meta ) {
 ERROR ( "cgroupfs failed to detect cgroup metadata" ) ;
 goto err2 ;
 }
 return d ;
 err2 : free ( d -> name ) ;
 err1 : free ( d ) ;
 return NULL ;
 }