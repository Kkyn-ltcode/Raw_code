static char * get_data ( char * buf , int len ) {
 char * data ;
 int pos = 0 ;
 while ( pos < len && buf [ pos ] != '{
' ) pos ++ ;
 if ( pos == len ) {
 return NULL ;
 }
 data = buf + pos - 1 ;
 return data ;
 }