static gint dissect_as_if_format_type_body ( tvbuff_t * tvb , gint offset , packet_info * pinfo _U_ , proto_tree * tree , usb_conv_info_t * usb_conv_info ) {
 audio_conv_info_t * audio_conv_info ;
 gint offset_start ;
 guint8 SamFreqType ;
 guint8 format_type ;
 audio_conv_info = ( audio_conv_info_t * ) usb_conv_info -> class_data ;
 if ( ! audio_conv_info ) return 0 ;
 offset_start = offset ;
 proto_tree_add_item ( tree , hf_as_if_ft_formattype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 format_type = tvb_get_guint8 ( tvb , offset ) ;
 offset ++ ;
 switch ( format_type ) {
 case 1 : proto_tree_add_item ( tree , hf_as_if_ft_nrchannels , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 1 ;
 proto_tree_add_item ( tree , hf_as_if_ft_subframesize , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 1 ;
 proto_tree_add_item ( tree , hf_as_if_ft_bitresolution , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 1 ;
 proto_tree_add_item ( tree , hf_as_if_ft_samfreqtype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 SamFreqType = tvb_get_guint8 ( tvb , offset ) ;
 offset ++ ;
 if ( SamFreqType == 0 ) {
 proto_tree_add_item ( tree , hf_as_if_ft_lowersamfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 proto_tree_add_item ( tree , hf_as_if_ft_uppersamfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 }
 else {
 while ( SamFreqType ) {
 proto_tree_add_item ( tree , hf_as_if_ft_samfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 SamFreqType -- ;
 }
 }
 break ;
 case 2 : proto_tree_add_item ( tree , hf_as_if_ft_maxbitrate , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( tree , hf_as_if_ft_samplesperframe , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( tree , hf_as_if_ft_samfreqtype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 SamFreqType = tvb_get_guint8 ( tvb , offset ) ;
 offset ++ ;
 if ( SamFreqType == 0 ) {
 proto_tree_add_item ( tree , hf_as_if_ft_lowersamfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 proto_tree_add_item ( tree , hf_as_if_ft_uppersamfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 }
 else {
 while ( SamFreqType ) {
 proto_tree_add_item ( tree , hf_as_if_ft_samfreq , tvb , offset , 3 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 SamFreqType -- ;
 }
 }
 break ;
 default : break ;
 }
 return offset - offset_start ;
 }