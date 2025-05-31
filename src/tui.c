#include <stdio.h>

#include "../include/loadfile.h"
#include "../include/db.h"


#define username_maxlenght 128


int tui_register_login(void* conn){

	getchar();
	
	char quit = 0;
	char input;

	char* intro = loadfile("src/dialogues/register_login.txt");
	printf(intro);
	
	while(!quit){
		
		input = getchar();
		
		switch(input){
			case '1':
				getchar();
				char username[username_maxlenght] = {0x00};
				int i=0;
				char done = 0;
				while(!done){
					input = getchar();
					switch(input){
						case '\n':
							done = 1;
							break;
						default:
							username[i] = input;
							i++;
							break;
					}
					if(i >= username_maxlenght) done = 1;
				}
				
				create_account(conn, username);
				quit = 1;
				break;
			case 'r':
			case '0':
				quit = 1;
				break;
			default:
				break;
		}	
	}


	free(intro);
}

int tui_main(void* conn){

	char quit = 0;
	char input;

	char* main_menu = loadfile("src/dialogues/main_menu.txt");

	while(!quit){


		printf(main_menu);
		
		
		
		input = getchar();
		switch(input){

			case 'q':
				quit = 1;
				break;
			
			case '1':
				tui_register_login(conn);
				break;


			default:
				break;
		}

	}
}