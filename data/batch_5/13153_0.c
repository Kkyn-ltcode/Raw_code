static bool restricted_shell ( const char * shell ) {
 char * line ;
 setusershell ( ) ;
 while ( ( line = getusershell ( ) ) != NULL ) {
 if ( * line != '#' && ! strcmp ( line , shell ) ) {
 endusershell ( ) ;
 return false ;
 }
 }
 endusershell ( ) ;
 return true ;
 }