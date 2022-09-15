static void dumpCreateDB ( PGconn * conn ) {
 PQExpBuffer buf = createPQExpBuffer ( ) ;
 char * default_encoding = NULL ;
 char * default_collate = NULL ;
 char * default_ctype = NULL ;
 PGresult * res ;
 int i ;
 fprintf ( OPF , "--\n-- Database creation\n--\n\n" ) ;
 if ( server_version >= 80400 ) res = executeQuery ( conn , "SELECT pg_encoding_to_char(encoding), " "datcollate, datctype " "FROM pg_database " "WHERE datname = 'template0'" ) ;
 else if ( server_version >= 70100 ) res = executeQuery ( conn , "SELECT pg_encoding_to_char(encoding), " "null::text AS datcollate, null::text AS datctype " "FROM pg_database " "WHERE datname = 'template0'" ) ;
 else res = executeQuery ( conn , "SELECT pg_encoding_to_char(encoding), " "null::text AS datcollate, null::text AS datctype " "FROM pg_database " "WHERE datname = 'template1'" ) ;
 if ( PQntuples ( res ) > 0 ) {
 if ( ! PQgetisnull ( res , 0 , 0 ) ) default_encoding = pg_strdup ( PQgetvalue ( res , 0 , 0 ) ) ;
 if ( ! PQgetisnull ( res , 0 , 1 ) ) default_collate = pg_strdup ( PQgetvalue ( res , 0 , 1 ) ) ;
 if ( ! PQgetisnull ( res , 0 , 2 ) ) default_ctype = pg_strdup ( PQgetvalue ( res , 0 , 2 ) ) ;
 }
 PQclear ( res ) ;
 if ( server_version >= 90600 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(rolname, (select rolname from pg_authid where oid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "datcollate, datctype, datfrozenxid, datminmxid, " "datistemplate, " "(SELECT pg_catalog.array_agg(acl) FROM (SELECT pg_catalog.unnest(coalesce(datacl,pg_catalog.acldefault('d',datdba))) AS acl " "EXCEPT SELECT pg_catalog.unnest(pg_catalog.acldefault('d',datdba))) as foo)" "AS datacl," "(SELECT pg_catalog.array_agg(acl) FROM (SELECT pg_catalog.unnest(pg_catalog.acldefault('d',datdba)) AS acl " "EXCEPT SELECT pg_catalog.unnest(coalesce(datacl,pg_catalog.acldefault('d',datdba)))) as foo)" "AS rdatacl," "datconnlimit, " "(SELECT spcname FROM pg_tablespace t WHERE t.oid = d.dattablespace) AS dattablespace " "FROM pg_database d LEFT JOIN pg_authid u ON (datdba = u.oid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 90300 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(rolname, (select rolname from pg_authid where oid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "datcollate, datctype, datfrozenxid, datminmxid, " "datistemplate, datacl, '' as rdatacl, datconnlimit, " "(SELECT spcname FROM pg_tablespace t WHERE t.oid = d.dattablespace) AS dattablespace " "FROM pg_database d LEFT JOIN pg_authid u ON (datdba = u.oid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 80400 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(rolname, (select rolname from pg_authid where oid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "datcollate, datctype, datfrozenxid, 0 AS datminmxid, " "datistemplate, datacl, '' as rdatacl, datconnlimit, " "(SELECT spcname FROM pg_tablespace t WHERE t.oid = d.dattablespace) AS dattablespace " "FROM pg_database d LEFT JOIN pg_authid u ON (datdba = u.oid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 80100 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(rolname, (select rolname from pg_authid where oid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "null::text AS datcollate, null::text AS datctype, datfrozenxid, 0 AS datminmxid, " "datistemplate, datacl, '' as rdatacl, datconnlimit, " "(SELECT spcname FROM pg_tablespace t WHERE t.oid = d.dattablespace) AS dattablespace " "FROM pg_database d LEFT JOIN pg_authid u ON (datdba = u.oid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 80000 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(usename, (select usename from pg_shadow where usesysid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "null::text AS datcollate, null::text AS datctype, datfrozenxid, 0 AS datminmxid, " "datistemplate, datacl, '' as rdatacl, -1 as datconnlimit, " "(SELECT spcname FROM pg_tablespace t WHERE t.oid = d.dattablespace) AS dattablespace " "FROM pg_database d LEFT JOIN pg_shadow u ON (datdba = usesysid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 70300 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(usename, (select usename from pg_shadow where usesysid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "null::text AS datcollate, null::text AS datctype, datfrozenxid, 0 AS datminmxid, " "datistemplate, datacl, '' as rdatacl, -1 as datconnlimit, " "'pg_default' AS dattablespace " "FROM pg_database d LEFT JOIN pg_shadow u ON (datdba = usesysid) " "WHERE datallowconn ORDER BY 1" ) ;
 else if ( server_version >= 70100 ) res = executeQuery ( conn , "SELECT datname, " "coalesce(" "(select usename from pg_shadow where usesysid=datdba), " "(select usename from pg_shadow where usesysid=(select datdba from pg_database where datname='template0'))), " "pg_encoding_to_char(d.encoding), " "null::text AS datcollate, null::text AS datctype, 0 AS datfrozenxid, 0 AS datminmxid, " "datistemplate, '' as datacl, '' as rdatacl, -1 as datconnlimit, " "'pg_default' AS dattablespace " "FROM pg_database d " "WHERE datallowconn ORDER BY 1" ) ;
 else {
 res = executeQuery ( conn , "SELECT datname, " "(select usename from pg_shadow where usesysid=datdba), " "pg_encoding_to_char(d.encoding), " "null::text AS datcollate, null::text AS datctype, 0 AS datfrozenxid, 0 AS datminmxid, " "'f' as datistemplate, " "'' as datacl, '' as rdatacl, -1 as datconnlimit, " "'pg_default' AS dattablespace " "FROM pg_database d " "ORDER BY 1" ) ;
 }
 for ( i = 0 ;
 i < PQntuples ( res ) ;
 i ++ ) {
 char * dbname = PQgetvalue ( res , i , 0 ) ;
 char * dbowner = PQgetvalue ( res , i , 1 ) ;
 char * dbencoding = PQgetvalue ( res , i , 2 ) ;
 char * dbcollate = PQgetvalue ( res , i , 3 ) ;
 char * dbctype = PQgetvalue ( res , i , 4 ) ;
 uint32 dbfrozenxid = atooid ( PQgetvalue ( res , i , 5 ) ) ;
 uint32 dbminmxid = atooid ( PQgetvalue ( res , i , 6 ) ) ;
 char * dbistemplate = PQgetvalue ( res , i , 7 ) ;
 char * dbacl = PQgetvalue ( res , i , 8 ) ;
 char * rdbacl = PQgetvalue ( res , i , 9 ) ;
 char * dbconnlimit = PQgetvalue ( res , i , 10 ) ;
 char * dbtablespace = PQgetvalue ( res , i , 11 ) ;
 char * fdbname ;
 fdbname = pg_strdup ( fmtId ( dbname ) ) ;
 resetPQExpBuffer ( buf ) ;
 if ( strcmp ( dbname , "template1" ) != 0 && strcmp ( dbname , "postgres" ) != 0 ) {
 appendPQExpBuffer ( buf , "CREATE DATABASE %s" , fdbname ) ;
 appendPQExpBufferStr ( buf , " WITH TEMPLATE = template0" ) ;
 if ( strlen ( dbowner ) != 0 ) appendPQExpBuffer ( buf , " OWNER = %s" , fmtId ( dbowner ) ) ;
 if ( default_encoding && strcmp ( dbencoding , default_encoding ) != 0 ) {
 appendPQExpBufferStr ( buf , " ENCODING = " ) ;
 appendStringLiteralConn ( buf , dbencoding , conn ) ;
 }
 if ( default_collate && strcmp ( dbcollate , default_collate ) != 0 ) {
 appendPQExpBufferStr ( buf , " LC_COLLATE = " ) ;
 appendStringLiteralConn ( buf , dbcollate , conn ) ;
 }
 if ( default_ctype && strcmp ( dbctype , default_ctype ) != 0 ) {
 appendPQExpBufferStr ( buf , " LC_CTYPE = " ) ;
 appendStringLiteralConn ( buf , dbctype , conn ) ;
 }
 if ( strcmp ( dbtablespace , "pg_default" ) != 0 && ! no_tablespaces ) appendPQExpBuffer ( buf , " TABLESPACE = %s" , fmtId ( dbtablespace ) ) ;
 if ( strcmp ( dbistemplate , "t" ) == 0 ) appendPQExpBuffer ( buf , " IS_TEMPLATE = true" ) ;
 if ( strcmp ( dbconnlimit , "-1" ) != 0 ) appendPQExpBuffer ( buf , " CONNECTION LIMIT = %s" , dbconnlimit ) ;
 appendPQExpBufferStr ( buf , ";
\n" ) ;
 }
 else if ( strcmp ( dbtablespace , "pg_default" ) != 0 && ! no_tablespaces ) {
 if ( strcmp ( dbname , "postgres" ) == 0 ) appendPQExpBuffer ( buf , "\\connect template1\n" ) ;
 else appendPQExpBuffer ( buf , "\\connect postgres\n" ) ;
 appendPQExpBuffer ( buf , "ALTER DATABASE %s SET TABLESPACE %s;
\n" , fdbname , fmtId ( dbtablespace ) ) ;
 appendPQExpBuffer ( buf , "\\connect %s\n" , fdbname ) ;
 }
 if ( binary_upgrade ) {
 appendPQExpBufferStr ( buf , "-- For binary upgrade, set datfrozenxid and datminmxid.\n" ) ;
 appendPQExpBuffer ( buf , "UPDATE pg_catalog.pg_database " "SET datfrozenxid = '%u', datminmxid = '%u' " "WHERE datname = " , dbfrozenxid , dbminmxid ) ;
 appendStringLiteralConn ( buf , dbname , conn ) ;
 appendPQExpBufferStr ( buf , ";
\n" ) ;
 }
 if ( ! skip_acls && ! buildACLCommands ( fdbname , NULL , "DATABASE" , dbacl , rdbacl , dbowner , "" , server_version , buf ) ) {
 fprintf ( stderr , _ ( "%s: could not parse ACL list (%s) for database \"%s\"\n" ) , progname , dbacl , fdbname ) ;
 PQfinish ( conn ) ;
 exit_nicely ( 1 ) ;
 }
 fprintf ( OPF , "%s" , buf -> data ) ;
 if ( server_version >= 70300 ) dumpDatabaseConfig ( conn , dbname ) ;
 free ( fdbname ) ;
 }
 if ( default_encoding ) free ( default_encoding ) ;
 if ( default_collate ) free ( default_collate ) ;
 if ( default_ctype ) free ( default_ctype ) ;
 PQclear ( res ) ;
 destroyPQExpBuffer ( buf ) ;
 fprintf ( OPF , "\n\n" ) ;
 }