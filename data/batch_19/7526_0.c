void set_property ( st_command * command , enum_prop prop , my_bool val ) {
 char * p = command -> first_argument ;
 if ( p && ! strcmp ( p , "ONCE" ) ) {
 command -> last_argument = p + 4 ;
 set_once_property ( prop , val ) ;
 return ;
 }
 property & pr = prop_list [ prop ] ;
 * pr . var = val ;
 pr . set = 0 ;
 var_set_int ( pr . env_name , ( val != pr . reverse ) ) ;
 }