static void * _conf_to_memberp ( TSOverridableConfigKey conf , OverridableHttpConfigParams * overridableHttpConfig , OverridableDataType * typep ) {
 OverridableDataType typ = OVERRIDABLE_TYPE_BYTE ;
 void * ret = nullptr ;
 switch ( conf ) {
 case TS_CONFIG_URL_REMAP_PRISTINE_HOST_HDR : ret = & overridableHttpConfig -> maintain_pristine_host_hdr ;
 break ;
 case TS_CONFIG_HTTP_CHUNKING_ENABLED : ret = & overridableHttpConfig -> chunking_enabled ;
 break ;
 case TS_CONFIG_HTTP_NEGATIVE_CACHING_ENABLED : ret = & overridableHttpConfig -> negative_caching_enabled ;
 break ;
 case TS_CONFIG_HTTP_NEGATIVE_CACHING_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> negative_caching_lifetime ;
 break ;
 case TS_CONFIG_HTTP_CACHE_WHEN_TO_REVALIDATE : ret = & overridableHttpConfig -> cache_when_to_revalidate ;
 break ;
 case TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_IN : ret = & overridableHttpConfig -> keep_alive_enabled_in ;
 break ;
 case TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_OUT : ret = & overridableHttpConfig -> keep_alive_enabled_out ;
 break ;
 case TS_CONFIG_HTTP_KEEP_ALIVE_POST_OUT : ret = & overridableHttpConfig -> keep_alive_post_out ;
 break ;
 case TS_CONFIG_HTTP_SERVER_SESSION_SHARING_MATCH : ret = & overridableHttpConfig -> server_session_sharing_match ;
 break ;
 case TS_CONFIG_NET_SOCK_RECV_BUFFER_SIZE_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> sock_recv_buffer_size_out ;
 break ;
 case TS_CONFIG_NET_SOCK_SEND_BUFFER_SIZE_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> sock_send_buffer_size_out ;
 break ;
 case TS_CONFIG_NET_SOCK_OPTION_FLAG_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> sock_option_flag_out ;
 break ;
 case TS_CONFIG_HTTP_FORWARD_PROXY_AUTH_TO_PARENT : ret = & overridableHttpConfig -> fwd_proxy_auth_to_parent ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_REMOVE_FROM : ret = & overridableHttpConfig -> anonymize_remove_from ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_REMOVE_REFERER : ret = & overridableHttpConfig -> anonymize_remove_referer ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_REMOVE_USER_AGENT : ret = & overridableHttpConfig -> anonymize_remove_user_agent ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_REMOVE_COOKIE : ret = & overridableHttpConfig -> anonymize_remove_cookie ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_REMOVE_CLIENT_IP : ret = & overridableHttpConfig -> anonymize_remove_client_ip ;
 break ;
 case TS_CONFIG_HTTP_ANONYMIZE_INSERT_CLIENT_IP : ret = & overridableHttpConfig -> anonymize_insert_client_ip ;
 break ;
 case TS_CONFIG_HTTP_RESPONSE_SERVER_ENABLED : ret = & overridableHttpConfig -> proxy_response_server_enabled ;
 break ;
 case TS_CONFIG_HTTP_INSERT_SQUID_X_FORWARDED_FOR : ret = & overridableHttpConfig -> insert_squid_x_forwarded_for ;
 break ;
 case TS_CONFIG_HTTP_SERVER_TCP_INIT_CWND : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> server_tcp_init_cwnd ;
 break ;
 case TS_CONFIG_HTTP_SEND_HTTP11_REQUESTS : ret = & overridableHttpConfig -> send_http11_requests ;
 break ;
 case TS_CONFIG_HTTP_CACHE_HTTP : ret = & overridableHttpConfig -> cache_http ;
 break ;
 case TS_CONFIG_HTTP_CACHE_CLUSTER_CACHE_LOCAL : ret = & overridableHttpConfig -> cache_cluster_cache_local ;
 break ;
 case TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_NO_CACHE : ret = & overridableHttpConfig -> cache_ignore_client_no_cache ;
 break ;
 case TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_CC_MAX_AGE : ret = & overridableHttpConfig -> cache_ignore_client_cc_max_age ;
 break ;
 case TS_CONFIG_HTTP_CACHE_IMS_ON_CLIENT_NO_CACHE : ret = & overridableHttpConfig -> cache_ims_on_client_no_cache ;
 break ;
 case TS_CONFIG_HTTP_CACHE_IGNORE_SERVER_NO_CACHE : ret = & overridableHttpConfig -> cache_ignore_server_no_cache ;
 break ;
 case TS_CONFIG_HTTP_CACHE_CACHE_RESPONSES_TO_COOKIES : ret = & overridableHttpConfig -> cache_responses_to_cookies ;
 break ;
 case TS_CONFIG_HTTP_CACHE_IGNORE_AUTHENTICATION : ret = & overridableHttpConfig -> cache_ignore_auth ;
 break ;
 case TS_CONFIG_HTTP_CACHE_CACHE_URLS_THAT_LOOK_DYNAMIC : ret = & overridableHttpConfig -> cache_urls_that_look_dynamic ;
 break ;
 case TS_CONFIG_HTTP_CACHE_REQUIRED_HEADERS : ret = & overridableHttpConfig -> cache_required_headers ;
 break ;
 case TS_CONFIG_HTTP_INSERT_REQUEST_VIA_STR : ret = & overridableHttpConfig -> insert_request_via_string ;
 break ;
 case TS_CONFIG_HTTP_INSERT_RESPONSE_VIA_STR : ret = & overridableHttpConfig -> insert_response_via_string ;
 break ;
 case TS_CONFIG_HTTP_CACHE_HEURISTIC_MIN_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_heuristic_min_lifetime ;
 break ;
 case TS_CONFIG_HTTP_CACHE_HEURISTIC_MAX_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_heuristic_max_lifetime ;
 break ;
 case TS_CONFIG_HTTP_CACHE_GUARANTEED_MIN_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_guaranteed_min_lifetime ;
 break ;
 case TS_CONFIG_HTTP_CACHE_GUARANTEED_MAX_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_guaranteed_max_lifetime ;
 break ;
 case TS_CONFIG_HTTP_CACHE_MAX_STALE_AGE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_max_stale_age ;
 break ;
 case TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_IN : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> keep_alive_no_activity_timeout_in ;
 break ;
 case TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> keep_alive_no_activity_timeout_out ;
 break ;
 case TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_IN : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> transaction_no_activity_timeout_in ;
 break ;
 case TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> transaction_no_activity_timeout_out ;
 break ;
 case TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> transaction_active_timeout_out ;
 break ;
 case TS_CONFIG_HTTP_ORIGIN_MAX_CONNECTIONS : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> origin_max_connections ;
 break ;
 case TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> connect_attempts_max_retries ;
 break ;
 case TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES_DEAD_SERVER : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> connect_attempts_max_retries_dead_server ;
 break ;
 case TS_CONFIG_HTTP_CONNECT_ATTEMPTS_RR_RETRIES : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> connect_attempts_rr_retries ;
 break ;
 case TS_CONFIG_HTTP_CONNECT_ATTEMPTS_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> connect_attempts_timeout ;
 break ;
 case TS_CONFIG_HTTP_POST_CONNECT_ATTEMPTS_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> post_connect_attempts_timeout ;
 break ;
 case TS_CONFIG_HTTP_DOWN_SERVER_CACHE_TIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> down_server_timeout ;
 break ;
 case TS_CONFIG_HTTP_DOWN_SERVER_ABORT_THRESHOLD : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> client_abort_threshold ;
 break ;
 case TS_CONFIG_HTTP_CACHE_FUZZ_TIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> freshness_fuzz_time ;
 break ;
 case TS_CONFIG_HTTP_CACHE_FUZZ_MIN_TIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> freshness_fuzz_min_time ;
 break ;
 case TS_CONFIG_HTTP_DOC_IN_CACHE_SKIP_DNS : ret = & overridableHttpConfig -> doc_in_cache_skip_dns ;
 break ;
 case TS_CONFIG_HTTP_BACKGROUND_FILL_ACTIVE_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> background_fill_active_timeout ;
 break ;
 case TS_CONFIG_HTTP_RESPONSE_SERVER_STR : typ = OVERRIDABLE_TYPE_STRING ;
 ret = & overridableHttpConfig -> proxy_response_server_string ;
 break ;
 case TS_CONFIG_HTTP_CACHE_HEURISTIC_LM_FACTOR : typ = OVERRIDABLE_TYPE_FLOAT ;
 ret = & overridableHttpConfig -> cache_heuristic_lm_factor ;
 break ;
 case TS_CONFIG_HTTP_CACHE_FUZZ_PROBABILITY : typ = OVERRIDABLE_TYPE_FLOAT ;
 ret = & overridableHttpConfig -> freshness_fuzz_prob ;
 break ;
 case TS_CONFIG_HTTP_BACKGROUND_FILL_COMPLETED_THRESHOLD : typ = OVERRIDABLE_TYPE_FLOAT ;
 ret = & overridableHttpConfig -> background_fill_threshold ;
 break ;
 case TS_CONFIG_NET_SOCK_PACKET_MARK_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> sock_packet_mark_out ;
 break ;
 case TS_CONFIG_NET_SOCK_PACKET_TOS_OUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> sock_packet_tos_out ;
 break ;
 case TS_CONFIG_HTTP_INSERT_AGE_IN_RESPONSE : ret = & overridableHttpConfig -> insert_age_in_response ;
 break ;
 case TS_CONFIG_HTTP_CHUNKING_SIZE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> http_chunking_size ;
 break ;
 case TS_CONFIG_HTTP_FLOW_CONTROL_ENABLED : ret = & overridableHttpConfig -> flow_control_enabled ;
 break ;
 case TS_CONFIG_HTTP_FLOW_CONTROL_LOW_WATER_MARK : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> flow_low_water_mark ;
 break ;
 case TS_CONFIG_HTTP_FLOW_CONTROL_HIGH_WATER_MARK : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> flow_high_water_mark ;
 break ;
 case TS_CONFIG_HTTP_CACHE_RANGE_LOOKUP : ret = & overridableHttpConfig -> cache_range_lookup ;
 break ;
 case TS_CONFIG_HTTP_NORMALIZE_AE_GZIP : ret = & overridableHttpConfig -> normalize_ae_gzip ;
 break ;
 case TS_CONFIG_HTTP_DEFAULT_BUFFER_SIZE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> default_buffer_size_index ;
 break ;
 case TS_CONFIG_HTTP_DEFAULT_BUFFER_WATER_MARK : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> default_buffer_water_mark ;
 break ;
 case TS_CONFIG_HTTP_REQUEST_HEADER_MAX_SIZE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> request_hdr_max_size ;
 break ;
 case TS_CONFIG_HTTP_RESPONSE_HEADER_MAX_SIZE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> response_hdr_max_size ;
 break ;
 case TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_ENABLED : ret = & overridableHttpConfig -> negative_revalidating_enabled ;
 break ;
 case TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_LIFETIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> negative_revalidating_lifetime ;
 break ;
 case TS_CONFIG_SSL_HSTS_MAX_AGE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> proxy_response_hsts_max_age ;
 break ;
 case TS_CONFIG_SSL_HSTS_INCLUDE_SUBDOMAINS : ret = & overridableHttpConfig -> proxy_response_hsts_include_subdomains ;
 break ;
 case TS_CONFIG_HTTP_CACHE_OPEN_READ_RETRY_TIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_open_read_retry_time ;
 break ;
 case TS_CONFIG_HTTP_CACHE_MAX_OPEN_READ_RETRIES : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> max_cache_open_read_retries ;
 break ;
 case TS_CONFIG_HTTP_CACHE_RANGE_WRITE : ret = & overridableHttpConfig -> cache_range_write ;
 break ;
 case TS_CONFIG_HTTP_POST_CHECK_CONTENT_LENGTH_ENABLED : ret = & overridableHttpConfig -> post_check_content_length_enabled ;
 break ;
 case TS_CONFIG_HTTP_GLOBAL_USER_AGENT_HEADER : typ = OVERRIDABLE_TYPE_STRING ;
 ret = & overridableHttpConfig -> global_user_agent_header ;
 break ;
 case TS_CONFIG_HTTP_AUTH_SERVER_SESSION_PRIVATE : ret = & overridableHttpConfig -> auth_server_session_private ;
 break ;
 case TS_CONFIG_HTTP_SLOW_LOG_THRESHOLD : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> slow_log_threshold ;
 break ;
 case TS_CONFIG_HTTP_CACHE_GENERATION : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> cache_generation_number ;
 break ;
 case TS_CONFIG_BODY_FACTORY_TEMPLATE_BASE : typ = OVERRIDABLE_TYPE_STRING ;
 ret = & overridableHttpConfig -> body_factory_template_base ;
 break ;
 case TS_CONFIG_HTTP_CACHE_OPEN_WRITE_FAIL_ACTION : ret = & overridableHttpConfig -> cache_open_write_fail_action ;
 break ;
 case TS_CONFIG_HTTP_ENABLE_REDIRECTION : ret = & overridableHttpConfig -> redirection_enabled ;
 break ;
 case TS_CONFIG_HTTP_NUMBER_OF_REDIRECTIONS : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> number_of_redirections ;
 break ;
 case TS_CONFIG_HTTP_CACHE_MAX_OPEN_WRITE_RETRIES : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> max_cache_open_write_retries ;
 break ;
 case TS_CONFIG_HTTP_REDIRECT_USE_ORIG_CACHE_KEY : ret = & overridableHttpConfig -> redirect_use_orig_cache_key ;
 break ;
 case TS_CONFIG_HTTP_ATTACH_SERVER_SESSION_TO_CLIENT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> attach_server_session_to_client ;
 break ;
 case TS_CONFIG_HTTP_SAFE_REQUESTS_RETRYABLE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> safe_requests_retryable ;
 break ;
 case TS_CONFIG_HTTP_ORIGIN_MAX_CONNECTIONS_QUEUE : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> origin_max_connections_queue ;
 break ;
 case TS_CONFIG_WEBSOCKET_NO_ACTIVITY_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> websocket_inactive_timeout ;
 break ;
 case TS_CONFIG_WEBSOCKET_ACTIVE_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> websocket_active_timeout ;
 break ;
 case TS_CONFIG_HTTP_UNCACHEABLE_REQUESTS_BYPASS_PARENT : ret = & overridableHttpConfig -> uncacheable_requests_bypass_parent ;
 break ;
 case TS_CONFIG_HTTP_PARENT_PROXY_TOTAL_CONNECT_ATTEMPTS : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> parent_connect_attempts ;
 break ;
 case TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_IN : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> transaction_active_timeout_in ;
 break ;
 case TS_CONFIG_SRV_ENABLED : ret = & overridableHttpConfig -> srv_enabled ;
 break ;
 case TS_CONFIG_HTTP_FORWARD_CONNECT_METHOD : ret = & overridableHttpConfig -> forward_connect_method ;
 break ;
 case TS_CONFIG_SSL_CERT_FILENAME : typ = OVERRIDABLE_TYPE_STRING ;
 ret = & overridableHttpConfig -> client_cert_filename ;
 break ;
 case TS_CONFIG_SSL_CERT_FILEPATH : typ = OVERRIDABLE_TYPE_STRING ;
 ret = & overridableHttpConfig -> client_cert_filepath ;
 break ;
 case TS_CONFIG_PARENT_FAILURES_UPDATE_HOSTDB : ret = & overridableHttpConfig -> parent_failures_update_hostdb ;
 break ;
 case TS_CONFIG_SSL_CLIENT_VERIFY_SERVER : ret = & overridableHttpConfig -> ssl_client_verify_server ;
 break ;
 case TS_CONFIG_HTTP_PARENT_PROXY_FAIL_THRESHOLD : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> parent_fail_threshold ;
 break ;
 case TS_CONFIG_HTTP_PARENT_PROXY_RETRY_TIME : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> parent_retry_time ;
 break ;
 case TS_CONFIG_HTTP_PER_PARENT_CONNECT_ATTEMPTS : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> per_parent_connect_attempts ;
 break ;
 case TS_CONFIG_HTTP_PARENT_CONNECT_ATTEMPT_TIMEOUT : typ = OVERRIDABLE_TYPE_INT ;
 ret = & overridableHttpConfig -> parent_connect_timeout ;
 break ;
 case TS_CONFIG_HTTP_ALLOW_MULTI_RANGE : ret = & overridableHttpConfig -> allow_multi_range ;
 break ;
 case TS_CONFIG_NULL : case TS_CONFIG_LAST_ENTRY : typ = OVERRIDABLE_TYPE_NULL ;
 ret = nullptr ;
 break ;
 }
 * typep = typ ;
 return ret ;
 }