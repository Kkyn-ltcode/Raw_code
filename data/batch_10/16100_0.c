void list_cpus ( FILE * f , fprintf_function cpu_fprintf , const char * optarg ) {
 # if defined ( cpu_list ) cpu_list ( f , cpu_fprintf ) ;
 # endif }