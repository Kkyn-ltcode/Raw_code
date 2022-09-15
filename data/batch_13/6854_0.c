MPI mpi_alloc_set_ui ( unsigned long u ) {
 # ifdef M_DEBUG MPI w = mpi_debug_alloc ( 1 , "alloc_set_ui" ) ;
 # else MPI w = mpi_alloc ( 1 ) ;
 # endif w -> d [ 0 ] = u ;
 w -> nlimbs = u ? 1 : 0 ;
 w -> sign = 0 ;
 return w ;
 }