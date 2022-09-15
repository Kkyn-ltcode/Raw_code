static inline int sk_mc_loop ( struct sock * sk ) {
 if ( ! sk ) return 1 ;
 switch ( sk -> sk_family ) {
 case AF_INET : return inet_sk ( sk ) -> mc_loop ;
 # if defined ( CONFIG_IPV6 ) || defined ( CONFIG_IPV6_MODULE ) case AF_INET6 : return inet6_sk ( sk ) -> mc_loop ;
 # endif }
 WARN_ON ( 1 ) ;
 return 1 ;
 }