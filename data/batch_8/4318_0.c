bool cephx_build_service_ticket_blob ( CephContext * cct , CephXSessionAuthInfo & info , CephXTicketBlob & blob ) {
 CephXServiceTicketInfo ticket_info ;
 ticket_info . session_key = info . session_key ;
 ticket_info . ticket = info . ticket ;
 ticket_info . ticket . caps = info . ticket . caps ;
 ldout ( cct , 10 ) << "build_service_ticket service " << ceph_entity_type_name ( info . service_id ) << " secret_id " << info . secret_id << " ticket_info.ticket.name=" << ticket_info . ticket . name . to_str ( ) << dendl ;
 blob . secret_id = info . secret_id ;
 std : : string error ;
 if ( ! info . service_secret . get_secret ( ) . length ( ) ) error = "invalid key" ;
 else encode_encrypt_enc_bl ( cct , ticket_info , info . service_secret , blob . blob , error ) ;
 if ( ! error . empty ( ) ) {
 ldout ( cct , - 1 ) << "cephx_build_service_ticket_blob failed with error " << error << dendl ;
 return false ;
 }
 return true ;
 }