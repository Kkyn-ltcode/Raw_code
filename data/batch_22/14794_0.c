static inline guint32 gst_asf_demux_identify_guid ( const ASFGuidHash * guids , ASFGuid * guid ) {
 guint32 ret ;
 ret = gst_asf_identify_guid ( guids , guid ) ;
 GST_LOG ( "%s 0x%08x-0x%08x-0x%08x-0x%08x" , gst_asf_get_guid_nick ( guids , ret ) , guid -> v1 , guid -> v2 , guid -> v3 , guid -> v4 ) ;
 return ret ;
 }