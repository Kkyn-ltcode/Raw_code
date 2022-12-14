static void pci_cirrus_vga_realize ( PCIDevice * dev , Error * * errp ) {
 PCICirrusVGAState * d = PCI_CIRRUS_VGA ( dev ) ;
 CirrusVGAState * s = & d -> cirrus_vga ;
 PCIDeviceClass * pc = PCI_DEVICE_GET_CLASS ( dev ) ;
 int16_t device_id = pc -> device_id ;
 if ( s -> vga . vram_size_mb != 4 && s -> vga . vram_size_mb != 8 && s -> vga . vram_size_mb != 16 ) {
 error_setg ( errp , "Invalid cirrus_vga ram size '%u'" , s -> vga . vram_size_mb ) ;
 return ;
 }
 vga_common_init ( & s -> vga , OBJECT ( dev ) , true ) ;
 cirrus_init_common ( s , OBJECT ( dev ) , device_id , 1 , pci_address_space ( dev ) , pci_address_space_io ( dev ) ) ;
 s -> vga . con = graphic_console_init ( DEVICE ( dev ) , 0 , s -> vga . hw_ops , & s -> vga ) ;
 memory_region_init ( & s -> pci_bar , OBJECT ( dev ) , "cirrus-pci-bar0" , 0x2000000 ) ;
 memory_region_add_subregion ( & s -> pci_bar , 0 , & s -> cirrus_linear_io ) ;
 memory_region_add_subregion ( & s -> pci_bar , 0x1000000 , & s -> cirrus_linear_bitblt_io ) ;
 pci_register_bar ( & d -> dev , 0 , PCI_BASE_ADDRESS_MEM_PREFETCH , & s -> pci_bar ) ;
 if ( device_id == CIRRUS_ID_CLGD5446 ) {
 pci_register_bar ( & d -> dev , 1 , 0 , & s -> cirrus_mmio_io ) ;
 }
 }