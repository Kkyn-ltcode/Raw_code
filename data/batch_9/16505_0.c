static int virtio_blk_init_pci ( PCIDevice * pci_dev ) {
 VirtIOPCIProxy * proxy = DO_UPCAST ( VirtIOPCIProxy , pci_dev , pci_dev ) ;
 VirtIODevice * vdev ;
 if ( proxy -> class_code != PCI_CLASS_STORAGE_SCSI && proxy -> class_code != PCI_CLASS_STORAGE_OTHER ) proxy -> class_code = PCI_CLASS_STORAGE_SCSI ;
 if ( ! proxy -> dinfo ) {
 qemu_error ( "virtio-blk-pci: drive property not set\n" ) ;
 return - 1 ;
 }
 vdev = virtio_blk_init ( & pci_dev -> qdev , proxy -> dinfo ) ;
 vdev -> nvectors = proxy -> nvectors ;
 virtio_init_pci ( proxy , vdev , PCI_VENDOR_ID_REDHAT_QUMRANET , PCI_DEVICE_ID_VIRTIO_BLOCK , proxy -> class_code , 0x00 ) ;
 proxy -> nvectors = vdev -> nvectors ;
 return 0 ;
 }