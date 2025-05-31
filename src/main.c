#include <stdio.h>
#include <libpq-fe.h>

#include "../include/loadfile.h"
#include "../include/db.h"



int main(){
	// printf("pissing myself rn\n");

	PGconn* conn = PQconnectdb("host=localhost dbname=h303 user=postgres password=immentallystable");
	printf("main.c:9 @ main | conn = 0x%8x\n");
	if(PQstatus(conn) == CONNECTION_BAD){
		fprintf(stderr, "main.c:11 @ main | Connection failed : %s\n", PQerrorMessage(conn));
		PQfinish(conn);
	}

	int ver = PQserverVersion(conn);

	
	int ret;
	if((ret = create_tables(conn)) != 0) exit(ret);

	// PGresult* res;

	// char* create_tables = loadfile("src/sql/create_tables.sql");

	// res = PQexec(conn, create_tables);
	// // free(create_tables);
	// if(PQresultStatus(res) != PGRES_COMMAND_OK){
	// 	printf("NUh huh : %s\n", PQerrorMessage(conn));
	// 	PQfinish(conn);
	// 	exit(1);
	// }


	PQfinish(conn);

	return 0;
}
