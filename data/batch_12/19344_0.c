hb_bool_t hb_set_set_user_data ( hb_set_t * set , hb_user_data_key_t * key , void * data , hb_destroy_func_t destroy , hb_bool_t replace ) {
 return hb_object_set_user_data ( set , key , data , destroy , replace ) ;
 }