static const char * fieldtype2str ( enum enum_field_types type ) {
 switch ( type ) {
 case MYSQL_TYPE_BIT : return "BIT" ;
 case MYSQL_TYPE_BLOB : return "BLOB" ;
 case MYSQL_TYPE_DATE : return "DATE" ;
 case MYSQL_TYPE_DATETIME : return "DATETIME" ;
 case MYSQL_TYPE_NEWDECIMAL : return "NEWDECIMAL" ;
 case MYSQL_TYPE_DECIMAL : return "DECIMAL" ;
 case MYSQL_TYPE_DOUBLE : return "DOUBLE" ;
 case MYSQL_TYPE_ENUM : return "ENUM" ;
 case MYSQL_TYPE_FLOAT : return "FLOAT" ;
 case MYSQL_TYPE_GEOMETRY : return "GEOMETRY" ;
 case MYSQL_TYPE_INT24 : return "INT24" ;
 case MYSQL_TYPE_LONG : return "LONG" ;
 case MYSQL_TYPE_LONGLONG : return "LONGLONG" ;
 case MYSQL_TYPE_LONG_BLOB : return "LONG_BLOB" ;
 case MYSQL_TYPE_MEDIUM_BLOB : return "MEDIUM_BLOB" ;
 case MYSQL_TYPE_NEWDATE : return "NEWDATE" ;
 case MYSQL_TYPE_NULL : return "NULL" ;
 case MYSQL_TYPE_SET : return "SET" ;
 case MYSQL_TYPE_SHORT : return "SHORT" ;
 case MYSQL_TYPE_STRING : return "STRING" ;
 case MYSQL_TYPE_TIME : return "TIME" ;
 case MYSQL_TYPE_TIMESTAMP : return "TIMESTAMP" ;
 case MYSQL_TYPE_TINY : return "TINY" ;
 case MYSQL_TYPE_TINY_BLOB : return "TINY_BLOB" ;
 case MYSQL_TYPE_VAR_STRING : return "VAR_STRING" ;
 case MYSQL_TYPE_YEAR : return "YEAR" ;
 default : return "?-unknown-?" ;
 }
 }