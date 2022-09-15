int multi_reg_replace ( struct st_replace_regex * r , char * val ) {
 uint i ;
 char * in_buf , * out_buf ;
 int * buf_len_p ;
 in_buf = val ;
 out_buf = r -> even_buf ;
 buf_len_p = & r -> even_buf_len ;
 r -> buf = 0 ;
 for ( i = 0 ;
 i < r -> regex_arr . elements ;
 i ++ ) {
 struct st_regex re ;
 char * save_out_buf = out_buf ;
 get_dynamic ( & r -> regex_arr , ( uchar * ) & re , i ) ;
 if ( ! reg_replace ( & out_buf , buf_len_p , re . pattern , re . replace , in_buf , re . icase ) ) {
 if ( save_out_buf != out_buf ) {
 if ( save_out_buf == r -> even_buf ) r -> even_buf = out_buf ;
 else r -> odd_buf = out_buf ;
 }
 r -> buf = out_buf ;
 if ( in_buf == val ) in_buf = r -> odd_buf ;
 swap_variables ( char * , in_buf , out_buf ) ;
 buf_len_p = ( out_buf == r -> even_buf ) ? & r -> even_buf_len : & r -> odd_buf_len ;
 }
 }
 return ( r -> buf == 0 ) ;
 }