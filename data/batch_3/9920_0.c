static inline int rsvp_class_to_filter_num ( int classnum ) {
 switch ( classnum ) {
 case RSVP_CLASS_SESSION : case RSVP_CLASS_HOP : case RSVP_CLASS_INTEGRITY : case RSVP_CLASS_TIME_VALUES : case RSVP_CLASS_ERROR : case RSVP_CLASS_SCOPE : case RSVP_CLASS_STYLE : case RSVP_CLASS_FLOWSPEC : case RSVP_CLASS_FILTER_SPEC : case RSVP_CLASS_SENDER_TEMPLATE : case RSVP_CLASS_SENDER_TSPEC : case RSVP_CLASS_ADSPEC : case RSVP_CLASS_POLICY : case RSVP_CLASS_CONFIRM : case RSVP_CLASS_LABEL : case RSVP_CLASS_LABEL_REQUEST : case RSVP_CLASS_HELLO : case RSVP_CLASS_EXPLICIT_ROUTE : case RSVP_CLASS_RECORD_ROUTE : case RSVP_CLASS_MESSAGE_ID : case RSVP_CLASS_MESSAGE_ID_ACK : case RSVP_CLASS_MESSAGE_ID_LIST : return classnum + RSVPF_OBJECT ;
 break ;
 case RSVP_CLASS_RECOVERY_LABEL : case RSVP_CLASS_UPSTREAM_LABEL : case RSVP_CLASS_LABEL_SET : case RSVP_CLASS_PROTECTION : return RSVPF_RECOVERY_LABEL + ( classnum - RSVP_CLASS_RECOVERY_LABEL ) ;
 case RSVP_CLASS_SUGGESTED_LABEL : case RSVP_CLASS_ACCEPTABLE_LABEL_SET : case RSVP_CLASS_RESTART_CAP : return RSVPF_SUGGESTED_LABEL + ( classnum - RSVP_CLASS_SUGGESTED_LABEL ) ;
 case RSVP_CLASS_LINK_CAP : return RSVPF_LINK_CAP ;
 case RSVP_CLASS_DIFFSERV : return RSVPF_DIFFSERV ;
 case RSVP_CLASS_CLASSTYPE : return RSVPF_DSTE ;
 case RSVP_CLASS_NOTIFY_REQUEST : return RSVPF_NOTIFY_REQUEST ;
 case RSVP_CLASS_ADMIN_STATUS : return RSVPF_ADMIN_STATUS ;
 case RSVP_CLASS_LSP_ATTRIBUTES : return RSVPF_LSP_ATTRIBUTES ;
 case RSVP_CLASS_ASSOCIATION : return RSVPF_ASSOCIATION ;
 case RSVP_CLASS_CALL_ATTRIBUTES : return RSVPF_CALL_ATTRIBUTES ;
 case RSVP_CLASS_SESSION_ATTRIBUTE : return RSVPF_SESSION_ATTRIBUTE ;
 case RSVP_CLASS_GENERALIZED_UNI : return RSVPF_GENERALIZED_UNI ;
 case RSVP_CLASS_CALL_ID : return RSVPF_CALL_ID ;
 case RSVP_CLASS_3GPP2_OBJECT : return RSVPF_3GPP2_OBJECT ;
 case RSVP_CLASS_DCLASS : return RSVPF_DCLASS ;
 case RSVP_CLASS_LSP_TUNNEL_IF_ID : return RSVPF_LSP_TUNNEL_IF_ID ;
 case RSVP_CLASS_EXCLUDE_ROUTE : return RSVPF_EXCLUDE_ROUTE ;
 case RSVP_CLASS_JUNIPER_PROPERTIES : return RSVPF_JUNIPER ;
 case RSVP_CLASS_VENDOR_PRIVATE_1 : case RSVP_CLASS_VENDOR_PRIVATE_2 : case RSVP_CLASS_VENDOR_PRIVATE_3 : case RSVP_CLASS_VENDOR_PRIVATE_4 : case RSVP_CLASS_VENDOR_PRIVATE_5 : case RSVP_CLASS_VENDOR_PRIVATE_6 : case RSVP_CLASS_VENDOR_PRIVATE_7 : case RSVP_CLASS_VENDOR_PRIVATE_8 : case RSVP_CLASS_VENDOR_PRIVATE_9 : case RSVP_CLASS_VENDOR_PRIVATE_10 : case RSVP_CLASS_VENDOR_PRIVATE_11 : case RSVP_CLASS_VENDOR_PRIVATE_12 : return RSVPF_PRIVATE_OBJ ;
 default : return RSVPF_UNKNOWN_OBJ ;
 }
 }