static void selinux_cred_free ( struct cred * cred ) {
 struct task_security_struct * tsec = cred -> security ;
 BUG_ON ( cred -> security && ( unsigned long ) cred -> security < PAGE_SIZE ) ;
 cred -> security = ( void * ) 0x7UL ;
 kfree ( tsec ) ;
 }