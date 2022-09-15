int evdns_init ( void ) {
 int res = 0 ;
 # ifdef WIN32 res = evdns_config_windows_nameservers ( ) ;
 # else res = evdns_resolv_conf_parse ( DNS_OPTIONS_ALL , "/etc/resolv.conf" ) ;
 # endif return ( res ) ;
 }