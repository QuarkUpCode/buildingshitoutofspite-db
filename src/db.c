#include <libpq-fe.h>

#include "../include/loadfile.h"


char* db_concat(char* a, char* b){
	int lena = 0;
	int lenb = 0;

	while(a[lena] != 0x00) lena++;
	while(b[lenb] != 0x00) lenb++;

	int lenc = lena + lenb + 1;
	char* c = malloc(lenc * sizeof(char));

	for(int i=0; i<lena; i++){
		c[i] = a[i];
	}
	for(int i=0; i<lenb; i++){
		c[lena + i] = b[i];
	}
	return c;
}

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


int create_account(PGconn* conn, char* username){
	PGresult* res;
	
	char* a = "INSERT INTO users (username, level, exp, gold)\n VALUES ('";
	char* b = username;
	char* c = db_concat(a, b);
	char* d = "', 0, 0, 0);";
	
	char* req = db_concat(c, d);
	free(c);
	res = PQexec(conn, req);
	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		fprintf(stderr, "db.c @ create_account : %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	free(req);

	return 0;
}