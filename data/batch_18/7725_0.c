void tmx_pretran_unlink ( void ) {
 int slotid ;
 if ( _tmx_proc_ptran == NULL ) return ;
 slotid = _tmx_proc_ptran -> hid & ( _tmx_ptran_size - 1 ) ;
 lock_get ( & _tmx_ptran_table [ slotid ] . lock ) ;
 tmx_pretran_unlink_safe ( slotid ) ;
 lock_release ( & _tmx_ptran_table [ slotid ] . lock ) ;
 }