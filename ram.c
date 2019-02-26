#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//
FILE *ram[10]; 

void addToRam(FILE *p){
	int i=0;
	for(i=0;i<10;i++){
		if (ram[i]==NULL) {
			ram[i] = p;
			break;
		}
	}
}