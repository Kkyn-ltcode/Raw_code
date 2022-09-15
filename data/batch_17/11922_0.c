int # ifdef DEBUG _TSAssert ( const char * text , const char * file , int line ) {
 _ink_assert ( text , file , line ) ;
 return 0 ;
 }
 # else _TSAssert ( const char * , const char * , int ) {
 return 0 ;
 }