bool cephx_decode_ticket ( CephContext * cct , KeyStore * keys , uint32_t service_id , CephXTicketBlob & ticket_blob , CephXServiceTicketInfo & ticket_info ) {
 uint64_t secret_id = ticket_blob . secret_id ;
 CryptoKey service_secret ;
 if ( ! ticket_blob . blob . length ( ) ) {
 return false ;
 }
 if ( secret_id == ( uint64_t ) - 1 ) {
 if ( ! keys -> get_secret ( cct -> _conf -> name , service_secret ) ) {
 ldout ( cct , 0 ) << "ceph_decode_ticket could not get general service secret for service_id=" << ceph_entity_type_name ( service_id ) << " secret_id=" << secret_id << dendl ;
 return false ;
 }
 }
 else {
 if ( ! keys -> get_service_secret ( service_id , secret_id , service_secret ) ) {
 ldout ( cct , 0 ) << "ceph_decode_ticket could not get service secret for service_id=" << ceph_entity_type_name ( service_id ) << " secret_id=" << secret_id << dendl ;
 return false ;
 }
 }
 std : : string error ;
 decode_decrypt_enc_bl ( cct , ticket_info , service_secret , ticket_blob . blob , error ) ;
 if ( ! error . empty ( ) ) {
 ldout ( cct , 0 ) << "ceph_decode_ticket could not decrypt ticket info. error:" << error << dendl ;
 return false ;
 }
 return true ;
 }