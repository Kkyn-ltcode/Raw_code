mysql_declare_plugin ( myisam ) {
 MYSQL_STORAGE_ENGINE_PLUGIN , & myisam_storage_engine , "MyISAM" , "MySQL AB" , "MyISAM storage engine" , PLUGIN_LICENSE_GPL , myisam_init , NULL , 0x0100 , NULL , myisam_sysvars , NULL , 0 , }