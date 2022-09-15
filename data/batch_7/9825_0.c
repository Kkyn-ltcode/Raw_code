static void balloon_page ( void * addr , int deflate ) {
 # if defined ( __linux__ ) if ( ! kvm_enabled ( ) || kvm_has_sync_mmu ( ) ) qemu_madvise ( addr , TARGET_PAGE_SIZE , deflate ? QEMU_MADV_WILLNEED : QEMU_MADV_DONTNEED ) ;
 # endif }