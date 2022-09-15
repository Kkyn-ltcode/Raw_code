static int dca_exss_mask2count ( int mask ) {
 return av_popcount ( mask ) + av_popcount ( mask & ( DCA_EXSS_CENTER_LEFT_RIGHT | DCA_EXSS_FRONT_LEFT_RIGHT | DCA_EXSS_FRONT_HIGH_LEFT_RIGHT | DCA_EXSS_WIDE_LEFT_RIGHT | DCA_EXSS_SIDE_LEFT_RIGHT | DCA_EXSS_SIDE_HIGH_LEFT_RIGHT | DCA_EXSS_SIDE_REAR_LEFT_RIGHT | DCA_EXSS_REAR_LEFT_RIGHT | DCA_EXSS_REAR_HIGH_LEFT_RIGHT ) ) ;
 }