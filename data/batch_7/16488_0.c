static int virtio_serial_init_pci ( PCIDevice * pci_dev ) {
 VirtIOPCIProxy * proxy = DO_UPCAST ( VirtIOPCIProxy , pci_dev , pci_dev ) ;
 VirtIODevice * vdev ;
 if ( proxy -> class_code != PCI_CLASS_COMMUNICATION_OTHER && proxy -> class_code != PCI_CLASS_DISPLAY_OTHER && proxy -> class_code != PCI_CLASS_OTHERS ) proxy -> class_code = PCI_CLASS_COMMUNICATION_OTHER ;
 vdev = virtio_serial_init ( & pci_dev -> qdev , proxy -> max_virtserial_ports ) ;
 if ( ! vdev ) {
 return - 1 ;
 }
 virtio_init_pci ( proxy , vdev , PCI_VENDOR_ID_REDHAT_QUMRANET , PCI_DEVICE_ID_VIRTIO_CONSOLE , proxy -> class_code , 0x00 ) ;
 return 0 ;
 }