static void openpic_load_IRQ_queue ( QEMUFile * f , IRQQueue * q ) {
 unsigned int i ;
 for ( i = 0 ;
 i < ARRAY_SIZE ( q -> queue ) ;
 i ++ ) {
 unsigned long val ;
 val = qemu_get_be32 ( f ) ;
 # if LONG_MAX > 0x7FFFFFFF val <<= 32 ;
 val |= qemu_get_be32 ( f ) ;
 # endif q -> queue [ i ] = val ;
 }
 qemu_get_sbe32s ( f , & q -> next ) ;
 qemu_get_sbe32s ( f , & q -> priority ) ;
 }