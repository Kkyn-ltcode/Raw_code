static int rawv6_geticmpfilter ( struct sock * sk , int level , int optname , char __user * optval , int __user * optlen ) {
 int len ;
 switch ( optname ) {
 case ICMPV6_FILTER : if ( get_user ( len , optlen ) ) return - EFAULT ;
 if ( len < 0 ) return - EINVAL ;
 if ( len > sizeof ( struct icmp6_filter ) ) len = sizeof ( struct icmp6_filter ) ;
 if ( put_user ( len , optlen ) ) return - EFAULT ;
 if ( copy_to_user ( optval , & raw6_sk ( sk ) -> filter , len ) ) return - EFAULT ;
 return 0 ;
 default : return - ENOPROTOOPT ;
 }
 return 0 ;
 }