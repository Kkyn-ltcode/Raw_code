void update_key_parts ( MI_KEYDEF * keyinfo , ulong * rec_per_key_part , ulonglong * unique , ulonglong * notnull , ulonglong records ) {
 ulonglong count = 0 , tmp , unique_tuples ;
 ulonglong tuples = records ;
 uint parts ;
 for ( parts = 0 ;
 parts < keyinfo -> keysegs ;
 parts ++ ) {
 count += unique [ parts ] ;
 unique_tuples = count + 1 ;
 if ( notnull ) {
 tuples = notnull [ parts ] ;
 unique_tuples -= ( records - notnull [ parts ] ) ;
 }
 if ( unique_tuples == 0 ) tmp = 1 ;
 else if ( count == 0 ) tmp = tuples ;
 else tmp = ( tuples + unique_tuples / 2 ) / unique_tuples ;
 set_if_bigger ( tmp , 1 ) ;
 if ( tmp >= ( ulonglong ) ~ ( ulong ) 0 ) tmp = ( ulonglong ) ~ ( ulong ) 0 ;
 * rec_per_key_part = ( ulong ) tmp ;
 rec_per_key_part ++ ;
 }
 }