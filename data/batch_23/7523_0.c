void set_once_property ( enum_prop prop , my_bool val ) {
 property & pr = prop_list [ prop ] ;
 pr . set = 1 ;
 pr . old = * pr . var ;
 * pr . var = val ;
 var_set_int ( pr . env_name , ( val != pr . reverse ) ) ;
 once_property = TRUE ;
 }