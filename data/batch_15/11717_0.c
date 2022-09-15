TSReturnCode TSMimeHdrFieldCreate ( TSMBuffer bufp , TSMLoc mh_mloc , TSMLoc * locp ) {
 sdk_assert ( sdk_sanity_check_mbuffer ( bufp ) == TS_SUCCESS ) ;
 sdk_assert ( ( sdk_sanity_check_mime_hdr_handle ( mh_mloc ) == TS_SUCCESS ) || ( sdk_sanity_check_http_hdr_handle ( mh_mloc ) == TS_SUCCESS ) ) ;
 sdk_assert ( sdk_sanity_check_null_ptr ( ( void * ) locp ) == TS_SUCCESS ) ;
 if ( ! isWriteable ( bufp ) ) {
 return TS_ERROR ;
 }
 MIMEHdrImpl * mh = _hdr_mloc_to_mime_hdr_impl ( mh_mloc ) ;
 HdrHeap * heap = ( HdrHeap * ) ( ( ( HdrHeapSDKHandle * ) bufp ) -> m_heap ) ;
 MIMEFieldSDKHandle * h = sdk_alloc_field_handle ( bufp , mh ) ;
 h -> field_ptr = mime_field_create ( heap , mh ) ;
 * locp = reinterpret_cast < TSMLoc > ( h ) ;
 return TS_SUCCESS ;
 }