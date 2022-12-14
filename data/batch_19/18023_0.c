int ShellBrowserMain ( const content : : MainFunctionParams & parameters , const scoped_ptr < content : : BrowserMainRunner > & main_runner ) {
 int exit_code = main_runner -> Initialize ( parameters ) ;
 DCHECK_LT ( exit_code , 0 ) << "BrowserMainRunner::Initialize failed in ShellBrowserMain" ;
 if ( exit_code >= 0 ) return exit_code ;
 # if ! defined ( OS_ANDROID ) exit_code = main_runner -> Run ( ) ;
 main_runner -> Shutdown ( ) ;
 # endif return exit_code ;
 }