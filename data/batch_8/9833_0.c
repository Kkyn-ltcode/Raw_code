static void virtio_balloon_stat ( void * opaque , BalloonInfo * info ) {
 VirtIOBalloon * dev = opaque ;
 # if 0 if ( dev -> vdev . guest_features & ( 1 << VIRTIO_BALLOON_F_STATS_VQ ) ) {
 virtqueue_push ( dev -> svq , & dev -> stats_vq_elem , dev -> stats_vq_offset ) ;
 virtio_notify ( & dev -> vdev , dev -> svq ) ;
 return ;
 }
 # endif reset_stats ( dev ) ;
 info -> actual = ram_size - ( ( uint64_t ) dev -> actual << VIRTIO_BALLOON_PFN_SHIFT ) ;
 }