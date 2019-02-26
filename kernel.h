// public functions
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "pcb.h"
//ready queue
struct ReadyQuery {
	struct PCB *pcb;
	struct ReadyQuery *next;
};

int myinit(FILE *p);
int prompt(char buffer[]);
int scheduler();

