static int com_ego ( String * buffer , char * line ) {
 int result ;
 bool oldvertical = vertical ;
 vertical = 1 ;
 result = com_go ( buffer , line ) ;
 vertical = oldvertical ;
 return result ;
 }