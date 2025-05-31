#include <libpq-fe.h>

#include "../include/loadfile.h"


int create_tables(PGconn* conn){
	PGresult* res;

	char* create_tables = loadfile("src/sql/create_tables.sql");

	res = PQexec(conn, create_tables);
	// free(create_tables);
	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		fprintf(stderr, "db.c @ create_tables : %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}

	return 0;
}