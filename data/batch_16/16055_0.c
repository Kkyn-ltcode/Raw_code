static void openpic_save_IRQ_queue ( QEMUFile * f , IRQQueue * q ) {
 unsigned int i ;
 for ( i = 0 ;
 i < ARRAY_SIZE ( q -> queue ) ;
 i ++ ) {
 qemu_put_be32 ( f , ( uint32_t ) q -> queue [ i ] ) ;
 # if LONG_MAX > 0x7FFFFFFF qemu_put_be32 ( f , ( uint32_t ) ( q -> queue [ i ] >> 32 ) ) ;
 # endif }
 qemu_put_sbe32s ( f , & q -> next ) ;
 qemu_put_sbe32s ( f , & q -> priority ) ;
 }