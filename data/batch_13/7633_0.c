void myisamchk_init ( MI_CHECK * param ) {
 bzero ( ( uchar * ) param , sizeof ( * param ) ) ;
 param -> opt_follow_links = 1 ;
 param -> keys_in_use = ~ ( ulonglong ) 0 ;
 param -> search_after_block = HA_OFFSET_ERROR ;
 param -> auto_increment_value = 0 ;
 param -> use_buffers = USE_BUFFER_INIT ;
 param -> read_buffer_length = READ_BUFFER_INIT ;
 param -> write_buffer_length = READ_BUFFER_INIT ;
 param -> sort_buffer_length = SORT_BUFFER_INIT ;
 param -> sort_key_blocks = BUFFERS_WHEN_SORTING ;
 param -> tmpfile_createflag = O_RDWR | O_TRUNC | O_EXCL ;
 param -> myf_rw = MYF ( MY_NABP | MY_WME | MY_WAIT_IF_FULL ) ;
 param -> start_check_pos = 0 ;
 param -> max_record_length = LONGLONG_MAX ;
 param -> key_cache_block_size = KEY_CACHE_BLOCK_SIZE ;
 param -> stats_method = MI_STATS_METHOD_NULLS_NOT_EQUAL ;
 param -> need_print_msg_lock = 0 ;
 }