static int dissect_h225_FeatureDescriptor ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 852 "./asn1/h225/h225.cnf" void * priv_data = actx -> private_data ;
 actx -> private_data = gef_ctx_alloc ( NULL , "FeatureDescriptor" ) ;
 offset = dissect_h225_GenericData ( tvb , offset , actx , tree , hf_index ) ;
 # line 855 "./asn1/h225/h225.cnf" actx -> private_data = priv_data ;
 return offset ;
 }