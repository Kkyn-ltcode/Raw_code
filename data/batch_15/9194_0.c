static const char * cmd_rule ( cmd_parms * cmd , void * _dcfg , const char * p1 , const char * p2 , const char * p3 ) {
 return add_rule ( cmd , ( directory_config * ) _dcfg , RULE_TYPE_NORMAL , p1 , p2 , p3 ) ;
 }