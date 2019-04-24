#ifndef LISTA_H_
#define LISTA_H_ "lista.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _item{
	void* info;
	struct _item* prox;
}Item;

typedef struct _listaEnc{
	Item* first;
	Item* last;
	int numItens;
}Lista;

Lista* newList();
Item* newItem(void* elemento);
void insertAt(Lista* lst, int pos, void* elemento);
void addAtPos(Lista* lst, int pos, Item* novo);
void* getAtPos(Lista* lst, int pos);
void* removeFromPos(Lista* lst, int pos);
void moveToPos(Lista* lst, int origin, int destiny);
int isEmpty(Lista* lst);

#endif
