int main ( int argc , char * * argv ) {
 using std : : string ;
 if ( argc != 2 ) {
 fprintf ( stderr , "One argument, the input filename, must be provided.\n" ) ;
 return 1 ;
 }
 string filename ( argv [ 1 ] ) ;
 string outfilename = filename . substr ( 0 , filename . find_last_of ( "." ) ) + ".woff2" ;
 fprintf ( stdout , "Processing %s => %s\n" , filename . c_str ( ) , outfilename . c_str ( ) ) ;
 string input = woff2 : : GetFileContent ( filename ) ;
 const uint8_t * input_data = reinterpret_cast < const uint8_t * > ( input . data ( ) ) ;
 size_t output_size = woff2 : : MaxWOFF2CompressedSize ( input_data , input . size ( ) ) ;
 string output ( output_size , 0 ) ;
 uint8_t * output_data = reinterpret_cast < uint8_t * > ( & output [ 0 ] ) ;
 if ( ! woff2 : : ConvertTTFToWOFF2 ( input_data , input . size ( ) , output_data , & output_size ) ) {
 fprintf ( stderr , "Compression failed.\n" ) ;
 return 1 ;
 }
 output . resize ( output_size ) ;
 woff2 : : SetFileContents ( outfilename , output ) ;
 return 0 ;
 }