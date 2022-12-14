static gboolean k12_seek_read ( wtap * wth , gint64 seek_off , struct wtap_pkthdr * phdr , Buffer * buf , int * err , gchar * * err_info ) {
 k12_t * k12 = ( k12_t * ) wth -> priv ;
 guint8 * buffer ;
 gint len ;
 gboolean status ;
 K12_DBG ( 5 , ( "k12_seek_read: ENTER" ) ) ;
 if ( file_seek ( wth -> random_fh , seek_off , SEEK_SET , err ) == - 1 ) {
 K12_DBG ( 5 , ( "k12_seek_read: SEEK ERROR" ) ) ;
 return FALSE ;
 }
 len = get_record ( k12 , wth -> random_fh , seek_off , TRUE , err , err_info ) ;
 if ( len < 0 ) {
 K12_DBG ( 5 , ( "k12_seek_read: READ ERROR" ) ) ;
 return FALSE ;
 }
 else if ( len < K12_RECORD_SRC_ID + 4 ) {
 K12_DBG ( 5 , ( "k12_seek_read: SHORT READ" ) ) ;
 * err = WTAP_ERR_SHORT_READ ;
 return FALSE ;
 }
 buffer = k12 -> rand_read_buff ;
 status = process_packet_data ( phdr , buf , buffer , ( guint ) len , k12 , err , err_info ) ;
 K12_DBG ( 5 , ( "k12_seek_read: DONE OK" ) ) ;
 return status ;
 }