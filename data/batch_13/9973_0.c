static void set_pseudo_header_frame4 ( union wtap_pseudo_header * pseudo_header , struct frame4_rec * frame4 ) {
 guint32 StatusWord ;
 guint8 aal_type , hl_type ;
 guint16 vpi , vci ;
 pseudo_header -> atm . flags = 0 ;
 StatusWord = pletoh32 ( & frame4 -> atm_info . StatusWord ) ;
 if ( StatusWord & SW_RAW_CELL ) pseudo_header -> atm . flags |= ATM_RAW_CELL ;
 aal_type = frame4 -> atm_info . AppTrafType & ATT_AALTYPE ;
 hl_type = frame4 -> atm_info . AppTrafType & ATT_HLTYPE ;
 vpi = pletoh16 ( & frame4 -> atm_info . Vpi ) ;
 vci = pletoh16 ( & frame4 -> atm_info . Vci ) ;
 switch ( aal_type ) {
 case ATT_AAL_UNKNOWN : if ( vpi == 0 && vci == 5 ) pseudo_header -> atm . aal = AAL_SIGNALLING ;
 else pseudo_header -> atm . aal = AAL_UNKNOWN ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_AAL1 : pseudo_header -> atm . aal = AAL_1 ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_AAL3_4 : pseudo_header -> atm . aal = AAL_3_4 ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_AAL5 : pseudo_header -> atm . aal = AAL_5 ;
 switch ( hl_type ) {
 case ATT_HL_UNKNOWN : pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_HL_LLCMX : pseudo_header -> atm . type = TRAF_LLCMX ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_HL_VCMX : pseudo_header -> atm . type = TRAF_VCMX ;
 switch ( frame4 -> atm_info . AppHLType ) {
 case AHLT_UNKNOWN : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case AHLT_VCMX_802_3_FCS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_3_FCS ;
 break ;
 case AHLT_VCMX_802_4_FCS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_4_FCS ;
 break ;
 case AHLT_VCMX_802_5_FCS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_5_FCS ;
 break ;
 case AHLT_VCMX_FDDI_FCS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_FDDI_FCS ;
 break ;
 case AHLT_VCMX_802_6_FCS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_6_FCS ;
 break ;
 case AHLT_VCMX_802_3 : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_3 ;
 break ;
 case AHLT_VCMX_802_4 : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_4 ;
 break ;
 case AHLT_VCMX_802_5 : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_5 ;
 break ;
 case AHLT_VCMX_FDDI : pseudo_header -> atm . subtype = TRAF_ST_VCMX_FDDI ;
 break ;
 case AHLT_VCMX_802_6 : pseudo_header -> atm . subtype = TRAF_ST_VCMX_802_6 ;
 break ;
 case AHLT_VCMX_FRAGMENTS : pseudo_header -> atm . subtype = TRAF_ST_VCMX_FRAGMENTS ;
 break ;
 case AHLT_VCMX_BPDU : pseudo_header -> atm . subtype = TRAF_ST_VCMX_BPDU ;
 break ;
 default : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 }
 break ;
 case ATT_HL_LANE : pseudo_header -> atm . type = TRAF_LANE ;
 switch ( frame4 -> atm_info . AppHLType ) {
 case AHLT_UNKNOWN : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case AHLT_LANE_LE_CTRL : pseudo_header -> atm . subtype = TRAF_ST_LANE_LE_CTRL ;
 break ;
 case AHLT_LANE_802_3 : pseudo_header -> atm . subtype = TRAF_ST_LANE_802_3 ;
 break ;
 case AHLT_LANE_802_5 : pseudo_header -> atm . subtype = TRAF_ST_LANE_802_5 ;
 break ;
 case AHLT_LANE_802_3_MC : pseudo_header -> atm . subtype = TRAF_ST_LANE_802_3_MC ;
 break ;
 case AHLT_LANE_802_5_MC : pseudo_header -> atm . subtype = TRAF_ST_LANE_802_5_MC ;
 break ;
 default : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 }
 break ;
 case ATT_HL_ILMI : pseudo_header -> atm . type = TRAF_ILMI ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_HL_FRMR : pseudo_header -> atm . type = TRAF_FR ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_HL_SPANS : pseudo_header -> atm . type = TRAF_SPANS ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_HL_IPSILON : pseudo_header -> atm . type = TRAF_IPSILON ;
 switch ( frame4 -> atm_info . AppHLType ) {
 case AHLT_UNKNOWN : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case AHLT_IPSILON_FT0 : pseudo_header -> atm . subtype = TRAF_ST_IPSILON_FT0 ;
 break ;
 case AHLT_IPSILON_FT1 : pseudo_header -> atm . subtype = TRAF_ST_IPSILON_FT1 ;
 break ;
 case AHLT_IPSILON_FT2 : pseudo_header -> atm . subtype = TRAF_ST_IPSILON_FT2 ;
 break ;
 default : pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 }
 break ;
 default : pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 }
 break ;
 case ATT_AAL_USER : pseudo_header -> atm . aal = AAL_USER ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_AAL_SIGNALLING : pseudo_header -> atm . aal = AAL_SIGNALLING ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 case ATT_OAMCELL : pseudo_header -> atm . aal = AAL_OAMCELL ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 default : pseudo_header -> atm . aal = AAL_UNKNOWN ;
 pseudo_header -> atm . type = TRAF_UNKNOWN ;
 pseudo_header -> atm . subtype = TRAF_ST_UNKNOWN ;
 break ;
 }
 pseudo_header -> atm . vpi = vpi ;
 pseudo_header -> atm . vci = vci ;
 pseudo_header -> atm . channel = pletoh16 ( & frame4 -> atm_info . channel ) ;
 pseudo_header -> atm . cells = pletoh16 ( & frame4 -> atm_info . cells ) ;
 pseudo_header -> atm . aal5t_u2u = pletoh16 ( & frame4 -> atm_info . Trailer . aal5t_u2u ) ;
 pseudo_header -> atm . aal5t_len = pletoh16 ( & frame4 -> atm_info . Trailer . aal5t_len ) ;
 pseudo_header -> atm . aal5t_chksum = pntoh32 ( & frame4 -> atm_info . Trailer . aal5t_chksum ) ;
 }