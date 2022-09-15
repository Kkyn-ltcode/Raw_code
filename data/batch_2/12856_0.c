RegProcedure get_oprjoin ( Oid opno ) {
 HeapTuple tp ;
 tp = SearchSysCache1 ( OPEROID , ObjectIdGetDatum ( opno ) ) ;
 if ( HeapTupleIsValid ( tp ) ) {
 Form_pg_operator optup = ( Form_pg_operator ) GETSTRUCT ( tp ) ;
 RegProcedure result ;
 result = optup -> oprjoin ;
 ReleaseSysCache ( tp ) ;
 return result ;
 }
 else return ( RegProcedure ) InvalidOid ;
 }