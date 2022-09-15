static ArchiveHandle * _allocAH ( const char * FileSpec , const ArchiveFormat fmt , const int compression , ArchiveMode mode , SetupWorkerPtr setupWorkerPtr ) {
 ArchiveHandle * AH ;
 # if 0 write_msg ( modulename , "allocating AH for %s, format %d\n" , FileSpec , fmt ) ;
 # endif AH = ( ArchiveHandle * ) pg_malloc0 ( sizeof ( ArchiveHandle ) ) ;
 AH -> vmaj = K_VERS_MAJOR ;
 AH -> vmin = K_VERS_MINOR ;
 AH -> vrev = K_VERS_REV ;
 AH -> version = ( ( AH -> vmaj * 256 + AH -> vmin ) * 256 + AH -> vrev ) * 256 + 0 ;
 AH -> public . encoding = 0 ;
 AH -> public . std_strings = false ;
 AH -> public . exit_on_error = true ;
 AH -> public . n_errors = 0 ;
 AH -> archiveDumpVersion = PG_VERSION ;
 AH -> createDate = time ( NULL ) ;
 AH -> intSize = sizeof ( int ) ;
 AH -> offSize = sizeof ( pgoff_t ) ;
 if ( FileSpec ) {
 AH -> fSpec = pg_strdup ( FileSpec ) ;
 }
 else AH -> fSpec = NULL ;
 AH -> currUser = NULL ;
 AH -> currSchema = NULL ;
 AH -> currTablespace = NULL ;
 AH -> currWithOids = - 1 ;
 AH -> toc = ( TocEntry * ) pg_malloc0 ( sizeof ( TocEntry ) ) ;
 AH -> toc -> next = AH -> toc ;
 AH -> toc -> prev = AH -> toc ;
 AH -> mode = mode ;
 AH -> compression = compression ;
 memset ( & ( AH -> sqlparse ) , 0 , sizeof ( AH -> sqlparse ) ) ;
 AH -> gzOut = 0 ;
 AH -> OF = stdout ;
 # ifdef WIN32 if ( fmt != archNull && ( AH -> fSpec == NULL || strcmp ( AH -> fSpec , "" ) == 0 ) ) {
 if ( mode == archModeWrite ) setmode ( fileno ( stdout ) , O_BINARY ) ;
 else setmode ( fileno ( stdin ) , O_BINARY ) ;
 }
 # endif AH -> SetupWorkerPtr = setupWorkerPtr ;
 if ( fmt == archUnknown ) AH -> format = _discoverArchiveFormat ( AH ) ;
 else AH -> format = fmt ;
 AH -> promptPassword = TRI_DEFAULT ;
 switch ( AH -> format ) {
 case archCustom : InitArchiveFmt_Custom ( AH ) ;
 break ;
 case archNull : InitArchiveFmt_Null ( AH ) ;
 break ;
 case archDirectory : InitArchiveFmt_Directory ( AH ) ;
 break ;
 case archTar : InitArchiveFmt_Tar ( AH ) ;
 break ;
 default : exit_horribly ( modulename , "unrecognized file format \"%d\"\n" , fmt ) ;
 }
 return AH ;
 }