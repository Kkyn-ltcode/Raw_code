static int dissect_h225_SEQUENCE_OF_FeatureDescriptor ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 offset = dissect_per_sequence_of ( tvb , offset , actx , tree , hf_index , ett_h225_SEQUENCE_OF_FeatureDescriptor , SEQUENCE_OF_FeatureDescriptor_sequence_of ) ;
 return offset ;
 }