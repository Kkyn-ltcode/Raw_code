static VALUE cState_partial_generate ( VALUE self , VALUE obj ) {
 FBuffer * buffer = cState_prepare_buffer ( self ) ;
 GET_STATE ( self ) ;
 generate_json ( buffer , self , state , obj ) ;
 return fbuffer_to_s ( buffer ) ;
 }