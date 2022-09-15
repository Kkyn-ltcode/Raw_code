static int do_rawv6_setsockopt ( struct sock * sk , int level , int optname , char __user * optval , unsigned int optlen ) {
 struct raw6_sock * rp = raw6_sk ( sk ) ;
 int val ;
 if ( get_user ( val , ( int __user * ) optval ) ) return - EFAULT ;
 switch ( optname ) {
 case IPV6_CHECKSUM : if ( inet_sk ( sk ) -> inet_num == IPPROTO_ICMPV6 && level == IPPROTO_IPV6 ) {
 return - EINVAL ;
 }
 if ( val > 0 && ( val & 1 ) ) return ( - EINVAL ) ;
 if ( val < 0 ) {
 rp -> checksum = 0 ;
 }
 else {
 rp -> checksum = 1 ;
 rp -> offset = val ;
 }
 return 0 ;
 break ;
 default : return ( - ENOPROTOOPT ) ;
 }
 }