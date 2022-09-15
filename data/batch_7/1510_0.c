static int rawv6_probe_proto_opt ( struct flowi * fl , struct msghdr * msg ) {
 struct iovec * iov ;
 u8 __user * type = NULL ;
 u8 __user * code = NULL ;
 u8 len = 0 ;
 int probed = 0 ;
 int i ;
 if ( ! msg -> msg_iov ) return 0 ;
 for ( i = 0 ;
 i < msg -> msg_iovlen ;
 i ++ ) {
 iov = & msg -> msg_iov [ i ] ;
 if ( ! iov ) continue ;
 switch ( fl -> proto ) {
 case IPPROTO_ICMPV6 : if ( iov -> iov_base && iov -> iov_len < 1 ) break ;
 if ( ! type ) {
 type = iov -> iov_base ;
 if ( iov -> iov_len > 1 ) code = type + 1 ;
 }
 else if ( ! code ) code = iov -> iov_base ;
 if ( type && code ) {
 if ( get_user ( fl -> fl_icmp_type , type ) || get_user ( fl -> fl_icmp_code , code ) ) return - EFAULT ;
 probed = 1 ;
 }
 break ;
 case IPPROTO_MH : if ( iov -> iov_base && iov -> iov_len < 1 ) break ;
 if ( iov -> iov_len > 2 - len ) {
 u8 __user * p = iov -> iov_base ;
 if ( get_user ( fl -> fl_mh_type , & p [ 2 - len ] ) ) return - EFAULT ;
 probed = 1 ;
 }
 else len += iov -> iov_len ;
 break ;
 default : probed = 1 ;
 break ;
 }
 if ( probed ) break ;
 }
 return 0 ;
 }