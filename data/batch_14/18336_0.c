static inline void uprv_arrayCopy ( const UChar * src , int32_t srcStart , UChar * dst , int32_t dstStart , int32_t count ) {
 uprv_memcpy ( dst + dstStart , src + srcStart , ( size_t ) count * sizeof ( * src ) ) ;
 }