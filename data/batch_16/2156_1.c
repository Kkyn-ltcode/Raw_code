TEST ( BuildTime , TimeLooksValid ) {
 # if defined ( DONT_EMBED_BUILD_METADATA ) char build_time [ ] = "08:00:00" ;
 # else char build_time [ ] = __TIME__ ;
 # endif EXPECT_EQ ( 8u , strlen ( build_time ) ) ;
 EXPECT_EQ ( ':' , build_time [ 2 ] ) ;
 EXPECT_EQ ( ':' , build_time [ 5 ] ) ;
 }