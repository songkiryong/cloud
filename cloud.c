#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option_mode() {
	int opt;


	printf("=====Select mode=====\n");
	printf("1.easy\n");
	printf("2.normal\n");
	printf("3.hard\n");
	printf("입력 : ");

	scanf("%d", &opt);
	return opt;
}


int option_language() {
	int opt;

	printf("====Select language====\n");
	printf("1. C\n");
	printf("2. Python\n");
	printf("3. Java\n");
	printf("입력 : ");
	scanf("%d",&opt);

	return opt;
}

void read_file(char* file) {
	char buffer[BUFSIZ];
	int size;
	int count;
	

	FILE *fp=fopen(file,"r");
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	fseek(fp,0,SEEK_SET);
	fread(buffer,size,1,fp);
	printf("%s",buffer);
	fclose(fp);
}


void c() {

	int opt;
        opt=option_mode();
        char file[BUFSIZ];
	switch(opt) {
		case 1:
			//easy file open
			strcpy(file,"c_easy.txt");
			read_file(file);
		break;
		case 2:
			//normal file open
		break;
		case 3:
			//hard file open
		break;

		
	}
      
}

void java() {

	int opt;
        opt=option_mode();

	switch(opt) {
		case 1:
			//easy file open
		break;
		case 2:
			//normal file open
		break;
		case 3:
			//hard file open
		break;
	}
}

void python() {

	int opt;
        opt=option_mode();

	switch(opt) {
		case 1:
			//easy file open
		break;
		case 2:
			//normal file open
		break;
		case 3:
			//hard file open
		break;
	}
}

int main(void) {
	int opt;
	
	opt=option_language();

	switch(opt) {
		case 1:
		c();
		break;

		case 2:
		java();
		break;

		case 3:
		python();
		break;
	}
}


