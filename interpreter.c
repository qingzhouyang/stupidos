#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "shellmemory.h"
#include "shell.h"
#include "kernel.h"

int run(char *filename) {
	FILE *ptr;
	char buffer[1000], buf0[100], buf1[100], buf2[100],buf3[100];
	int result = 0;

	ptr = fopen(filename,"rt");
	if (ptr == NULL) return 4; // file not found

	fgets(buffer,999,ptr);
	while(!feof(ptr)) {
		if (strlen(buffer)>1) result = prompt(buffer);

		if (result == 99) break;
		fgets(buffer,999,ptr);
	}

	fclose(ptr);

	if (result == 99) return 99;

	return 0;
}

int exec(char *filename1,char *filename2,char *filename3){
	char buffer[1000];
	int result = 0;
	FILE *ptr;
	ptr= fopen(filename1,"rt");
	//in kernel.c
	myinit(ptr);


	//in kernel.c
	scheduler();

	return 0;
}

int interpreter(char buf0[], char buf1[], char buf2[], char buf3[]) {
	int result = 0; // no errors

	if (strcmp(buf0,"help")==0) {
		printf("Legal commands:\n");
		printf("help              display this help\n");
		printf("quit              exits the shell\n");
		printf("set VAR STRING    assign STRING to VAR\n");
		printf("print VAR         display contents of VAR\n");
		printf("run SCRIPT.TXT    interpret SCRIPT.TXT\n");
		printf("exec p1 p2 p3	  Executes concurent programs $ exec prog.txt prog2.txt\n");

		result = 0;
	}
	else if (strcmp(buf0,"quit")==0) {
		result = 99; // exit shell code
	}
	else if (strcmp(buf0,"set")==0) {
		if (strlen(buf1)<1 || strlen(buf2)<1) return 1; // set error

		add(strdup(buf1), strdup(buf2));
	}
	else if (strcmp(buf0,"print")==0) {
		if (strlen(buf1)<1) return 2; // print error

		printf("%s\n", get(buf1));
	}
	else if (strcmp(buf0,"run")==0) {
		if (strlen(buf1)<1) return 3; // run error

		result = run(buf1);
	}
	else if (strcmp(buf0,"exec")==0) {
		if (strlen(buf1)<1) return 5; // exec error

		result = exec(buf1,buf2,buf3);  // multiple programs
	}
	else {
		result = 98; // command does not exist
	}

	return result;
}

