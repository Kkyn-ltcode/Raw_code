static void config_access ( config_tree * ptree ) {
 static int warned_signd ;
 attr_val * my_opt ;
 restrict_node * my_node ;
 int_node * curr_flag ;
 sockaddr_u addr ;
 sockaddr_u mask ;
 struct addrinfo hints ;
 struct addrinfo * ai_list ;
 struct addrinfo * pai ;
 int rc ;
 int restrict_default ;
 u_short flags ;
 u_short mflags ;
 int range_err ;
 const char * signd_warning = # ifdef HAVE_NTP_SIGND "MS-SNTP signd operations currently block ntpd degrading service to all clients." ;
 # else "mssntp restrict bit ignored, this ntpd was configured without --enable-ntp-signd." ;
 # endif my_opt = HEAD_PFIFO ( ptree -> mru_opts ) ;
 for ( ;
 my_opt != NULL ;
 my_opt = my_opt -> link ) {
 range_err = FALSE ;
 switch ( my_opt -> attr ) {
 case T_Incalloc : if ( 0 <= my_opt -> value . i ) mru_incalloc = my_opt -> value . u ;
 else range_err = TRUE ;
 break ;
 case T_Incmem : if ( 0 <= my_opt -> value . i ) mru_incalloc = ( my_opt -> value . u * 1024 ) / sizeof ( mon_entry ) ;
 else range_err = TRUE ;
 break ;
 case T_Initalloc : if ( 0 <= my_opt -> value . i ) mru_initalloc = my_opt -> value . u ;
 else range_err = TRUE ;
 break ;
 case T_Initmem : if ( 0 <= my_opt -> value . i ) mru_initalloc = ( my_opt -> value . u * 1024 ) / sizeof ( mon_entry ) ;
 else range_err = TRUE ;
 break ;
 case T_Mindepth : if ( 0 <= my_opt -> value . i ) mru_mindepth = my_opt -> value . u ;
 else range_err = TRUE ;
 break ;
 case T_Maxage : mru_maxage = my_opt -> value . i ;
 break ;
 case T_Maxdepth : if ( 0 <= my_opt -> value . i ) mru_maxdepth = my_opt -> value . u ;
 else mru_maxdepth = UINT_MAX ;
 break ;
 case T_Maxmem : if ( 0 <= my_opt -> value . i ) mru_maxdepth = my_opt -> value . u * 1024 / sizeof ( mon_entry ) ;
 else mru_maxdepth = UINT_MAX ;
 break ;
 default : msyslog ( LOG_ERR , "Unknown mru option %s (%d)" , keyword ( my_opt -> attr ) , my_opt -> attr ) ;
 exit ( 1 ) ;
 }
 if ( range_err ) msyslog ( LOG_ERR , "mru %s %d out of range, ignored." , keyword ( my_opt -> attr ) , my_opt -> value . i ) ;
 }
 my_opt = HEAD_PFIFO ( ptree -> discard_opts ) ;
 for ( ;
 my_opt != NULL ;
 my_opt = my_opt -> link ) {
 switch ( my_opt -> attr ) {
 case T_Average : if ( 0 <= my_opt -> value . i && my_opt -> value . i <= UCHAR_MAX ) ntp_minpoll = ( u_char ) my_opt -> value . u ;
 else msyslog ( LOG_ERR , "discard average %d out of range, ignored." , my_opt -> value . i ) ;
 break ;
 case T_Minimum : ntp_minpkt = my_opt -> value . i ;
 break ;
 case T_Monitor : mon_age = my_opt -> value . i ;
 break ;
 default : msyslog ( LOG_ERR , "Unknown discard option %s (%d)" , keyword ( my_opt -> attr ) , my_opt -> attr ) ;
 exit ( 1 ) ;
 }
 }
 my_node = HEAD_PFIFO ( ptree -> restrict_opts ) ;
 for ( ;
 my_node != NULL ;
 my_node = my_node -> link ) {
 flags = 0 ;
 mflags = 0 ;
 curr_flag = HEAD_PFIFO ( my_node -> flags ) ;
 for ( ;
 curr_flag != NULL ;
 curr_flag = curr_flag -> link ) {
 switch ( curr_flag -> i ) {
 default : NTP_INSIST ( 0 ) ;
 break ;
 case T_Ntpport : mflags |= RESM_NTPONLY ;
 break ;
 case T_Source : mflags |= RESM_SOURCE ;
 break ;
 case T_Flake : flags |= RES_FLAKE ;
 break ;
 case T_Ignore : flags |= RES_IGNORE ;
 break ;
 case T_Kod : flags |= RES_KOD ;
 break ;
 case T_Mssntp : flags |= RES_MSSNTP ;
 break ;
 case T_Limited : flags |= RES_LIMITED ;
 break ;
 case T_Lowpriotrap : flags |= RES_LPTRAP ;
 break ;
 case T_Nomodify : flags |= RES_NOMODIFY ;
 break ;
 case T_Nopeer : flags |= RES_NOPEER ;
 break ;
 case T_Noquery : flags |= RES_NOQUERY ;
 break ;
 case T_Noserve : flags |= RES_DONTSERVE ;
 break ;
 case T_Notrap : flags |= RES_NOTRAP ;
 break ;
 case T_Notrust : flags |= RES_DONTTRUST ;
 break ;
 case T_Version : flags |= RES_VERSION ;
 break ;
 }
 }
 if ( ( RES_MSSNTP & flags ) && ! warned_signd ) {
 warned_signd = 1 ;
 fprintf ( stderr , "%s\n" , signd_warning ) ;
 msyslog ( LOG_WARNING , signd_warning ) ;
 }
 ZERO_SOCK ( & addr ) ;
 ai_list = NULL ;
 pai = NULL ;
 restrict_default = 0 ;
 if ( NULL == my_node -> addr ) {
 ZERO_SOCK ( & mask ) ;
 if ( ! ( RESM_SOURCE & mflags ) ) {
 restrict_default = 1 ;
 }
 else {
 DPRINTF ( 1 , ( "restrict source template mflags %x flags %x\n" , mflags , flags ) ) ;
 hack_restrict ( RESTRICT_FLAGS , NULL , NULL , mflags , flags , 0 ) ;
 continue ;
 }
 }
 else {
 AF ( & addr ) = ( u_short ) my_node -> addr -> type ;
 if ( getnetnum ( my_node -> addr -> address , & addr , 1 , t_UNK ) != 1 ) {
 ai_list = NULL ;
 memset ( & hints , 0 , sizeof ( hints ) ) ;
 hints . ai_protocol = IPPROTO_UDP ;
 hints . ai_socktype = SOCK_DGRAM ;
 hints . ai_family = my_node -> addr -> type ;
 rc = getaddrinfo ( my_node -> addr -> address , "ntp" , & hints , & ai_list ) ;
 if ( rc ) {
 msyslog ( LOG_ERR , "restrict: ignoring line %d, address/host '%s' unusable." , my_node -> line_no , my_node -> addr -> address ) ;
 continue ;
 }
 NTP_INSIST ( ai_list != NULL ) ;
 pai = ai_list ;
 NTP_INSIST ( pai -> ai_addr != NULL ) ;
 NTP_INSIST ( sizeof ( addr ) >= pai -> ai_addrlen ) ;
 memcpy ( & addr , pai -> ai_addr , pai -> ai_addrlen ) ;
 NTP_INSIST ( AF_INET == AF ( & addr ) || AF_INET6 == AF ( & addr ) ) ;
 }
 SET_HOSTMASK ( & mask , AF ( & addr ) ) ;
 if ( my_node -> mask ) {
 ZERO_SOCK ( & mask ) ;
 AF ( & mask ) = my_node -> mask -> type ;
 if ( getnetnum ( my_node -> mask -> address , & mask , 1 , t_MSK ) != 1 ) {
 msyslog ( LOG_ERR , "restrict: ignoring line %d, mask '%s' unusable." , my_node -> line_no , my_node -> mask -> address ) ;
 continue ;
 }
 }
 }
 if ( restrict_default ) {
 AF ( & addr ) = AF_INET ;
 AF ( & mask ) = AF_INET ;
 hack_restrict ( RESTRICT_FLAGS , & addr , & mask , mflags , flags , 0 ) ;
 AF ( & addr ) = AF_INET6 ;
 AF ( & mask ) = AF_INET6 ;
 }
 do {
 hack_restrict ( RESTRICT_FLAGS , & addr , & mask , mflags , flags , 0 ) ;
 if ( pai != NULL && NULL != ( pai = pai -> ai_next ) ) {
 NTP_INSIST ( pai -> ai_addr != NULL ) ;
 NTP_INSIST ( sizeof ( addr ) >= pai -> ai_addrlen ) ;
 ZERO_SOCK ( & addr ) ;
 memcpy ( & addr , pai -> ai_addr , pai -> ai_addrlen ) ;
 NTP_INSIST ( AF_INET == AF ( & addr ) || AF_INET6 == AF ( & addr ) ) ;
 SET_HOSTMASK ( & mask , AF ( & addr ) ) ;
 }
 }
 while ( pai != NULL ) ;
 if ( ai_list != NULL ) freeaddrinfo ( ai_list ) ;
 }
 }