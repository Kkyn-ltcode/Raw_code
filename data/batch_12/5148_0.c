static void pk_transaction_authorize_actions_finished_cb ( GObject * source_object , GAsyncResult * res , struct AuthorizeActionsData * data ) {
 const gchar * action_id = NULL ;
 PkTransactionPrivate * priv = data -> transaction -> priv ;
 g_autoptr ( GError ) error = NULL ;
 g_autoptr ( PolkitAuthorizationResult ) result = NULL ;
 g_assert ( data -> actions && data -> actions -> len > 0 ) ;
 action_id = g_ptr_array_index ( data -> actions , 0 ) ;
 result = polkit_authority_check_authorization_finish ( priv -> authority , res , & error ) ;
 if ( g_cancellable_is_cancelled ( priv -> cancellable ) ) {
 priv -> waiting_for_auth = FALSE ;
 pk_transaction_status_changed_emit ( data -> transaction , PK_STATUS_ENUM_FINISHED ) ;
 pk_transaction_error_code_emit ( data -> transaction , PK_ERROR_ENUM_NOT_AUTHORIZED , "The authentication was cancelled due to a timeout." ) ;
 pk_transaction_finished_emit ( data -> transaction , PK_EXIT_ENUM_FAILED , 0 ) ;
 goto out ;
 }
 if ( result == NULL ) {
 g_autofree gchar * message = NULL ;
 priv -> waiting_for_auth = FALSE ;
 g_warning ( "failed to check for auth: %s" , error -> message ) ;
 pk_transaction_status_changed_emit ( data -> transaction , PK_STATUS_ENUM_FINISHED ) ;
 message = g_strdup_printf ( "Failed to check for authentication: %s" , error -> message ) ;
 pk_transaction_error_code_emit ( data -> transaction , PK_ERROR_ENUM_NOT_AUTHORIZED , message ) ;
 pk_transaction_finished_emit ( data -> transaction , PK_EXIT_ENUM_FAILED , 0 ) ;
 goto out ;
 }
 if ( ! polkit_authorization_result_get_is_authorized ( result ) ) {
 priv -> waiting_for_auth = FALSE ;
 pk_transaction_status_changed_emit ( data -> transaction , PK_STATUS_ENUM_FINISHED ) ;
 pk_transaction_error_code_emit ( data -> transaction , PK_ERROR_ENUM_NOT_AUTHORIZED , "Failed to obtain authentication." ) ;
 pk_transaction_finished_emit ( data -> transaction , PK_EXIT_ENUM_FAILED , 0 ) ;
 syslog ( LOG_AUTH | LOG_NOTICE , "uid %i failed to obtain auth" , priv -> uid ) ;
 goto out ;
 }
 if ( data -> actions -> len <= 1 ) {
 priv -> waiting_for_auth = FALSE ;
 pk_transaction_set_state ( data -> transaction , PK_TRANSACTION_STATE_READY ) ;
 syslog ( LOG_AUTH | LOG_INFO , "uid %i obtained auth for %s" , priv -> uid , action_id ) ;
 }
 else {
 g_ptr_array_remove_index ( data -> actions , 0 ) ;
 pk_transaction_authorize_actions ( data -> transaction , data -> role , data -> actions ) ;
 }
 out : g_ptr_array_unref ( data -> actions ) ;
 g_free ( data ) ;
 }