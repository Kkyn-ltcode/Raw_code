int rds_recvmsg ( struct socket * sock , struct msghdr * msg , size_t size , int msg_flags ) {
 struct sock * sk = sock -> sk ;
 struct rds_sock * rs = rds_sk_to_rs ( sk ) ;
 long timeo ;
 int ret = 0 , nonblock = msg_flags & MSG_DONTWAIT ;
 DECLARE_SOCKADDR ( struct sockaddr_in * , sin , msg -> msg_name ) ;
 struct rds_incoming * inc = NULL ;
 timeo = sock_rcvtimeo ( sk , nonblock ) ;
 rdsdebug ( "size %zu flags 0x%x timeo %ld\n" , size , msg_flags , timeo ) ;
 if ( msg_flags & MSG_OOB ) goto out ;
 while ( 1 ) {
 struct iov_iter save ;
 if ( ! list_empty ( & rs -> rs_notify_queue ) ) {
 ret = rds_notify_queue_get ( rs , msg ) ;
 break ;
 }
 if ( rs -> rs_cong_notify ) {
 ret = rds_notify_cong ( rs , msg ) ;
 break ;
 }
 if ( ! rds_next_incoming ( rs , & inc ) ) {
 if ( nonblock ) {
 ret = - EAGAIN ;
 break ;
 }
 timeo = wait_event_interruptible_timeout ( * sk_sleep ( sk ) , ( ! list_empty ( & rs -> rs_notify_queue ) || rs -> rs_cong_notify || rds_next_incoming ( rs , & inc ) ) , timeo ) ;
 rdsdebug ( "recvmsg woke inc %p timeo %ld\n" , inc , timeo ) ;
 if ( timeo > 0 || timeo == MAX_SCHEDULE_TIMEOUT ) continue ;
 ret = timeo ;
 if ( ret == 0 ) ret = - ETIMEDOUT ;
 break ;
 }
 rdsdebug ( "copying inc %p from %pI4:%u to user\n" , inc , & inc -> i_conn -> c_faddr , ntohs ( inc -> i_hdr . h_sport ) ) ;
 save = msg -> msg_iter ;
 ret = inc -> i_conn -> c_trans -> inc_copy_to_user ( inc , & msg -> msg_iter ) ;
 if ( ret < 0 ) break ;
 if ( ! rds_still_queued ( rs , inc , ! ( msg_flags & MSG_PEEK ) ) ) {
 rds_inc_put ( inc ) ;
 inc = NULL ;
 rds_stats_inc ( s_recv_deliver_raced ) ;
 msg -> msg_iter = save ;
 continue ;
 }
 if ( ret < be32_to_cpu ( inc -> i_hdr . h_len ) ) {
 if ( msg_flags & MSG_TRUNC ) ret = be32_to_cpu ( inc -> i_hdr . h_len ) ;
 msg -> msg_flags |= MSG_TRUNC ;
 }
 if ( rds_cmsg_recv ( inc , msg , rs ) ) {
 ret = - EFAULT ;
 goto out ;
 }
 rds_stats_inc ( s_recv_delivered ) ;
 if ( sin ) {
 sin -> sin_family = AF_INET ;
 sin -> sin_port = inc -> i_hdr . h_sport ;
 sin -> sin_addr . s_addr = inc -> i_saddr ;
 memset ( sin -> sin_zero , 0 , sizeof ( sin -> sin_zero ) ) ;
 msg -> msg_namelen = sizeof ( * sin ) ;
 }
 break ;
 }
 if ( inc ) rds_inc_put ( inc ) ;
 out : return ret ;
 }