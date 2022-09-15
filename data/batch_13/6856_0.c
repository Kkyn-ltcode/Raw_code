MPI # ifdef M_DEBUG mpi_debug_alloc_secure ( unsigned nlimbs , const char * info ) # else mpi_alloc_secure ( unsigned nlimbs ) # endif {
 MPI a ;
 if ( DBG_MEMORY ) log_debug ( "mpi_alloc_secure(%u)\n" , nlimbs * BITS_PER_MPI_LIMB ) ;
 # ifdef M_DEBUG a = m_debug_alloc ( sizeof * a , info ) ;
 a -> d = nlimbs ? mpi_debug_alloc_limb_space ( nlimbs , 1 , info ) : NULL ;
 # else a = xmalloc ( sizeof * a ) ;
 a -> d = nlimbs ? mpi_alloc_limb_space ( nlimbs , 1 ) : NULL ;
 # endif a -> alloced = nlimbs ;
 a -> flags = 1 ;
 a -> nlimbs = 0 ;
 a -> sign = 0 ;
 a -> nbits = 0 ;
 return a ;
 }