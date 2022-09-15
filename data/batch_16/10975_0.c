static int dissect_h225_H221NonStandard ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 802 "./asn1/h225/h225.cnf" t35CountryCode = 0 ;
 t35Extension = 0 ;
 manufacturerCode = 0 ;
 offset = dissect_per_sequence ( tvb , offset , actx , tree , hf_index , ett_h225_H221NonStandard , H221NonStandard_sequence ) ;
 # line 806 "./asn1/h225/h225.cnf" h221NonStandard = ( ( t35CountryCode * 256 ) + t35Extension ) * 65536 + manufacturerCode ;
 proto_tree_add_uint ( tree , hf_h221Manufacturer , tvb , ( offset >> 3 ) - 4 , 4 , h221NonStandard ) ;
 return offset ;
 }