static gint round_to_4byte ( gint current_offset , gint starting_offset ) {
 gint length = current_offset - starting_offset ;
 return starting_offset + ROUND_TO_4BYTE ( length ) ;
 }