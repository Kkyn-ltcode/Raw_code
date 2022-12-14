extern int main ( int argc , char * argv [ ] ) {
 UBool sourceTOC , verbose ;
 uint32_t maxSize ;
 U_MAIN_INIT_ARGS ( argc , argv ) ;
 argc = u_parseArgs ( argc , argv , UPRV_LENGTHOF ( options ) , options ) ;
 if ( argc < 0 ) {
 fprintf ( stderr , "error in command line argument \"%s\"\n" , argv [ - argc ] ) ;
 }
 else if ( argc < 2 ) {
 argc = - 1 ;
 }
 if ( argc < 0 || options [ 0 ] . doesOccur || options [ 1 ] . doesOccur ) {
 FILE * where = argc < 0 ? stderr : stdout ;
 fprintf ( where , "%csage: %s [ -h, -?, --help ] [ -v, --verbose ] [ -c, --copyright ] [ -C, --comment comment ] [ -d, --destdir dir ] [ -n, --name filename ] [ -t, --type filetype ] [ -S, --source tocfile ] [ -e, --entrypoint name ] maxsize listfile\n" , argc < 0 ? 'u' : 'U' , * argv ) ;
 if ( options [ 0 ] . doesOccur || options [ 1 ] . doesOccur ) {
 fprintf ( where , "\n" "Read the list file (default: standard input) and create a common data\n" "file from specified files. Omit any files larger than maxsize, if maxsize > 0.\n" ) ;
 fprintf ( where , "\n" "Options:\n" "\t-h, -?, --help this usage text\n" "\t-v, --verbose verbose output\n" "\t-c, --copyright include the ICU copyright notice\n" "\t-C, --comment comment include a comment string\n" "\t-d, --destdir dir destination directory\n" ) ;
 fprintf ( where , "\t-n, --name filename output filename, without .type extension\n" "\t (default: " U_ICUDATA_NAME ")\n" "\t-t, --type filetype type of the destination file\n" "\t (default: \" dat \")\n" "\t-S, --source tocfile write a .c source file with the table of\n" "\t contents\n" "\t-e, --entrypoint name override the c entrypoint name\n" "\t (default: \"<name>_<type>\")\n" ) ;
 }
 return argc < 0 ? U_ILLEGAL_ARGUMENT_ERROR : U_ZERO_ERROR ;
 }
 sourceTOC = options [ 8 ] . doesOccur ;
 verbose = options [ 2 ] . doesOccur ;
 maxSize = ( uint32_t ) uprv_strtoul ( argv [ 1 ] , NULL , 0 ) ;
 createCommonDataFile ( options [ 4 ] . doesOccur ? options [ 4 ] . value : NULL , options [ 6 ] . doesOccur ? options [ 6 ] . value : NULL , options [ 9 ] . doesOccur ? options [ 9 ] . value : options [ 6 ] . doesOccur ? options [ 6 ] . value : NULL , options [ 7 ] . doesOccur ? options [ 7 ] . value : NULL , options [ 10 ] . doesOccur ? options [ 10 ] . value : NULL , options [ 3 ] . doesOccur ? U_COPYRIGHT_STRING : options [ 5 ] . doesOccur ? options [ 5 ] . value : NULL , argc == 2 ? NULL : argv [ 2 ] , maxSize , sourceTOC , verbose , NULL ) ;
 return 0 ;
 }