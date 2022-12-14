static inline void NVRAM_set_lword ( m48t59_t * nvram , uint32_t addr , uint32_t value ) {
 m48t59_set_addr ( nvram , addr ) ;
 m48t59_write ( nvram , value >> 24 ) ;
 m48t59_set_addr ( nvram , addr + 1 ) ;
 m48t59_write ( nvram , ( value >> 16 ) & 0xFF ) ;
 m48t59_set_addr ( nvram , addr + 2 ) ;
 m48t59_write ( nvram , ( value >> 8 ) & 0xFF ) ;
 m48t59_set_addr ( nvram , addr + 3 ) ;
 m48t59_write ( nvram , value & 0xFF ) ;
 }