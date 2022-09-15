int cli_scanmschm ( cli_ctx * ctx ) {
 struct mschm_decompressor * mschm_d ;
 struct mschmd_header * mschm_h ;
 struct mschmd_file * mschm_f ;
 int ret ;
 int files ;
 int virus_num = 0 ;
 struct mspack_name mspack_fmap = {
 . fmap = * ctx -> fmap , }
 ;
 struct mspack_system_ex ops_ex ;
 memset ( & ops_ex , 0 , sizeof ( struct mspack_system_ex ) ) ;
 ops_ex . ops = mspack_sys_fmap_ops ;
 MSPACK_SYS_SELFTEST ( ret ) ;
 if ( ret ) {
 cli_dbgmsg ( "%s() failed at %d\n" , __func__ , __LINE__ ) ;
 return CL_EUNPACK ;
 }
 mschm_d = mspack_create_chm_decompressor ( & ops_ex . ops ) ;
 if ( ! mschm_d ) {
 cli_dbgmsg ( "%s() failed at %d\n" , __func__ , __LINE__ ) ;
 return CL_EUNPACK ;
 }
 mschm_h = mschm_d -> open ( mschm_d , ( char * ) & mspack_fmap ) ;
 if ( ! mschm_h ) {
 ret = CL_EFORMAT ;
 cli_dbgmsg ( "%s() failed at %d\n" , __func__ , __LINE__ ) ;
 goto out_dest ;
 }
 files = 0 ;
 for ( mschm_f = mschm_h -> files ;
 mschm_f ;
 mschm_f = mschm_f -> next ) {
 off_t max_size ;
 char * tmp_fname ;
 ret = cli_matchmeta ( ctx , mschm_f -> filename , 0 , mschm_f -> length , 0 , files , 0 , NULL ) ;
 if ( ret ) {
 if ( ret == CL_VIRUS ) {
 virus_num ++ ;
 if ( ! SCAN_ALL ) break ;
 }
 goto out_close ;
 }
 if ( ctx -> engine -> maxscansize ) {
 if ( ctx -> scansize >= ctx -> engine -> maxscansize ) {
 ret = CL_CLEAN ;
 break ;
 }
 }
 if ( ctx -> engine -> maxscansize && ctx -> scansize + ctx -> engine -> maxfilesize >= ctx -> engine -> maxscansize ) max_size = ctx -> engine -> maxscansize - ctx -> scansize ;
 else max_size = ctx -> engine -> maxfilesize ? ctx -> engine -> maxfilesize : 0xffffffff ;
 ops_ex . max_size = max_size ;
 tmp_fname = cli_gentemp ( ctx -> engine -> tmpdir ) ;
 if ( ! tmp_fname ) {
 ret = CL_EMEM ;
 break ;
 }
 ret = mschm_d -> extract ( mschm_d , mschm_f , tmp_fname ) ;
 if ( ret ) cli_dbgmsg ( "%s() failed to extract %d\n" , __func__ , ret ) ;
 ret = cli_scanfile ( tmp_fname , ctx ) ;
 if ( ret == CL_VIRUS ) virus_num ++ ;
 if ( ! ctx -> engine -> keeptmp ) {
 if ( ! access ( tmp_fname , R_OK ) && cli_unlink ( tmp_fname ) ) {
 free ( tmp_fname ) ;
 ret = CL_EUNLINK ;
 break ;
 }
 }
 free ( tmp_fname ) ;
 files ++ ;
 if ( ret == CL_VIRUS && SCAN_ALL ) continue ;
 if ( ret ) break ;
 }
 out_close : mschm_d -> close ( mschm_d , mschm_h ) ;
 out_dest : mspack_destroy_chm_decompressor ( mschm_d ) ;
 if ( virus_num ) return CL_VIRUS ;
 return ret ;
 return 0 ;
 }