static void thumbnail_loader_size_prepared ( GdkPixbufLoader * loader , int width , int height , gpointer user_data ) {
 int max_thumbnail_size ;
 double aspect_ratio ;
 aspect_ratio = ( ( double ) width ) / height ;
 max_thumbnail_size = NAUTILUS_CANVAS_ICON_SIZE_LARGER * cached_thumbnail_size / NAUTILUS_CANVAS_ICON_SIZE_SMALL ;
 if ( MAX ( width , height ) > max_thumbnail_size ) {
 if ( width > height ) {
 width = max_thumbnail_size ;
 height = width / aspect_ratio ;
 }
 else {
 height = max_thumbnail_size ;
 width = height * aspect_ratio ;
 }
 gdk_pixbuf_loader_set_size ( loader , width , height ) ;
 }
 }