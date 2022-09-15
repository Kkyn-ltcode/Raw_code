static uint32_t PPC_io_readl ( target_phys_addr_t addr ) {
 uint32_t ret = cpu_inl ( NULL , addr - PPC_IO_BASE ) ;
 # ifdef TARGET_WORDS_BIGENDIAN ret = bswap32 ( ret ) ;
 # endif PPC_IO_DPRINTF ( "0x%08x <= 0x%08x\n" , addr - PPC_IO_BASE , ret ) ;
 return ret ;
 }