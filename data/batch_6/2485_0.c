static inline int vorbis_residue_decode ( vorbis_context * vc , vorbis_residue * vr , unsigned ch , uint8_t * do_not_decode , float * vec , unsigned vlen , unsigned ch_left ) {
 if ( vr -> type == 2 ) return vorbis_residue_decode_internal ( vc , vr , ch , do_not_decode , vec , vlen , ch_left , 2 ) ;
 else if ( vr -> type == 1 ) return vorbis_residue_decode_internal ( vc , vr , ch , do_not_decode , vec , vlen , ch_left , 1 ) ;
 else if ( vr -> type == 0 ) return vorbis_residue_decode_internal ( vc , vr , ch , do_not_decode , vec , vlen , ch_left , 0 ) ;
 else {
 av_log ( vc -> avctx , AV_LOG_ERROR , " Invalid residue type while residue decode?! \n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 }