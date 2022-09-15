static void set_ports ( ) {
 char * env ;
 if ( ! mysqld_port && ! opt_disable_networking ) {
 mysqld_port = MYSQL_PORT ;
 # if MYSQL_PORT_DEFAULT == 0 struct servent * serv_ptr ;
 if ( ( serv_ptr = getservbyname ( "mysql" , "tcp" ) ) ) mysqld_port = ntohs ( ( u_short ) serv_ptr -> s_port ) ;
 # endif if ( ( env = getenv ( "MYSQL_TCP_PORT" ) ) ) mysqld_port = ( uint ) atoi ( env ) ;
 }
 if ( ! mysqld_unix_port ) {
 # ifdef __WIN__ mysqld_unix_port = ( char * ) MYSQL_NAMEDPIPE ;
 # else mysqld_unix_port = ( char * ) MYSQL_UNIX_ADDR ;
 # endif if ( ( env = getenv ( "MYSQL_UNIX_PORT" ) ) ) mysqld_unix_port = env ;
 }
 }