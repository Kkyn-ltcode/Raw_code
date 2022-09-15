static uint32_t PPC_io_readb ( target_phys_addr_t addr ) {
 uint32_t ret = cpu_inb ( NULL , addr - PPC_IO_BASE ) ;
 # if 0 if ( ( addr < 0x800003F0 || addr > 0x80000400 ) && ( addr < 0x80000074 || addr > 0x80000077 ) && ( addr < 0x80000020 || addr > 0x80000021 ) && ( addr < 0x800000a0 || addr > 0x800000a1 ) && ( addr < 0x800001f0 || addr > 0x800001f7 ) && ( addr < 0x80000170 || addr > 0x80000177 ) && ( addr < 0x8000060 || addr > 0x8000064 ) ) # endif {
 PPC_IO_DPRINTF ( "0x%08x <= 0x%02x\n" , addr - PPC_IO_BASE , ret ) ;
 }
 return ret ;
 }