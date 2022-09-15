static inline Quantum ClampPixel ( const MagickRealType value ) {
 # if ! defined ( MAGICKCORE_HDRI_SUPPORT ) return ( ( Quantum ) value ) ;
 # else if ( value < 0.0 ) return ( ( Quantum ) 0.0 ) ;
 if ( value >= ( MagickRealType ) QuantumRange ) return ( ( Quantum ) QuantumRange ) ;
 return ( ( Quantum ) value ) ;
 # endif }