static int dissect_SYSTEM_TIME_ptr ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 char * str ;
 offset = dissect_SYSTEM_TIME ( tvb , offset , pinfo , tree , di , drep , NULL , FALSE , & str ) ;
 dcv -> private_data = str ;
 return offset ;
 }