static MagickBooleanType CompositeOverImage ( Image * image , const Image * composite_image , const MagickBooleanType clip_to_self , const ssize_t x_offset , const ssize_t y_offset , ExceptionInfo * exception ) {
 # define CompositeImageTag "Composite/Image" CacheView * composite_view , * image_view ;
 MagickBooleanType status ;
 MagickOffsetType progress ;
 ssize_t y ;
 status = MagickTrue ;
 progress = 0 ;
 composite_view = AcquireVirtualCacheView ( composite_image , exception ) ;
 image_view = AcquireAuthenticCacheView ( image , exception ) ;
 # if defined ( MAGICKCORE_OPENMP_SUPPORT ) # pragma omp parallel for schedule ( static , 4 ) shared ( progress , status ) magick_threads ( composite_image , image , image -> rows , 1 ) # endif for ( y = 0 ;
 y < ( ssize_t ) image -> rows ;
 y ++ ) {
 const Quantum * pixels ;
 register const Quantum * restrict p ;
 register Quantum * restrict q ;
 register ssize_t x ;
 size_t channels ;
 if ( status == MagickFalse ) continue ;
 if ( clip_to_self != MagickFalse ) {
 if ( y < y_offset ) continue ;
 if ( ( y - y_offset ) >= ( ssize_t ) composite_image -> rows ) continue ;
 }
 pixels = ( Quantum * ) NULL ;
 p = ( Quantum * ) NULL ;
 if ( ( y >= y_offset ) && ( ( y - y_offset ) < ( ssize_t ) composite_image -> rows ) ) {
 p = GetCacheViewVirtualPixels ( composite_view , 0 , y - y_offset , composite_image -> columns , 1 , exception ) ;
 if ( p == ( const Quantum * ) NULL ) {
 status = MagickFalse ;
 continue ;
 }
 pixels = p ;
 if ( x_offset < 0 ) p -= x_offset * GetPixelChannels ( composite_image ) ;
 }
 q = GetCacheViewAuthenticPixels ( image_view , 0 , y , image -> columns , 1 , exception ) ;
 if ( q == ( Quantum * ) NULL ) {
 status = MagickFalse ;
 continue ;
 }
 for ( x = 0 ;
 x < ( ssize_t ) image -> columns ;
 x ++ ) {
 MagickRealType Da , Dc , Dca , Sa , Sc , Sca ;
 register ssize_t i ;
 if ( clip_to_self != MagickFalse ) {
 if ( x < x_offset ) {
 q += GetPixelChannels ( image ) ;
 continue ;
 }
 if ( ( x - x_offset ) >= ( ssize_t ) composite_image -> columns ) break ;
 }
 if ( ( pixels == ( Quantum * ) NULL ) || ( x < x_offset ) || ( ( x - x_offset ) >= ( ssize_t ) composite_image -> columns ) ) {
 Quantum source [ MaxPixelChannels ] ;
 if ( GetPixelReadMask ( image , q ) == 0 ) {
 q += GetPixelChannels ( image ) ;
 continue ;
 }
 ( void ) GetOneVirtualPixel ( composite_image , x - x_offset , y - y_offset , source , exception ) ;
 for ( i = 0 ;
 i < ( ssize_t ) GetPixelChannels ( image ) ;
 i ++ ) {
 PixelChannel channel = GetPixelChannelChannel ( image , i ) ;
 PixelTrait traits = GetPixelChannelTraits ( image , channel ) ;
 PixelTrait composite_traits = GetPixelChannelTraits ( composite_image , channel ) ;
 if ( ( traits == UndefinedPixelTrait ) || ( composite_traits == UndefinedPixelTrait ) ) continue ;
 q [ i ] = source [ channel ] ;
 }
 q += GetPixelChannels ( image ) ;
 continue ;
 }
 if ( GetPixelReadMask ( composite_image , p ) == 0 ) {
 p += GetPixelChannels ( composite_image ) ;
 channels = GetPixelChannels ( composite_image ) ;
 if ( p >= ( pixels + channels * composite_image -> columns ) ) p = pixels ;
 q += GetPixelChannels ( image ) ;
 continue ;
 }
 Sa = QuantumScale * GetPixelAlpha ( composite_image , p ) ;
 Da = QuantumScale * GetPixelAlpha ( image , q ) ;
 for ( i = 0 ;
 i < ( ssize_t ) GetPixelChannels ( image ) ;
 i ++ ) {
 PixelChannel channel = GetPixelChannelChannel ( image , i ) ;
 PixelTrait traits = GetPixelChannelTraits ( image , channel ) ;
 PixelTrait composite_traits = GetPixelChannelTraits ( composite_image , channel ) ;
 if ( ( traits == UndefinedPixelTrait ) || ( composite_traits == UndefinedPixelTrait ) ) continue ;
 if ( ( traits & CopyPixelTrait ) != 0 ) {
 q [ i ] = GetPixelChannel ( composite_image , channel , p ) ;
 continue ;
 }
 if ( channel == AlphaPixelChannel ) {
 q [ i ] = ClampToQuantum ( QuantumRange * ( Sa + Da - Sa * Da ) ) ;
 continue ;
 }
 Sc = ( MagickRealType ) GetPixelChannel ( composite_image , channel , p ) ;
 Dc = ( MagickRealType ) q [ i ] ;
 Sca = QuantumScale * Sa * Sc ;
 Dca = QuantumScale * Da * Dc ;
 q [ i ] = ClampToQuantum ( QuantumRange * ( Sca + Dca * ( 1.0 - Sa ) ) ) ;
 }
 p += GetPixelChannels ( composite_image ) ;
 channels = GetPixelChannels ( composite_image ) ;
 if ( p >= ( pixels + channels * composite_image -> columns ) ) p = pixels ;
 q += GetPixelChannels ( image ) ;
 }
 if ( SyncCacheViewAuthenticPixels ( image_view , exception ) == MagickFalse ) status = MagickFalse ;
 if ( image -> progress_monitor != ( MagickProgressMonitor ) NULL ) {
 MagickBooleanType proceed ;
 # if defined ( MAGICKCORE_OPENMP_SUPPORT ) # pragma omp critical ( MagickCore_CompositeImage ) # endif proceed = SetImageProgress ( image , CompositeImageTag , progress ++ , image -> rows ) ;
 if ( proceed == MagickFalse ) status = MagickFalse ;
 }
 }
 composite_view = DestroyCacheView ( composite_view ) ;
 image_view = DestroyCacheView ( image_view ) ;
 return ( status ) ;
 }