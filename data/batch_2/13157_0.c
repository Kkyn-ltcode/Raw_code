static void cleanup_pam ( int retcode ) {
 int saved_errno = errno ;
 if ( _pam_session_opened ) pam_close_session ( pamh , 0 ) ;
 if ( _pam_cred_established ) pam_setcred ( pamh , PAM_DELETE_CRED | PAM_SILENT ) ;
 pam_end ( pamh , retcode ) ;
 errno = saved_errno ;
 }