static void PPC_io_writel ( target_phys_addr_t addr , uint32_t value ) {
 PPC_IO_DPRINTF ( "0x%08x => 0x%08x\n" , addr - PPC_IO_BASE , value ) ;
 # ifdef TARGET_WORDS_BIGENDIAN value = bswap32 ( value ) ;
 # endif cpu_outl ( NULL , addr - PPC_IO_BASE , value ) ;
 }