static void VGA_init ( void ) {
 printf ( "Init VGA...\n" ) ;
 # if 1 PPC_io_writeb ( PPC_IO_BASE + 0x3C2 , 0xC3 ) ;
 PPC_io_writeb ( PPC_IO_BASE + 0x3C4 , 0x04 ) ;
 PPC_io_writeb ( PPC_IO_BASE + 0x3C5 , 0x02 ) ;
 # endif VGA_printf ( "PPC VGA BIOS...\n" ) ;
 }