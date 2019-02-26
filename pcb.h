// pcb structure type
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct PCB {
	FILE *pc; //program counter, pointer to the file current line
};

// public functions

struct PCB *makePCB(FILE *p); 
void initReadyQueue();

