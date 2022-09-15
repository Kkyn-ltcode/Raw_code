static const char * name ## _get_name ( void * ctx ) \ {
 return # name ;
 \ }
 static const AVClass name ## _class = {
 . class_name = # name , . item_name = name ## _get_name , . option = name ## _options \ }
 typedef struct DefaultContext {
 const AVClass * class ;
 int nokey ;
 int noprint_wrappers ;
 int nested_section [ SECTION_MAX_NB_LEVELS ] ;
 }
 DefaultContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( DefaultContext , x ) static const AVOption default_options [ ] = {
 {
 "noprint_wrappers" , "do not print headers and footers" , OFFSET ( noprint_wrappers ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "nw" , "do not print headers and footers" , OFFSET ( noprint_wrappers ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "nokey" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "nk" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( default ) ;
 static inline char * upcase_string ( char * dst , size_t dst_size , const char * src ) {
 int i ;
 for ( i = 0 ;
 src [ i ] && i < dst_size - 1 ;
 i ++ ) dst [ i ] = av_toupper ( src [ i ] ) ;
 dst [ i ] = 0 ;
 return dst ;
 }
 static void default_print_section_header ( WriterContext * wctx ) {
 DefaultContext * def = wctx -> priv ;
 char buf [ 32 ] ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 const struct section * parent_section = wctx -> level ? wctx -> section [ wctx -> level - 1 ] : NULL ;
 av_bprint_clear ( & wctx -> section_pbuf [ wctx -> level ] ) ;
 if ( parent_section && ! ( parent_section -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) {
 def -> nested_section [ wctx -> level ] = 1 ;
 av_bprintf ( & wctx -> section_pbuf [ wctx -> level ] , "%s%s:" , wctx -> section_pbuf [ wctx -> level - 1 ] . str , upcase_string ( buf , sizeof ( buf ) , av_x_if_null ( section -> element_name , section -> name ) ) ) ;
 }
 if ( def -> noprint_wrappers || def -> nested_section [ wctx -> level ] ) return ;
 if ( ! ( section -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) printf ( "[%s]\n" , upcase_string ( buf , sizeof ( buf ) , section -> name ) ) ;
 }
 static void default_print_section_footer ( WriterContext * wctx ) {
 DefaultContext * def = wctx -> priv ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 char buf [ 32 ] ;
 if ( def -> noprint_wrappers || def -> nested_section [ wctx -> level ] ) return ;
 if ( ! ( section -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) printf ( "[/%s]\n" , upcase_string ( buf , sizeof ( buf ) , section -> name ) ) ;
 }
 static void default_print_str ( WriterContext * wctx , const char * key , const char * value ) {
 DefaultContext * def = wctx -> priv ;
 if ( ! def -> nokey ) printf ( "%s%s=" , wctx -> section_pbuf [ wctx -> level ] . str , key ) ;
 printf ( "%s\n" , value ) ;
 }
 static void default_print_int ( WriterContext * wctx , const char * key , long long int value ) {
 DefaultContext * def = wctx -> priv ;
 if ( ! def -> nokey ) printf ( "%s%s=" , wctx -> section_pbuf [ wctx -> level ] . str , key ) ;
 printf ( "%lld\n" , value ) ;
 }
 static const Writer default_writer = {
 . name = "default" , . priv_size = sizeof ( DefaultContext ) , . print_section_header = default_print_section_header , . print_section_footer = default_print_section_footer , . print_integer = default_print_int , . print_string = default_print_str , . flags = WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS , . priv_class = & default_class , }
 ;
 static const char * c_escape_str ( AVBPrint * dst , const char * src , const char sep , void * log_ctx ) {
 const char * p ;
 for ( p = src ;
 * p ;
 p ++ ) {
 switch ( * p ) {
 case '\b' : av_bprintf ( dst , "%s" , "\\b" ) ;
 break ;
 case '\f' : av_bprintf ( dst , "%s" , "\\f" ) ;
 break ;
 case '\n' : av_bprintf ( dst , "%s" , "\\n" ) ;
 break ;
 case '\r' : av_bprintf ( dst , "%s" , "\\r" ) ;
 break ;
 case '\\' : av_bprintf ( dst , "%s" , "\\\\" ) ;
 break ;
 default : if ( * p == sep ) av_bprint_chars ( dst , '\\' , 1 ) ;
 av_bprint_chars ( dst , * p , 1 ) ;
 }
 }
 return dst -> str ;
 }
 static const char * csv_escape_str ( AVBPrint * dst , const char * src , const char sep , void * log_ctx ) {
 char meta_chars [ ] = {
 sep , '"' , '\n' , '\r' , '\0' }
 ;
 int needs_quoting = ! ! src [ strcspn ( src , meta_chars ) ] ;
 if ( needs_quoting ) av_bprint_chars ( dst , '"' , 1 ) ;
 for ( ;
 * src ;
 src ++ ) {
 if ( * src == '"' ) av_bprint_chars ( dst , '"' , 1 ) ;
 av_bprint_chars ( dst , * src , 1 ) ;
 }
 if ( needs_quoting ) av_bprint_chars ( dst , '"' , 1 ) ;
 return dst -> str ;
 }
 static const char * none_escape_str ( AVBPrint * dst , const char * src , const char sep , void * log_ctx ) {
 return src ;
 }
 typedef struct CompactContext {
 const AVClass * class ;
 char * item_sep_str ;
 char item_sep ;
 int nokey ;
 int print_section ;
 char * escape_mode_str ;
 const char * ( * escape_str ) ( AVBPrint * dst , const char * src , const char sep , void * log_ctx ) ;
 int nested_section [ SECTION_MAX_NB_LEVELS ] ;
 int has_nested_elems [ SECTION_MAX_NB_LEVELS ] ;
 int terminate_line [ SECTION_MAX_NB_LEVELS ] ;
 }
 CompactContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( CompactContext , x ) static const AVOption compact_options [ ] = {
 {
 "item_sep" , "set item separator" , OFFSET ( item_sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "|" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "s" , "set item separator" , OFFSET ( item_sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "|" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "nokey" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "nk" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "escape" , "set escape mode" , OFFSET ( escape_mode_str ) , AV_OPT_TYPE_STRING , {
 . str = "c" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "e" , "set escape mode" , OFFSET ( escape_mode_str ) , AV_OPT_TYPE_STRING , {
 . str = "c" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "print_section" , "print section name" , OFFSET ( print_section ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "p" , "print section name" , OFFSET ( print_section ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( compact ) ;
 static av_cold int compact_init ( WriterContext * wctx ) {
 CompactContext * compact = wctx -> priv ;
 if ( strlen ( compact -> item_sep_str ) != 1 ) {
 av_log ( wctx , AV_LOG_ERROR , "Item separator '%s' specified, but must contain a single character\n" , compact -> item_sep_str ) ;
 return AVERROR ( EINVAL ) ;
 }
 compact -> item_sep = compact -> item_sep_str [ 0 ] ;
 if ( ! strcmp ( compact -> escape_mode_str , "none" ) ) compact -> escape_str = none_escape_str ;
 else if ( ! strcmp ( compact -> escape_mode_str , "c" ) ) compact -> escape_str = c_escape_str ;
 else if ( ! strcmp ( compact -> escape_mode_str , "csv" ) ) compact -> escape_str = csv_escape_str ;
 else {
 av_log ( wctx , AV_LOG_ERROR , "Unknown escape mode '%s'\n" , compact -> escape_mode_str ) ;
 return AVERROR ( EINVAL ) ;
 }
 return 0 ;
 }
 static void compact_print_section_header ( WriterContext * wctx ) {
 CompactContext * compact = wctx -> priv ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 const struct section * parent_section = wctx -> level ? wctx -> section [ wctx -> level - 1 ] : NULL ;
 compact -> terminate_line [ wctx -> level ] = 1 ;
 compact -> has_nested_elems [ wctx -> level ] = 0 ;
 av_bprint_clear ( & wctx -> section_pbuf [ wctx -> level ] ) ;
 if ( ! ( section -> flags & SECTION_FLAG_IS_ARRAY ) && parent_section && ! ( parent_section -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) {
 compact -> nested_section [ wctx -> level ] = 1 ;
 compact -> has_nested_elems [ wctx -> level - 1 ] = 1 ;
 av_bprintf ( & wctx -> section_pbuf [ wctx -> level ] , "%s%s:" , wctx -> section_pbuf [ wctx -> level - 1 ] . str , ( char * ) av_x_if_null ( section -> element_name , section -> name ) ) ;
 wctx -> nb_item [ wctx -> level ] = wctx -> nb_item [ wctx -> level - 1 ] ;
 }
 else {
 if ( parent_section && compact -> has_nested_elems [ wctx -> level - 1 ] && ( section -> flags & SECTION_FLAG_IS_ARRAY ) ) {
 compact -> terminate_line [ wctx -> level - 1 ] = 0 ;
 printf ( "\n" ) ;
 }
 if ( compact -> print_section && ! ( section -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) printf ( "%s%c" , section -> name , compact -> item_sep ) ;
 }
 }
 static void compact_print_section_footer ( WriterContext * wctx ) {
 CompactContext * compact = wctx -> priv ;
 if ( ! compact -> nested_section [ wctx -> level ] && compact -> terminate_line [ wctx -> level ] && ! ( wctx -> section [ wctx -> level ] -> flags & ( SECTION_FLAG_IS_WRAPPER | SECTION_FLAG_IS_ARRAY ) ) ) printf ( "\n" ) ;
 }
 static void compact_print_str ( WriterContext * wctx , const char * key , const char * value ) {
 CompactContext * compact = wctx -> priv ;
 AVBPrint buf ;
 if ( wctx -> nb_item [ wctx -> level ] ) printf ( "%c" , compact -> item_sep ) ;
 if ( ! compact -> nokey ) printf ( "%s%s=" , wctx -> section_pbuf [ wctx -> level ] . str , key ) ;
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 printf ( "%s" , compact -> escape_str ( & buf , value , compact -> item_sep , wctx ) ) ;
 av_bprint_finalize ( & buf , NULL ) ;
 }
 static void compact_print_int ( WriterContext * wctx , const char * key , long long int value ) {
 CompactContext * compact = wctx -> priv ;
 if ( wctx -> nb_item [ wctx -> level ] ) printf ( "%c" , compact -> item_sep ) ;
 if ( ! compact -> nokey ) printf ( "%s%s=" , wctx -> section_pbuf [ wctx -> level ] . str , key ) ;
 printf ( "%lld" , value ) ;
 }
 static const Writer compact_writer = {
 . name = "compact" , . priv_size = sizeof ( CompactContext ) , . init = compact_init , . print_section_header = compact_print_section_header , . print_section_footer = compact_print_section_footer , . print_integer = compact_print_int , . print_string = compact_print_str , . flags = WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS , . priv_class = & compact_class , }
 ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( CompactContext , x ) static const AVOption csv_options [ ] = {
 {
 "item_sep" , "set item separator" , OFFSET ( item_sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "," }
 , CHAR_MIN , CHAR_MAX }
 , {
 "s" , "set item separator" , OFFSET ( item_sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "," }
 , CHAR_MIN , CHAR_MAX }
 , {
 "nokey" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "nk" , "force no key printing" , OFFSET ( nokey ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "escape" , "set escape mode" , OFFSET ( escape_mode_str ) , AV_OPT_TYPE_STRING , {
 . str = "csv" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "e" , "set escape mode" , OFFSET ( escape_mode_str ) , AV_OPT_TYPE_STRING , {
 . str = "csv" }
 , CHAR_MIN , CHAR_MAX }
 , {
 "print_section" , "print section name" , OFFSET ( print_section ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "p" , "print section name" , OFFSET ( print_section ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( csv ) ;
 static const Writer csv_writer = {
 . name = "csv" , . priv_size = sizeof ( CompactContext ) , . init = compact_init , . print_section_header = compact_print_section_header , . print_section_footer = compact_print_section_footer , . print_integer = compact_print_int , . print_string = compact_print_str , . flags = WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS , . priv_class = & csv_class , }
 ;
 typedef struct FlatContext {
 const AVClass * class ;
 const char * sep_str ;
 char sep ;
 int hierarchical ;
 }
 FlatContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( FlatContext , x ) static const AVOption flat_options [ ] = {
 {
 "sep_char" , "set separator" , OFFSET ( sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "." }
 , CHAR_MIN , CHAR_MAX }
 , {
 "s" , "set separator" , OFFSET ( sep_str ) , AV_OPT_TYPE_STRING , {
 . str = "." }
 , CHAR_MIN , CHAR_MAX }
 , {
 "hierarchical" , "specify if the section specification should be hierarchical" , OFFSET ( hierarchical ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "h" , "specify if the section specification should be hierarchical" , OFFSET ( hierarchical ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( flat ) ;
 static av_cold int flat_init ( WriterContext * wctx ) {
 FlatContext * flat = wctx -> priv ;
 if ( strlen ( flat -> sep_str ) != 1 ) {
 av_log ( wctx , AV_LOG_ERROR , "Item separator '%s' specified, but must contain a single character\n" , flat -> sep_str ) ;
 return AVERROR ( EINVAL ) ;
 }
 flat -> sep = flat -> sep_str [ 0 ] ;
 return 0 ;
 }
 static const char * flat_escape_key_str ( AVBPrint * dst , const char * src , const char sep ) {
 const char * p ;
 for ( p = src ;
 * p ;
 p ++ ) {
 if ( ! ( ( * p >= '0' && * p <= '9' ) || ( * p >= 'a' && * p <= 'z' ) || ( * p >= 'A' && * p <= 'Z' ) ) ) av_bprint_chars ( dst , '_' , 1 ) ;
 else av_bprint_chars ( dst , * p , 1 ) ;
 }
 return dst -> str ;
 }
 static const char * flat_escape_value_str ( AVBPrint * dst , const char * src ) {
 const char * p ;
 for ( p = src ;
 * p ;
 p ++ ) {
 switch ( * p ) {
 case '\n' : av_bprintf ( dst , "%s" , "\\n" ) ;
 break ;
 case '\r' : av_bprintf ( dst , "%s" , "\\r" ) ;
 break ;
 case '\\' : av_bprintf ( dst , "%s" , "\\\\" ) ;
 break ;
 case '"' : av_bprintf ( dst , "%s" , "\\\"" ) ;
 break ;
 case '`' : av_bprintf ( dst , "%s" , "\\`" ) ;
 break ;
 case '$' : av_bprintf ( dst , "%s" , "\\$" ) ;
 break ;
 default : av_bprint_chars ( dst , * p , 1 ) ;
 break ;
 }
 }
 return dst -> str ;
 }
 static void flat_print_section_header ( WriterContext * wctx ) {
 FlatContext * flat = wctx -> priv ;
 AVBPrint * buf = & wctx -> section_pbuf [ wctx -> level ] ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 const struct section * parent_section = wctx -> level ? wctx -> section [ wctx -> level - 1 ] : NULL ;
 av_bprint_clear ( buf ) ;
 if ( ! parent_section ) return ;
 av_bprintf ( buf , "%s" , wctx -> section_pbuf [ wctx -> level - 1 ] . str ) ;
 if ( flat -> hierarchical || ! ( section -> flags & ( SECTION_FLAG_IS_ARRAY | SECTION_FLAG_IS_WRAPPER ) ) ) {
 av_bprintf ( buf , "%s%s" , wctx -> section [ wctx -> level ] -> name , flat -> sep_str ) ;
 if ( parent_section -> flags & SECTION_FLAG_IS_ARRAY ) {
 int n = parent_section -> id == SECTION_ID_PACKETS_AND_FRAMES ? wctx -> nb_section_packet_frame : wctx -> nb_item [ wctx -> level - 1 ] ;
 av_bprintf ( buf , "%d%s" , n , flat -> sep_str ) ;
 }
 }
 }
 static void flat_print_int ( WriterContext * wctx , const char * key , long long int value ) {
 printf ( "%s%s=%lld\n" , wctx -> section_pbuf [ wctx -> level ] . str , key , value ) ;
 }
 static void flat_print_str ( WriterContext * wctx , const char * key , const char * value ) {
 FlatContext * flat = wctx -> priv ;
 AVBPrint buf ;
 printf ( "%s" , wctx -> section_pbuf [ wctx -> level ] . str ) ;
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 printf ( "%s=" , flat_escape_key_str ( & buf , key , flat -> sep ) ) ;
 av_bprint_clear ( & buf ) ;
 printf ( "\"%s\"\n" , flat_escape_value_str ( & buf , value ) ) ;
 av_bprint_finalize ( & buf , NULL ) ;
 }
 static const Writer flat_writer = {
 . name = "flat" , . priv_size = sizeof ( FlatContext ) , . init = flat_init , . print_section_header = flat_print_section_header , . print_integer = flat_print_int , . print_string = flat_print_str , . flags = WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS | WRITER_FLAG_PUT_PACKETS_AND_FRAMES_IN_SAME_CHAPTER , . priv_class = & flat_class , }
 ;
 typedef struct INIContext {
 const AVClass * class ;
 int hierarchical ;
 }
 INIContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( INIContext , x ) static const AVOption ini_options [ ] = {
 {
 "hierarchical" , "specify if the section specification should be hierarchical" , OFFSET ( hierarchical ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 "h" , "specify if the section specification should be hierarchical" , OFFSET ( hierarchical ) , AV_OPT_TYPE_BOOL , {
 . i64 = 1 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( ini ) ;
 static char * ini_escape_str ( AVBPrint * dst , const char * src ) {
 int i = 0 ;
 char c = 0 ;
 while ( c = src [ i ++ ] ) {
 switch ( c ) {
 case '\b' : av_bprintf ( dst , "%s" , "\\b" ) ;
 break ;
 case '\f' : av_bprintf ( dst , "%s" , "\\f" ) ;
 break ;
 case '\n' : av_bprintf ( dst , "%s" , "\\n" ) ;
 break ;
 case '\r' : av_bprintf ( dst , "%s" , "\\r" ) ;
 break ;
 case '\t' : av_bprintf ( dst , "%s" , "\\t" ) ;
 break ;
 case '\\' : case '#' : case '=' : case ':' : av_bprint_chars ( dst , '\\' , 1 ) ;
 default : if ( ( unsigned char ) c < 32 ) av_bprintf ( dst , "\\x00%02x" , c & 0xff ) ;
 else av_bprint_chars ( dst , c , 1 ) ;
 break ;
 }
 }
 return dst -> str ;
 }
 static void ini_print_section_header ( WriterContext * wctx ) {
 INIContext * ini = wctx -> priv ;
 AVBPrint * buf = & wctx -> section_pbuf [ wctx -> level ] ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 const struct section * parent_section = wctx -> level ? wctx -> section [ wctx -> level - 1 ] : NULL ;
 av_bprint_clear ( buf ) ;
 if ( ! parent_section ) {
 printf ( "# ffprobe output\n\n" ) ;
 return ;
 }
 if ( wctx -> nb_item [ wctx -> level - 1 ] ) printf ( "\n" ) ;
 av_bprintf ( buf , "%s" , wctx -> section_pbuf [ wctx -> level - 1 ] . str ) ;
 if ( ini -> hierarchical || ! ( section -> flags & ( SECTION_FLAG_IS_ARRAY | SECTION_FLAG_IS_WRAPPER ) ) ) {
 av_bprintf ( buf , "%s%s" , buf -> str [ 0 ] ? "." : "" , wctx -> section [ wctx -> level ] -> name ) ;
 if ( parent_section -> flags & SECTION_FLAG_IS_ARRAY ) {
 int n = parent_section -> id == SECTION_ID_PACKETS_AND_FRAMES ? wctx -> nb_section_packet_frame : wctx -> nb_item [ wctx -> level - 1 ] ;
 av_bprintf ( buf , ".%d" , n ) ;
 }
 }
 if ( ! ( section -> flags & ( SECTION_FLAG_IS_ARRAY | SECTION_FLAG_IS_WRAPPER ) ) ) printf ( "[%s]\n" , buf -> str ) ;
 }
 static void ini_print_str ( WriterContext * wctx , const char * key , const char * value ) {
 AVBPrint buf ;
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 printf ( "%s=" , ini_escape_str ( & buf , key ) ) ;
 av_bprint_clear ( & buf ) ;
 printf ( "%s\n" , ini_escape_str ( & buf , value ) ) ;
 av_bprint_finalize ( & buf , NULL ) ;
 }
 static void ini_print_int ( WriterContext * wctx , const char * key , long long int value ) {
 printf ( "%s=%lld\n" , key , value ) ;
 }
 static const Writer ini_writer = {
 . name = "ini" , . priv_size = sizeof ( INIContext ) , . print_section_header = ini_print_section_header , . print_integer = ini_print_int , . print_string = ini_print_str , . flags = WRITER_FLAG_DISPLAY_OPTIONAL_FIELDS | WRITER_FLAG_PUT_PACKETS_AND_FRAMES_IN_SAME_CHAPTER , . priv_class = & ini_class , }
 ;
 typedef struct JSONContext {
 const AVClass * class ;
 int indent_level ;
 int compact ;
 const char * item_sep , * item_start_end ;
 }
 JSONContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( JSONContext , x ) static const AVOption json_options [ ] = {
 {
 "compact" , "enable compact output" , OFFSET ( compact ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "c" , "enable compact output" , OFFSET ( compact ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 NULL }
 }
 ;
 DEFINE_WRITER_CLASS ( json ) ;
 static av_cold int json_init ( WriterContext * wctx ) {
 JSONContext * json = wctx -> priv ;
 json -> item_sep = json -> compact ? ", " : ",\n" ;
 json -> item_start_end = json -> compact ? " " : "\n" ;
 return 0 ;
 }
 static const char * json_escape_str ( AVBPrint * dst , const char * src , void * log_ctx ) {
 static const char json_escape [ ] = {
 '"' , '\\' , '\b' , '\f' , '\n' , '\r' , '\t' , 0 }
 ;
 static const char json_subst [ ] = {
 '"' , '\\' , 'b' , 'f' , 'n' , 'r' , 't' , 0 }
 ;
 const char * p ;
 for ( p = src ;
 * p ;
 p ++ ) {
 char * s = strchr ( json_escape , * p ) ;
 if ( s ) {
 av_bprint_chars ( dst , '\\' , 1 ) ;
 av_bprint_chars ( dst , json_subst [ s - json_escape ] , 1 ) ;
 }
 else if ( ( unsigned char ) * p < 32 ) {
 av_bprintf ( dst , "\\u00%02x" , * p & 0xff ) ;
 }
 else {
 av_bprint_chars ( dst , * p , 1 ) ;
 }
 }
 return dst -> str ;
 }
 # define JSON_INDENT ( ) printf ( "%*c" , json -> indent_level * 4 , ' ' ) static void json_print_section_header ( WriterContext * wctx ) {
 JSONContext * json = wctx -> priv ;
 AVBPrint buf ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 const struct section * parent_section = wctx -> level ? wctx -> section [ wctx -> level - 1 ] : NULL ;
 if ( wctx -> level && wctx -> nb_item [ wctx -> level - 1 ] ) printf ( ",\n" ) ;
 if ( section -> flags & SECTION_FLAG_IS_WRAPPER ) {
 printf ( "{
\n" ) ;
 json -> indent_level ++ ;
 }
 else {
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 json_escape_str ( & buf , section -> name , wctx ) ;
 JSON_INDENT ( ) ;
 json -> indent_level ++ ;
 if ( section -> flags & SECTION_FLAG_IS_ARRAY ) {
 printf ( "\"%s\": [\n" , buf . str ) ;
 }
 else if ( parent_section && ! ( parent_section -> flags & SECTION_FLAG_IS_ARRAY ) ) {
 printf ( "\"%s\": {
%s" , buf . str , json -> item_start_end ) ;
 }
 else {
 printf ( "{
%s" , json -> item_start_end ) ;
 if ( parent_section && parent_section -> id == SECTION_ID_PACKETS_AND_FRAMES ) {
 if ( ! json -> compact ) JSON_INDENT ( ) ;
 printf ( "\"type\": \"%s\"%s" , section -> name , json -> item_sep ) ;
 }
 }
 av_bprint_finalize ( & buf , NULL ) ;
 }
 }
 static void json_print_section_footer ( WriterContext * wctx ) {
 JSONContext * json = wctx -> priv ;
 const struct section * section = wctx -> section [ wctx -> level ] ;
 if ( wctx -> level == 0 ) {
 json -> indent_level -- ;
 printf ( "\n}
\n" ) ;
 }
 else if ( section -> flags & SECTION_FLAG_IS_ARRAY ) {
 printf ( "\n" ) ;
 json -> indent_level -- ;
 JSON_INDENT ( ) ;
 printf ( "]" ) ;
 }
 else {
 printf ( "%s" , json -> item_start_end ) ;
 json -> indent_level -- ;
 if ( ! json -> compact ) JSON_INDENT ( ) ;
 printf ( "}
" ) ;
 }
 }
 static inline void json_print_item_str ( WriterContext * wctx , const char * key , const char * value ) {
 AVBPrint buf ;
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 printf ( "\"%s\":" , json_escape_str ( & buf , key , wctx ) ) ;
 av_bprint_clear ( & buf ) ;
 printf ( " \"%s\"" , json_escape_str ( & buf , value , wctx ) ) ;
 av_bprint_finalize ( & buf , NULL ) ;
 }
 static void json_print_str ( WriterContext * wctx , const char * key , const char * value ) {
 JSONContext * json = wctx -> priv ;
 if ( wctx -> nb_item [ wctx -> level ] ) printf ( "%s" , json -> item_sep ) ;
 if ( ! json -> compact ) JSON_INDENT ( ) ;
 json_print_item_str ( wctx , key , value ) ;
 }
 static void json_print_int ( WriterContext * wctx , const char * key , long long int value ) {
 JSONContext * json = wctx -> priv ;
 AVBPrint buf ;
 if ( wctx -> nb_item [ wctx -> level ] ) printf ( "%s" , json -> item_sep ) ;
 if ( ! json -> compact ) JSON_INDENT ( ) ;
 av_bprint_init ( & buf , 1 , AV_BPRINT_SIZE_UNLIMITED ) ;
 printf ( "\"%s\": %lld" , json_escape_str ( & buf , key , wctx ) , value ) ;
 av_bprint_finalize ( & buf , NULL ) ;
 }
 static const Writer json_writer = {
 . name = "json" , . priv_size = sizeof ( JSONContext ) , . init = json_init , . print_section_header = json_print_section_header , . print_section_footer = json_print_section_footer , . print_integer = json_print_int , . print_string = json_print_str , . flags = WRITER_FLAG_PUT_PACKETS_AND_FRAMES_IN_SAME_CHAPTER , . priv_class = & json_class , }
 ;
 typedef struct XMLContext {
 const AVClass * class ;
 int within_tag ;
 int indent_level ;
 int fully_qualified ;
 int xsd_strict ;
 }
 XMLContext ;
 # undef OFFSET # define OFFSET ( x ) offsetof ( XMLContext , x ) static const AVOption xml_options [ ] = {
 {
 "fully_qualified" , "specify if the output should be fully qualified" , OFFSET ( fully_qualified ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "q" , "specify if the output should be fully qualified" , OFFSET ( fully_qualified ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "xsd_strict" , "ensure that the output is XSD compliant" , OFFSET ( xsd_strict ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 "x" , "ensure that the output is XSD compliant" , OFFSET ( xsd_strict ) , AV_OPT_TYPE_BOOL , {
 . i64 = 0 }
 , 0 , 1 }
 , {
 NULL }
 , }
 ;
 DEFINE_WRITER_CLASS ( xml )