TEST ( IdlCompiler , OptionalArguments ) {
 base : : ListValue list ;
 std : : unique_ptr < Function7 : : Params > f7_params = Function7 : : Params : : Create ( list ) ;
 EXPECT_EQ ( NULL , f7_params -> arg . get ( ) ) ;
 list . AppendInteger ( 7 ) ;
 f7_params = Function7 : : Params : : Create ( list ) ;
 EXPECT_EQ ( 7 , * ( f7_params -> arg ) ) ;
 list . Clear ( ) ;
 list . AppendInteger ( 8 ) ;
 std : : unique_ptr < Function8 : : Params > f8_params = Function8 : : Params : : Create ( list ) ;
 EXPECT_EQ ( 8 , f8_params -> arg1 ) ;
 EXPECT_EQ ( NULL , f8_params -> arg2 . get ( ) ) ;
 list . AppendString ( "foo" ) ;
 f8_params = Function8 : : Params : : Create ( list ) ;
 EXPECT_EQ ( 8 , f8_params -> arg1 ) ;
 EXPECT_EQ ( "foo" , * ( f8_params -> arg2 ) ) ;
 list . Clear ( ) ;
 std : : unique_ptr < Function9 : : Params > f9_params = Function9 : : Params : : Create ( list ) ;
 EXPECT_EQ ( NULL , f9_params -> arg . get ( ) ) ;
 list . Clear ( ) ;
 std : : unique_ptr < base : : DictionaryValue > tmp ( new base : : DictionaryValue ( ) ) ;
 tmp -> SetInteger ( "x" , 17 ) ;
 tmp -> SetString ( "y" , "hello" ) ;
 tmp -> SetString ( "z" , "zstring" ) ;
 tmp -> SetString ( "a" , "astring" ) ;
 tmp -> SetString ( "b" , "bstring" ) ;
 tmp -> SetString ( "c" , "cstring" ) ;
 list . Append ( std : : move ( tmp ) ) ;
 f9_params = Function9 : : Params : : Create ( list ) ;
 ASSERT_TRUE ( f9_params -> arg . get ( ) != NULL ) ;
 MyType1 * t1 = f9_params -> arg . get ( ) ;
 EXPECT_EQ ( 17 , t1 -> x ) ;
 EXPECT_EQ ( "hello" , t1 -> y ) ;
 }