void lxc_cgroup_process_info_free_and_remove ( struct cgroup_process_info * info ) {
 struct cgroup_process_info * next ;
 char * * pp ;
 if ( ! info ) return ;
 next = info -> next ;
 {
 struct cgroup_mount_point * mp = info -> designated_mount_point ;
 if ( ! mp ) mp = lxc_cgroup_find_mount_point ( info -> hierarchy , info -> cgroup_path , true ) ;
 if ( mp ) ( void ) remove_cgroup ( mp , info -> cgroup_path , true ) ;
 }
 for ( pp = info -> created_paths ;
 pp && * pp ;
 pp ++ ) ;
 for ( ( void ) ( pp && -- pp ) ;
 info -> created_paths && pp >= info -> created_paths ;
 -- pp ) {
 free ( * pp ) ;
 }
 free ( info -> created_paths ) ;
 lxc_cgroup_put_meta ( info -> meta_ref ) ;
 free ( info -> cgroup_path ) ;
 free ( info -> cgroup_path_sub ) ;
 free ( info ) ;
 lxc_cgroup_process_info_free_and_remove ( next ) ;
 }