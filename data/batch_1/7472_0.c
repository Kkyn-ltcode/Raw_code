int my_system ( DYNAMIC_STRING * ds_cmd ) {
 # if defined __WIN__ && defined USE_CYGWIN str_to_file ( tmp_sh_name , ds_cmd -> str , ds_cmd -> length ) ;
 return system ( tmp_sh_cmd ) ;
 # else return system ( ds_cmd -> str ) ;
 # endif }