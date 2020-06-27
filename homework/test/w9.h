#ifndef _W9_H_ 
#define _W9_H_
#endif

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct Reg{ 
	int data;
	struct Reg *prev,*next;
}tReg;


typedef struct RegHead{
	int counts;
	tReg *front,*rear;
}tRegHead;


int ReSetLen(tRegHead*);
void insert(tRegHead*);
void printList(tRegHead*);
void randomExtend(tRegHead*);
void Rem(tRegHead*,int);
bool isEmpty(tRegHead*);
void Bsort(tRegHead*);
