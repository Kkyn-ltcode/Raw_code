int EC_GROUP_get_basis_type ( const EC_GROUP * group ) {
 int i = 0 ;
 if ( EC_METHOD_get_field_type ( EC_GROUP_method_of ( group ) ) != NID_X9_62_characteristic_two_field ) return 0 ;
 while ( group -> poly [ i ] != 0 ) i ++ ;
 if ( i == 4 ) return NID_X9_62_ppBasis ;
 else if ( i == 2 ) return NID_X9_62_tpBasis ;
 else return 0 ;
 }