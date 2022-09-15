static uint32_t PPC_io_readw ( target_phys_addr_t addr ) {
 uint32_t ret = cpu_inw ( NULL , addr - PPC_IO_BASE ) ;
 # ifdef TARGET_WORDS_BIGENDIAN ret = bswap16 ( ret ) ;
 # endif if ( ( addr < 0x800001f0 || addr > 0x800001f7 ) && ( addr < 0x80000170 || addr > 0x80000177 ) ) {
 PPC_IO_DPRINTF ( "0x%08x <= 0x%04x\n" , addr - PPC_IO_BASE , ret ) ;
 }
 return ret ;
 }