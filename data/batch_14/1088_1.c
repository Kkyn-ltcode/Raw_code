static void decode_color_temperature ( gchar * s , guint16 value ) {
 g_snprintf ( s , ITEM_LABEL_LENGTH , "%d [Mired] (%d [K])" , value , 1000000 / value ) ;
 return ;
 }