int change_to_newfile ( const char * filename , const char * old_ext , const char * new_ext , myf MyFlags ) {
 char old_filename [ FN_REFLEN ] , new_filename [ FN_REFLEN ] ;
 ( void ) fn_format ( old_filename , filename , "" , old_ext , 2 + 4 + 32 ) ;
 return my_redel ( old_filename , fn_format ( new_filename , old_filename , "" , new_ext , 2 + 4 ) , MYF ( MY_WME | MY_LINK_WARNING | MyFlags ) ) ;
 }