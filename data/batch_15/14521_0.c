static int put_error ( MYSQL * con ) {
 return put_info ( mysql_error ( con ) , INFO_ERROR , mysql_errno ( con ) , mysql_sqlstate ( con ) ) ;
 }