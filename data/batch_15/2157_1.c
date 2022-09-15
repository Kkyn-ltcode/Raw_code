TEST ( BuildTime , DateLooksValid ) {
 # if ! defined ( DONT_EMBED_BUILD_METADATA ) char build_date [ ] = __DATE__ ;
 # else char build_date [ ] = "Sep 02 2008" ;
 # endif EXPECT_EQ ( 11u , strlen ( build_date ) ) ;
 EXPECT_EQ ( ' ' , build_date [ 3 ] ) ;
 EXPECT_EQ ( ' ' , build_date [ 6 ] ) ;
 }