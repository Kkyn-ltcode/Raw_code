static void decode_color_temperature ( gchar * s , guint16 value ) {
 if ( value == 0 ) {
 g_snprintf ( s , ITEM_LABEL_LENGTH , "%u [Mired]" , value ) ;
 }
 else {
 g_snprintf ( s , ITEM_LABEL_LENGTH , "%u [Mired] (%u [K])" , value , 1000000 / value ) ;
 }
 return ;
 }