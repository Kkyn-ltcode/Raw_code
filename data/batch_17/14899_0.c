static void bug20023_change_user ( MYSQL * con ) {
 DIE_IF ( mysql_change_user ( con , opt_user , opt_password , opt_db ? opt_db : "test" ) ) ;
 }