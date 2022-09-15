static int prom_init1 ( SysBusDevice * dev ) {
 PROMState * s = FROM_SYSBUS ( PROMState , dev ) ;
 memory_region_init_ram ( & s -> prom , OBJECT ( s ) , "sun4m.prom" , PROM_SIZE_MAX ) ;
 vmstate_register_ram_global ( & s -> prom ) ;
 memory_region_set_readonly ( & s -> prom , true ) ;
 sysbus_init_mmio ( dev , & s -> prom ) ;
 return 0 ;
 }