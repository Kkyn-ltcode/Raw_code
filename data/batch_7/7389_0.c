static void init_builtin_echo ( void ) {
 # ifdef __WIN__ size_t echo_length ;
 dirname_part ( builtin_echo , my_progname , & echo_length ) ;
 fn_format ( builtin_echo , ".\\echo.exe" , builtin_echo , "" , MYF ( MY_REPLACE_DIR ) ) ;
 if ( access ( builtin_echo , F_OK ) != 0 ) builtin_echo [ 0 ] = 0 ;
 return ;
 # else builtin_echo [ 0 ] = 0 ;
 return ;
 # endif }