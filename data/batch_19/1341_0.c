static int slirp_smb ( SlirpState * s , const char * exported_dir , struct in_addr vserver_addr ) {
 char smb_conf [ 128 ] ;
 char smb_cmdline [ 128 ] ;
 struct passwd * passwd ;
 FILE * f ;
 passwd = getpwuid ( geteuid ( ) ) ;
 if ( ! passwd ) {
 error_report ( "failed to retrieve user name" ) ;
 return - 1 ;
 }
 if ( access ( CONFIG_SMBD_COMMAND , F_OK ) ) {
 error_report ( "could not find '%s', please install it" , CONFIG_SMBD_COMMAND ) ;
 return - 1 ;
 }
 if ( access ( exported_dir , R_OK | X_OK ) ) {
 error_report ( "error accessing shared directory '%s': %s" , exported_dir , strerror ( errno ) ) ;
 return - 1 ;
 }
 snprintf ( s -> smb_dir , sizeof ( s -> smb_dir ) , "/tmp/qemu-smb.XXXXXX" ) ;
 if ( ! mkdtemp ( s -> smb_dir ) ) {
 error_report ( "could not create samba server dir '%s'" , s -> smb_dir ) ;
 s -> smb_dir [ 0 ] = 0 ;
 return - 1 ;
 }
 snprintf ( smb_conf , sizeof ( smb_conf ) , "%s/%s" , s -> smb_dir , "smb.conf" ) ;
 f = fopen ( smb_conf , "w" ) ;
 if ( ! f ) {
 slirp_smb_cleanup ( s ) ;
 error_report ( "could not create samba server configuration file '%s'" , smb_conf ) ;
 return - 1 ;
 }
 fprintf ( f , "[global]\n" "private dir=%s\n" "interfaces=127.0.0.1\n" "bind interfaces only=yes\n" "pid directory=%s\n" "lock directory=%s\n" "state directory=%s\n" "cache directory=%s\n" "ncalrpc dir=%scalrpc\n" "log file=%s/log.smbd\n" "smb passwd file=%s/smbpasswd\n" "security = user\n" "map to guest = Bad User\n" "load printers = no\n" "printing = bsd\n" "disable spoolss = yes\n" "usershare max shares = 0\n" "[qemu]\n" "path=%s\n" "read only=no\n" "guest ok=yes\n" "force user=%s\n" , s -> smb_dir , s -> smb_dir , s -> smb_dir , s -> smb_dir , s -> smb_dir , s -> smb_dir , s -> smb_dir , s -> smb_dir , exported_dir , passwd -> pw_name ) ;
 fclose ( f ) ;
 snprintf ( smb_cmdline , sizeof ( smb_cmdline ) , "%s -l %s -s %s" , CONFIG_SMBD_COMMAND , s -> smb_dir , smb_conf ) ;
 if ( slirp_add_exec ( s -> slirp , 0 , smb_cmdline , & vserver_addr , 139 ) < 0 || slirp_add_exec ( s -> slirp , 0 , smb_cmdline , & vserver_addr , 445 ) < 0 ) {
 slirp_smb_cleanup ( s ) ;
 error_report ( "conflicting/invalid smbserver address" ) ;
 return - 1 ;
 }
 return 0 ;
 }