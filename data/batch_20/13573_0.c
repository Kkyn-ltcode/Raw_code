static void inhibit_power_manager ( CommonJob * job , const char * message ) {
 job -> inhibit_cookie = gtk_application_inhibit ( GTK_APPLICATION ( g_application_get_default ( ) ) , GTK_WINDOW ( job -> parent_window ) , GTK_APPLICATION_INHIBIT_LOGOUT | GTK_APPLICATION_INHIBIT_SUSPEND , message ) ;
 }