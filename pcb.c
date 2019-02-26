#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "pcb.h"


// public functions


struct PCB *makePCB(FILE *p){
	struct PCB *temp;
	temp = (struct PCB *) malloc(sizeof(struct PCB));
	temp->pc = p;
	return temp;
}

