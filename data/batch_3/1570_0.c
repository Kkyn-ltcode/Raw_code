static int jpc_enc_encodemainhdr ( jpc_enc_t * enc ) {
 jpc_siz_t * siz ;
 jpc_cod_t * cod ;
 jpc_qcd_t * qcd ;
 int i ;
 long startoff ;
 long mainhdrlen ;
 jpc_enc_cp_t * cp ;
 jpc_qcc_t * qcc ;
 jpc_enc_tccp_t * tccp ;
 uint_fast16_t cmptno ;
 jpc_tsfb_band_t bandinfos [ JPC_MAXBANDS ] ;
 jpc_fix_t mctsynweight ;
 jpc_enc_tcp_t * tcp ;
 jpc_tsfb_t * tsfb ;
 jpc_tsfb_band_t * bandinfo ;
 uint_fast16_t numbands ;
 uint_fast16_t bandno ;
 uint_fast16_t rlvlno ;
 uint_fast16_t analgain ;
 jpc_fix_t absstepsize ;
 char buf [ 1024 ] ;
 jpc_com_t * com ;
 cp = enc -> cp ;
 startoff = jas_stream_getrwcount ( enc -> out ) ;
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_SOC ) ) ) {
 return - 1 ;
 }
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 jas_eprintf ( "cannot write SOC marker\n" ) ;
 return - 1 ;
 }
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_SIZ ) ) ) {
 return - 1 ;
 }
 siz = & enc -> mrk -> parms . siz ;
 siz -> caps = 0 ;
 siz -> xoff = cp -> imgareatlx ;
 siz -> yoff = cp -> imgareatly ;
 siz -> width = cp -> refgrdwidth ;
 siz -> height = cp -> refgrdheight ;
 siz -> tilexoff = cp -> tilegrdoffx ;
 siz -> tileyoff = cp -> tilegrdoffy ;
 siz -> tilewidth = cp -> tilewidth ;
 siz -> tileheight = cp -> tileheight ;
 siz -> numcomps = cp -> numcmpts ;
 siz -> comps = jas_alloc2 ( siz -> numcomps , sizeof ( jpc_sizcomp_t ) ) ;
 assert ( siz -> comps ) ;
 for ( i = 0 ;
 i < JAS_CAST ( int , cp -> numcmpts ) ;
 ++ i ) {
 siz -> comps [ i ] . prec = cp -> ccps [ i ] . prec ;
 siz -> comps [ i ] . sgnd = cp -> ccps [ i ] . sgnd ;
 siz -> comps [ i ] . hsamp = cp -> ccps [ i ] . sampgrdstepx ;
 siz -> comps [ i ] . vsamp = cp -> ccps [ i ] . sampgrdstepy ;
 }
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 jas_eprintf ( "cannot write SIZ marker\n" ) ;
 return - 1 ;
 }
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_COM ) ) ) {
 return - 1 ;
 }
 sprintf ( buf , "Creator: JasPer Version %s" , jas_getversion ( ) ) ;
 com = & enc -> mrk -> parms . com ;
 com -> len = JAS_CAST ( uint_fast16_t , strlen ( buf ) ) ;
 com -> regid = JPC_COM_LATIN ;
 if ( ! ( com -> data = JAS_CAST ( jas_uchar * , jas_strdup ( buf ) ) ) ) {
 abort ( ) ;
 }
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 jas_eprintf ( "cannot write COM marker\n" ) ;
 return - 1 ;
 }
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 # if 0 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_CRG ) ) ) {
 return - 1 ;
 }
 crg = & enc -> mrk -> parms . crg ;
 crg -> comps = jas_alloc2 ( crg -> numcomps , sizeof ( jpc_crgcomp_t ) ) ;
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 jas_eprintf ( "cannot write CRG marker\n" ) ;
 return - 1 ;
 }
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 # endif tcp = & cp -> tcp ;
 tccp = & cp -> tccp ;
 for ( cmptno = 0 ;
 cmptno < cp -> numcmpts ;
 ++ cmptno ) {
 tsfb = jpc_cod_gettsfb ( tccp -> qmfbid , tccp -> maxrlvls - 1 ) ;
 jpc_tsfb_getbands ( tsfb , 0 , 0 , 1 << tccp -> maxrlvls , 1 << tccp -> maxrlvls , bandinfos ) ;
 jpc_tsfb_destroy ( tsfb ) ;
 mctsynweight = jpc_mct_getsynweight ( tcp -> mctid , cmptno ) ;
 numbands = 3 * tccp -> maxrlvls - 2 ;
 for ( bandno = 0 , bandinfo = bandinfos ;
 bandno < numbands ;
 ++ bandno , ++ bandinfo ) {
 rlvlno = ( bandno ) ? ( ( bandno - 1 ) / 3 + 1 ) : 0 ;
 analgain = JPC_NOMINALGAIN ( tccp -> qmfbid , tccp -> maxrlvls , rlvlno , bandinfo -> orient ) ;
 if ( ! tcp -> intmode ) {
 absstepsize = jpc_fix_div ( jpc_inttofix ( 1 << ( analgain + 1 ) ) , bandinfo -> synenergywt ) ;
 }
 else {
 absstepsize = jpc_inttofix ( 1 ) ;
 }
 cp -> ccps [ cmptno ] . stepsizes [ bandno ] = jpc_abstorelstepsize ( absstepsize , cp -> ccps [ cmptno ] . prec + analgain ) ;
 }
 cp -> ccps [ cmptno ] . numstepsizes = numbands ;
 }
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_COD ) ) ) {
 return - 1 ;
 }
 cod = & enc -> mrk -> parms . cod ;
 cod -> csty = cp -> tccp . csty | cp -> tcp . csty ;
 cod -> compparms . csty = cp -> tccp . csty | cp -> tcp . csty ;
 cod -> compparms . numdlvls = cp -> tccp . maxrlvls - 1 ;
 cod -> compparms . numrlvls = cp -> tccp . maxrlvls ;
 cod -> prg = cp -> tcp . prg ;
 cod -> numlyrs = cp -> tcp . numlyrs ;
 cod -> compparms . cblkwidthval = JPC_COX_CBLKSIZEEXPN ( cp -> tccp . cblkwidthexpn ) ;
 cod -> compparms . cblkheightval = JPC_COX_CBLKSIZEEXPN ( cp -> tccp . cblkheightexpn ) ;
 cod -> compparms . cblksty = cp -> tccp . cblksty ;
 cod -> compparms . qmfbid = cp -> tccp . qmfbid ;
 cod -> mctrans = ( cp -> tcp . mctid != JPC_MCT_NONE ) ;
 if ( tccp -> csty & JPC_COX_PRT ) {
 for ( rlvlno = 0 ;
 rlvlno < tccp -> maxrlvls ;
 ++ rlvlno ) {
 cod -> compparms . rlvls [ rlvlno ] . parwidthval = tccp -> prcwidthexpns [ rlvlno ] ;
 cod -> compparms . rlvls [ rlvlno ] . parheightval = tccp -> prcheightexpns [ rlvlno ] ;
 }
 }
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 jas_eprintf ( "cannot write COD marker\n" ) ;
 return - 1 ;
 }
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_QCD ) ) ) {
 return - 1 ;
 }
 qcd = & enc -> mrk -> parms . qcd ;
 qcd -> compparms . qntsty = ( tccp -> qmfbid == JPC_COX_INS ) ? JPC_QCX_SEQNT : JPC_QCX_NOQNT ;
 qcd -> compparms . numstepsizes = cp -> ccps [ 0 ] . numstepsizes ;
 qcd -> compparms . numguard = cp -> tccp . numgbits ;
 qcd -> compparms . stepsizes = cp -> ccps [ 0 ] . stepsizes ;
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 return - 1 ;
 }
 qcd -> compparms . stepsizes = 0 ;
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 tccp = & cp -> tccp ;
 for ( cmptno = 1 ;
 cmptno < cp -> numcmpts ;
 ++ cmptno ) {
 if ( ! ( enc -> mrk = jpc_ms_create ( JPC_MS_QCC ) ) ) {
 return - 1 ;
 }
 qcc = & enc -> mrk -> parms . qcc ;
 qcc -> compno = cmptno ;
 qcc -> compparms . qntsty = ( tccp -> qmfbid == JPC_COX_INS ) ? JPC_QCX_SEQNT : JPC_QCX_NOQNT ;
 qcc -> compparms . numstepsizes = cp -> ccps [ cmptno ] . numstepsizes ;
 qcc -> compparms . numguard = cp -> tccp . numgbits ;
 qcc -> compparms . stepsizes = cp -> ccps [ cmptno ] . stepsizes ;
 if ( jpc_putms ( enc -> out , enc -> cstate , enc -> mrk ) ) {
 return - 1 ;
 }
 qcc -> compparms . stepsizes = 0 ;
 jpc_ms_destroy ( enc -> mrk ) ;
 enc -> mrk = 0 ;
 }
 # define MAINTLRLEN 2 mainhdrlen = jas_stream_getrwcount ( enc -> out ) - startoff ;
 enc -> len += mainhdrlen ;
 if ( enc -> cp -> totalsize != UINT_FAST32_MAX ) {
 uint_fast32_t overhead ;
 overhead = mainhdrlen + MAINTLRLEN ;
 enc -> mainbodysize = ( enc -> cp -> totalsize >= overhead ) ? ( enc -> cp -> totalsize - overhead ) : 0 ;
 }
 else {
 enc -> mainbodysize = UINT_FAST32_MAX ;
 }
 return 0 ;
 }