static FILE * open_sql_file_for_table ( const char * table , int flags ) {
 FILE * res ;
 char filename [ FN_REFLEN ] , tmp_path [ FN_REFLEN ] ;
 convert_dirname ( tmp_path , path , NullS ) ;
 res = my_fopen ( fn_format ( filename , table , tmp_path , ".sql" , 4 ) , flags , MYF ( MY_WME ) ) ;
 return res ;
 }