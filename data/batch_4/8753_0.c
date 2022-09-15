static int selinux_file_ioctl ( struct file * file , unsigned int cmd , unsigned long arg ) {
 const struct cred * cred = current_cred ( ) ;
 int error = 0 ;
 switch ( cmd ) {
 case FIONREAD : case FIBMAP : case FIGETBSZ : case FS_IOC_GETFLAGS : case FS_IOC_GETVERSION : error = file_has_perm ( cred , file , FILE__GETATTR ) ;
 break ;
 case FS_IOC_SETFLAGS : case FS_IOC_SETVERSION : error = file_has_perm ( cred , file , FILE__SETATTR ) ;
 break ;
 case FIONBIO : case FIOASYNC : error = file_has_perm ( cred , file , 0 ) ;
 break ;
 case KDSKBENT : case KDSKBSENT : error = cred_has_capability ( cred , CAP_SYS_TTY_CONFIG , SECURITY_CAP_AUDIT , true ) ;
 break ;
 default : error = ioctl_has_perm ( cred , file , FILE__IOCTL , ( u16 ) cmd ) ;
 }
 return error ;
 }