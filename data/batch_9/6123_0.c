void mark_reachable_objects ( struct rev_info * revs , int mark_reflog , unsigned long mark_recent , struct progress * progress ) {
 struct connectivity_progress cp ;
 revs -> tag_objects = 1 ;
 revs -> blob_objects = 1 ;
 revs -> tree_objects = 1 ;
 add_index_objects_to_pending ( revs , 0 ) ;
 for_each_ref ( add_one_ref , revs ) ;
 head_ref ( add_one_ref , revs ) ;
 if ( mark_reflog ) add_reflogs_to_pending ( revs , 0 ) ;
 cp . progress = progress ;
 cp . count = 0 ;
 if ( prepare_revision_walk ( revs ) ) die ( "revision walk setup failed" ) ;
 traverse_commit_list ( revs , mark_commit , mark_object , & cp ) ;
 if ( mark_recent ) {
 revs -> ignore_missing_links = 1 ;
 if ( add_unseen_recent_objects_to_traversal ( revs , mark_recent ) ) die ( "unable to mark recent objects" ) ;
 if ( prepare_revision_walk ( revs ) ) die ( "revision walk setup failed" ) ;
 traverse_commit_list ( revs , mark_commit , mark_object , & cp ) ;
 }
 display_progress ( cp . progress , cp . count ) ;
 }