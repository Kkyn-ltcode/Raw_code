TEST ( IdlCompiler , Basics ) {
 MyType1 a ;
 a . x = 5 ;
 a . y = std : : string ( "foo" ) ;
 std : : unique_ptr < base : : DictionaryValue > serialized = a . ToValue ( ) ;
 MyType1 b ;
 EXPECT_TRUE ( MyType1 : : Populate ( * serialized . get ( ) , & b ) ) ;
 EXPECT_EQ ( a . x , b . x ) ;
 EXPECT_EQ ( a . y , b . y ) ;
 base : : ListValue list ;
 list . AppendInteger ( 5 ) ;
 std : : unique_ptr < Function2 : : Params > f2_params = Function2 : : Params : : Create ( list ) ;
 EXPECT_EQ ( 5 , f2_params -> x ) ;
 list . Clear ( ) ;
 std : : unique_ptr < base : : DictionaryValue > tmp ( new base : : DictionaryValue ( ) ) ;
 tmp -> SetInteger ( "x" , 17 ) ;
 tmp -> SetString ( "y" , "hello" ) ;
 tmp -> SetString ( "z" , "zstring" ) ;
 tmp -> SetString ( "a" , "astring" ) ;
 tmp -> SetString ( "b" , "bstring" ) ;
 tmp -> SetString ( "c" , "cstring" ) ;
 list . Append ( std : : move ( tmp ) ) ;
 std : : unique_ptr < Function3 : : Params > f3_params = Function3 : : Params : : Create ( list ) ;
 EXPECT_EQ ( 17 , f3_params -> arg . x ) ;
 EXPECT_EQ ( "hello" , f3_params -> arg . y ) ;
 std : : unique_ptr < base : : ListValue > f4_results = Function4 : : Results : : Create ( ) ;
 base : : ListValue expected ;
 EXPECT_TRUE ( f4_results -> Equals ( & expected ) ) ;
 std : : unique_ptr < base : : ListValue > f5_results ( Function5 : : Results : : Create ( 13 ) ) ;
 base : : Value * f5_result_int = NULL ;
 ASSERT_TRUE ( f5_results -> Get ( 0 , & f5_result_int ) ) ;
 EXPECT_TRUE ( f5_result_int -> is_int ( ) ) ;
 std : : unique_ptr < base : : ListValue > f6_results ( Function6 : : Results : : Create ( a ) ) ;
 base : : Value * f6_result_dict = NULL ;
 ASSERT_TRUE ( f6_results -> Get ( 0 , & f6_result_dict ) ) ;
 MyType1 c ;
 EXPECT_TRUE ( MyType1 : : Populate ( * f6_result_dict , & c ) ) ;
 EXPECT_EQ ( a . x , c . x ) ;
 EXPECT_EQ ( a . y , c . y ) ;
 }