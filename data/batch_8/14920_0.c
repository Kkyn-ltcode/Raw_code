static void client_query ( ) {
 int rc ;
 myheader ( "client_query" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1(" "id int primary key auto_increment, " "name varchar(20))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1(id int, name varchar(20))" ) ;
 myquery_r ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1(name) VALUES('mysql')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1(name) VALUES('monty')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1(name) VALUES('venu')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1(name) VALUES('deleted')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1(name) VALUES('deleted')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "UPDATE t1 SET name= 'updated' " "WHERE name= 'deleted'" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "UPDATE t1 SET id= 3 WHERE name= 'updated'" ) ;
 myquery_r ( rc ) ;
 myquery ( mysql_query ( mysql , "drop table t1" ) ) ;
 }