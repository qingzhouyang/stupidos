#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "interpreter.h"
#include "shell.h"
#include "shellmemory.h"
#include "pcb.h"
#include "ram.h"
#include "kernel.h"


struct ReadyQuery *head, *tail,*temp;

int addToReady(struct PCB *p){
	head = NULL;
	tail = NULL;

	temp = (struct ReadyQuery *) malloc(sizeof(struct ReadyQuery));
		temp->pcb   = p;
		temp->next  = NULL;

		if (head == NULL)
			head = temp;

		if (tail == NULL) 
			tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}

}

int main(void) {
	char buffer[1000], buf0[100], buf1[100], buf2[100];
	int done = 0, result = 0;

	initShellMemory();

	printf("Kernel i.0 loaded!\n");
	printf("Welcome to the Qingzhou Yang shell!\n");
	printf("Version 2.0 Updated February 2019\n");

	while(!done) {

		printf("$ ");

		if (fgets(buffer,999, stdin) == NULL) {
			freopen("/dev/tty", "r", stdin);
			continue;
        }
		result = prompt(buffer);
        
		if (result == 99) done = 1;
	}

	printf("Good bye.\n");
	return 0;
}

int myinit(FILE *p){
 //  addToRam(FILE *p);
 //  pcbp = makePCB(FILE *p);
 //  addToReady(PCB *p) 
	addToRam(p);
	struct PCB *pcbp = makePCB(p);
	addToReady(pcbp); 
	}



//
//called after files are loaded, 
int scheduler(){




}

//void addToRam(FILE *p);