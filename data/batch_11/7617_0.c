static uint isam_key_length ( MI_INFO * info , register MI_KEYDEF * keyinfo ) {
 uint length ;
 HA_KEYSEG * keyseg ;
 DBUG_ENTER ( "isam_key_length" ) ;
 length = info -> s -> rec_reflength ;
 for ( keyseg = keyinfo -> seg ;
 keyseg -> type ;
 keyseg ++ ) length += keyseg -> length ;
 DBUG_PRINT ( "exit" , ( "length: %d" , length ) ) ;
 DBUG_RETURN ( length ) ;
 }