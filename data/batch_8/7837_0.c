my_bool include_table ( const uchar * hash_key , size_t len ) {
 return ! my_hash_search ( & ignore_table , hash_key , len ) ;
 }