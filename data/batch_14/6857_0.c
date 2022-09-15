void # ifdef M_DEBUG mpi_debug_resize ( MPI a , unsigned nlimbs , const char * info ) # else mpi_resize ( MPI a , unsigned nlimbs ) # endif {
 if ( nlimbs <= a -> alloced ) return ;
 # ifdef M_DEBUG if ( a -> d ) a -> d = m_debug_realloc ( a -> d , nlimbs * sizeof ( mpi_limb_t ) , info ) ;
 else a -> d = m_debug_alloc_clear ( nlimbs * sizeof ( mpi_limb_t ) , info ) ;
 # else if ( a -> d ) a -> d = xrealloc ( a -> d , nlimbs * sizeof ( mpi_limb_t ) ) ;
 else a -> d = xmalloc_clear ( nlimbs * sizeof ( mpi_limb_t ) ) ;
 # endif a -> alloced = nlimbs ;
 }