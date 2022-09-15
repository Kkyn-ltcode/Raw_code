void parseDiagnosticInfo ( proto_tree * tree , tvbuff_t * tvb , packet_info * pinfo , gint * pOffset , const char * szFieldName ) {
 static const int * diag_mask [ ] = {
 & hf_opcua_diag_mask_symbolicflag , & hf_opcua_diag_mask_namespaceflag , & hf_opcua_diag_mask_localizedtextflag , & hf_opcua_diag_mask_localeflag , & hf_opcua_diag_mask_additionalinfoflag , & hf_opcua_diag_mask_innerstatuscodeflag , & hf_opcua_diag_mask_innerdiaginfoflag , NULL }
 ;
 gint iOffset = * pOffset ;
 guint8 EncodingMask ;
 proto_tree * subtree ;
 proto_item * ti ;
 subtree = proto_tree_add_subtree_format ( tree , tvb , * pOffset , - 1 , ett_opcua_diagnosticinfo , & ti , "%s: DiagnosticInfo" , szFieldName ) ;
 EncodingMask = tvb_get_guint8 ( tvb , iOffset ) ;
 proto_tree_add_bitmask ( subtree , tvb , iOffset , hf_opcua_diag_mask , ett_opcua_diagnosticinfo_encodingmask , diag_mask , ENC_LITTLE_ENDIAN ) ;
 iOffset ++ ;
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_SYMBOLICID_FLAG ) {
 parseInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_symbolicid ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_NAMESPACE_FLAG ) {
 parseInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_namespace ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_LOCALIZEDTEXT_FLAG ) {
 parseInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_localizedtext ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_LOCALE_FLAG ) {
 parseInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_locale ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_ADDITIONALINFO_FLAG ) {
 parseString ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_additionalinfo ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_INNERSTATUSCODE_FLAG ) {
 parseStatusCode ( subtree , tvb , pinfo , & iOffset , hf_opcua_diag_innerstatuscode ) ;
 }
 if ( EncodingMask & DIAGNOSTICINFO_ENCODINGMASK_INNERDIAGNOSTICINFO_FLAG ) {
 parseDiagnosticInfo ( subtree , tvb , pinfo , & iOffset , "Inner DiagnosticInfo" ) ;
 }
 proto_item_set_end ( ti , tvb , iOffset ) ;
 * pOffset = iOffset ;
 }