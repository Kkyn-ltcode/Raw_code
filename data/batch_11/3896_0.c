static int dissect_h245_H221NonStandardID ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 966 "../../asn1/h245/h245.cnf" t35CountryCode = 0 ;
 t35Extension = 0 ;
 manufacturerCode = 0 ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h245_H221NonStandardID , H221NonStandardID_sequence ) ;
 # line 970 "../../asn1/h245/h245.cnf" h221NonStandard = ( ( t35CountryCode * 256 ) + t35Extension ) * 65536 + manufacturerCode ;
 proto_tree_add_uint ( tree , hf_h245Manufacturer , tvb , ( offset >> 3 ) - 4 , 4 , h221NonStandard ) ;
 return offset ;
 }