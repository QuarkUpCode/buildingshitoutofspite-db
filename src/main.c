#include <stdio.h>
#include <libpq-fe.h>


int main(){
	// printf("pissing myself rn\n");

	PGconn* conn = PQconnectdb("user=postgres dbname=h303");
	printf("main.c:9 @ main | conn = 0x%8x\n");

	// PQfinish(conn);

	return 0;
}
