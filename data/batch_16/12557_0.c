static inline MagickBooleanType IsPixelInfoMonochrome ( const PixelInfo * restrict pixel_info ) {
 if ( ( pixel_info -> colorspace != GRAYColorspace ) && ( pixel_info -> colorspace != RGBColorspace ) ) return ( MagickFalse ) ;
 if ( ( AbsolutePixelValue ( pixel_info -> red ) >= MagickEpsilon ) || ( AbsolutePixelValue ( pixel_info -> red - QuantumRange ) >= MagickEpsilon ) ) return ( MagickFalse ) ;
 if ( ( AbsolutePixelValue ( pixel_info -> red - pixel_info -> green ) < MagickEpsilon ) && ( AbsolutePixelValue ( pixel_info -> green - pixel_info -> blue ) < MagickEpsilon ) ) return ( MagickTrue ) ;
 return ( MagickFalse ) ;
 }