static void pll_delete ( struct proclistlist * pll ) {
 free ( pll -> proclist ) ;
 free ( pll ) ;
 }