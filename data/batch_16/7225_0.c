static void help ( void ) {
 printf ( _ ( "%s extracts a PostgreSQL database cluster into an SQL script file.\n\n" ) , progname ) ;
 printf ( _ ( "Usage:\n" ) ) ;
 printf ( _ ( " %s [OPTION]...\n" ) , progname ) ;
 printf ( _ ( "\nGeneral options:\n" ) ) ;
 printf ( _ ( " -f, --file=FILENAME output file name\n" ) ) ;
 printf ( _ ( " -V, --version output version information, then exit\n" ) ) ;
 printf ( _ ( " --lock-wait-timeout=TIMEOUT fail after waiting TIMEOUT for a table lock\n" ) ) ;
 printf ( _ ( " -?, --help show this help, then exit\n" ) ) ;
 printf ( _ ( "\nOptions controlling the output content:\n" ) ) ;
 printf ( _ ( " -a, --data-only dump only the data, not the schema\n" ) ) ;
 printf ( _ ( " -c, --clean clean (drop) databases before recreating\n" ) ) ;
 printf ( _ ( " -g, --globals-only dump only global objects, no databases\n" ) ) ;
 printf ( _ ( " -o, --oids include OIDs in dump\n" ) ) ;
 printf ( _ ( " -O, --no-owner skip restoration of object ownership\n" ) ) ;
 printf ( _ ( " -r, --roles-only dump only roles, no databases or tablespaces\n" ) ) ;
 printf ( _ ( " -s, --schema-only dump only the schema, no data\n" ) ) ;
 printf ( _ ( " -S, --superuser=NAME superuser user name to use in the dump\n" ) ) ;
 printf ( _ ( " -t, --tablespaces-only dump only tablespaces, no databases or roles\n" ) ) ;
 printf ( _ ( " -x, --no-privileges do not dump privileges (grant/revoke)\n" ) ) ;
 printf ( _ ( " --binary-upgrade for use by upgrade utilities only\n" ) ) ;
 printf ( _ ( " --column-inserts dump data as INSERT commands with column names\n" ) ) ;
 printf ( _ ( " --disable-dollar-quoting disable dollar quoting, use SQL standard quoting\n" ) ) ;
 printf ( _ ( " --disable-triggers disable triggers during data-only restore\n" ) ) ;
 printf ( _ ( " --if-exists use IF EXISTS when dropping objects\n" ) ) ;
 printf ( _ ( " --inserts dump data as INSERT commands, rather than COPY\n" ) ) ;
 printf ( _ ( " --no-security-labels do not dump security label assignments\n" ) ) ;
 printf ( _ ( " --no-tablespaces do not dump tablespace assignments\n" ) ) ;
 printf ( _ ( " --no-unlogged-table-data do not dump unlogged table data\n" ) ) ;
 printf ( _ ( " --quote-all-identifiers quote all identifiers, even if not key words\n" ) ) ;
 printf ( _ ( " --use-set-session-authorization\n" " use SET SESSION AUTHORIZATION commands instead of\n" " ALTER OWNER commands to set ownership\n" ) ) ;
 printf ( _ ( "\nConnection options:\n" ) ) ;
 printf ( _ ( " -d, --dbname=CONNSTR connect using connection string\n" ) ) ;
 printf ( _ ( " -h, --host=HOSTNAME database server host or socket directory\n" ) ) ;
 printf ( _ ( " -l, --database=DBNAME alternative default database\n" ) ) ;
 printf ( _ ( " -p, --port=PORT database server port number\n" ) ) ;
 printf ( _ ( " -U, --username=NAME connect as specified database user\n" ) ) ;
 printf ( _ ( " -w, --no-password never prompt for password\n" ) ) ;
 printf ( _ ( " -W, --password force password prompt (should happen automatically)\n" ) ) ;
 printf ( _ ( " --role=ROLENAME do SET ROLE before dump\n" ) ) ;
 printf ( _ ( "\nIf -f/--file is not used, then the SQL script will be written to the standard\n" "output.\n\n" ) ) ;
 printf ( _ ( "Report bugs to <pgsql-bugs@postgresql.org>.\n" ) ) ;
 }