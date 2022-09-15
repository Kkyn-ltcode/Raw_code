FILE * my_popen ( DYNAMIC_STRING * ds_cmd , const char * mode ) {
 # if defined __WIN__ && defined USE_CYGWIN str_to_file ( tmp_sh_name , ds_cmd -> str , ds_cmd -> length ) ;
 return popen ( tmp_sh_cmd , mode ) ;
 # else return popen ( ds_cmd -> str , mode ) ;
 # endif }