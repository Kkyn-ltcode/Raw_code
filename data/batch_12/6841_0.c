void mpi_set_secure ( MPI a ) {
 mpi_ptr_t ap , bp ;
 if ( ( a -> flags & 1 ) ) return ;
 a -> flags |= 1 ;
 ap = a -> d ;
 if ( ! a -> nlimbs ) {
 assert ( ! ap ) ;
 return ;
 }
 # ifdef M_DEBUG bp = mpi_debug_alloc_limb_space ( a -> nlimbs , 1 , "set_secure" ) ;
 # else bp = mpi_alloc_limb_space ( a -> nlimbs , 1 ) ;
 # endif MPN_COPY ( bp , ap , a -> nlimbs ) ;
 a -> d = bp ;
 # ifdef M_DEBUG mpi_debug_free_limb_space ( ap , "set_secure" ) ;
 # else mpi_free_limb_space ( ap ) ;
 # endif }