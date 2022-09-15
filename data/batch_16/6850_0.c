MPI mpi_set_opaque ( MPI a , void * p , unsigned int len ) {
 if ( ! a ) {
 # ifdef M_DEBUG a = mpi_debug_alloc ( 0 , "alloc_opaque" ) ;
 # else a = mpi_alloc ( 0 ) ;
 # endif }
 if ( a -> flags & 4 ) xfree ( a -> d ) ;
 else {
 # ifdef M_DEBUG mpi_debug_free_limb_space ( a -> d , "alloc_opaque" ) ;
 # else mpi_free_limb_space ( a -> d ) ;
 # endif }
 a -> d = p ;
 a -> alloced = 0 ;
 a -> nlimbs = 0 ;
 a -> nbits = len ;
 a -> flags = 4 ;
 return a ;
 }