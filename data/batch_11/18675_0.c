void exsltRegisterAll ( void ) {
 xsltInitGlobals ( ) ;
 exsltCommonRegister ( ) ;
 # ifdef EXSLT_CRYPTO_ENABLED exsltCryptoRegister ( ) ;
 # endif exsltMathRegister ( ) ;
 exsltSetsRegister ( ) ;
 exsltFuncRegister ( ) ;
 exsltStrRegister ( ) ;
 exsltDateRegister ( ) ;
 exsltSaxonRegister ( ) ;
 exsltDynRegister ( ) ;
 }