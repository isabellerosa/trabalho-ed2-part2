#ifndef LISTA_H_
#define LISTA_H_ "lista.h"

#include <stdlib.h>
#include <stdio.h>
#include "../node.h"

typedef struct _listaEnc{
	Item* first;
	Item* last;
	int numItens;
}List;

List* newList();
void insertAt(List* lst, void* element);
void addAtPos(List* lst, int pos, Item* new);
void* getAtPos(List* lst, int pos);
void* removeFromPos(List* lst, int pos);
void moveToPos(List* lst, int origin, int destiny);
int isListEmpty(List* lst);

#endif
