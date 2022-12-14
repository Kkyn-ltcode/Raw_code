int main ( int argc , char * * argv ) {
 using std : : string ;
 if ( argc != 2 ) {
 fprintf ( stderr , "One argument, the input filename, must be provided.\n" ) ;
 return 1 ;
 }
 string filename ( argv [ 1 ] ) ;
 string outfilename = filename . substr ( 0 , filename . find_last_of ( "." ) ) + ".ttf" ;
 fprintf ( stdout , "Processing %s => %s\n" , filename . c_str ( ) , outfilename . c_str ( ) ) ;
 string input = woff2 : : GetFileContent ( filename ) ;
 size_t decompressed_size = woff2 : : ComputeWOFF2FinalSize ( reinterpret_cast < const uint8_t * > ( input . data ( ) ) , input . size ( ) ) ;
 string output ( decompressed_size , 0 ) ;
 const bool ok = woff2 : : ConvertWOFF2ToTTF ( reinterpret_cast < uint8_t * > ( & output [ 0 ] ) , decompressed_size , reinterpret_cast < const uint8_t * > ( input . data ( ) ) , input . size ( ) ) ;
 if ( ! ok ) {
 fprintf ( stderr , "Decompression failed\n" ) ;
 return 1 ;
 }
 woff2 : : SetFileContents ( outfilename , output ) ;
 return 0 ;
 }