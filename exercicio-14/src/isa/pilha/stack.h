#ifndef PILHA_H_
#define PILHA_H_ "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include "../node.h"

typedef struct {
	Item *top;
	Item *bottom;
} Stack;

Stack* newStack();
int isStackEmpty(Stack*);
void* pop(Stack*);
void push(Stack*, void*);

#endif
