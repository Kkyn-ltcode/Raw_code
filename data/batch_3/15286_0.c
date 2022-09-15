static int __attribute_noinline__ link_exists2_p ( const char * dir , size_t dirlen , const char * fname , glob_t * pglob # ifndef _LIBC , int flags # endif ) {
 size_t fnamelen = strlen ( fname ) ;
 char * fullname = ( char * ) __alloca ( dirlen + 1 + fnamelen + 1 ) ;
 struct stat st ;
 # ifndef _LIBC struct_stat64 st64 ;
 # endif mempcpy ( mempcpy ( mempcpy ( fullname , dir , dirlen ) , "/" , 1 ) , fname , fnamelen + 1 ) ;
 # ifdef _LIBC return ( * pglob -> gl_stat ) ( fullname , & st ) == 0 ;
 # else return ( ( __builtin_expect ( flags & GLOB_ALTDIRFUNC , 0 ) ? ( * pglob -> gl_stat ) ( fullname , & st ) : __stat64 ( fullname , & st64 ) ) == 0 ) ;
 # endif }