static inline void e1000e_set_16bit ( E1000ECore * core , int index , uint32_t val ) {
 core -> mac [ index ] = val & 0xffff ;
 }