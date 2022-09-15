void kadmin_getpol ( int argc , char * argv [ ] ) {
 krb5_error_code retval ;
 kadm5_policy_ent_rec policy ;
 if ( ! ( argc == 2 || ( argc == 3 && ! strcmp ( "-terse" , argv [ 1 ] ) ) ) ) {
 fprintf ( stderr , _ ( "usage: get_policy [-terse] policy\n" ) ) ;
 return ;
 }
 retval = kadm5_get_policy ( handle , argv [ argc - 1 ] , & policy ) ;
 if ( retval ) {
 com_err ( "get_policy" , retval , _ ( "while retrieving policy \"%s\"." ) , argv [ argc - 1 ] ) ;
 return ;
 }
 if ( argc == 2 ) {
 printf ( _ ( "Policy: %s\n" ) , policy . policy ) ;
 printf ( _ ( "Maximum password life: %ld\n" ) , policy . pw_max_life ) ;
 printf ( _ ( "Minimum password life: %ld\n" ) , policy . pw_min_life ) ;
 printf ( _ ( "Minimum password length: %ld\n" ) , policy . pw_min_length ) ;
 printf ( _ ( "Minimum number of password character classes: %ld\n" ) , policy . pw_min_classes ) ;
 printf ( _ ( "Number of old keys kept: %ld\n" ) , policy . pw_history_num ) ;
 printf ( _ ( "Reference count: %ld\n" ) , policy . policy_refcnt ) ;
 printf ( _ ( "Maximum password failures before lockout: %lu\n" ) , ( unsigned long ) policy . pw_max_fail ) ;
 printf ( _ ( "Password failure count reset interval: %s\n" ) , strdur ( policy . pw_failcnt_interval ) ) ;
 printf ( _ ( "Password lockout duration: %s\n" ) , strdur ( policy . pw_lockout_duration ) ) ;
 if ( policy . allowed_keysalts != NULL ) printf ( _ ( "Allowed key/salt types: %s\n" ) , policy . allowed_keysalts ) ;
 }
 else {
 printf ( "\"%s\"\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%lu\t%ld\t%ld\t%s\n" , policy . policy , policy . pw_max_life , policy . pw_min_life , policy . pw_min_length , policy . pw_min_classes , policy . pw_history_num , policy . policy_refcnt , ( unsigned long ) policy . pw_max_fail , ( long ) policy . pw_failcnt_interval , ( long ) policy . pw_lockout_duration , ( policy . allowed_keysalts == NULL ) ? "-" : policy . allowed_keysalts ) ;
 }
 kadm5_free_policy_ent ( handle , & policy ) ;
 }