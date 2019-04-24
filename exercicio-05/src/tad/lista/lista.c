#include "lista.h"

Item* newItem(void* elemento){
	Item* novo = (Item*) malloc(sizeof(Item));
	novo->info = elemento;
	novo->prox = NULL;

	return novo;
}

Lista* newList(){
	Lista* lst = (Lista*) malloc(sizeof(Lista));

	lst->first = NULL;
	lst->last = NULL;
	lst->numItens = 0;

	return lst;
}

void insertAt(Lista* lst, int pos, void* elemento){
	Item* item = newItem(elemento);
	addAtPos(lst, pos, item);
}

void addAtPos(Lista* lst, int pos, Item* novo){
	if(pos == 0){
		novo->prox = lst->first;
		lst->first = novo;
	} else {
		int i;
		Item* aux = NULL;

		if(pos > lst->numItens || pos < 0) pos = lst->numItens;

		for(i = 0, aux = lst->first; i<pos; i++, aux = aux->prox){
			if(i == pos - 1){
				novo->prox = aux->prox;
				aux->prox = novo;
			}
		}
	}

	if(pos == lst->numItens) lst->last = novo;

	lst->numItens++;
}

void* getAtPos(Lista* lst, int pos){
	int i;
	Item* aux;

	for(i = 0, aux = lst->first; i<=pos && aux!=NULL; i++, aux = aux->prox)
		if(i==pos) return aux->info;

	return NULL;
}

void* removeFromPos(Lista* lst, int pos){
	if(isEmpty(lst)) return NULL; // testa lista vazia
	if(pos > lst->numItens || pos < 0) return NULL;

	int i;
	Item* aux;
	Item* ant;

	if(pos == 0){
        aux = lst->first;
        lst->first = aux->prox;
        lst->numItens--;
        return aux->info;
	}
	for(i = 0, aux = lst->first; i<pos; i++, aux = aux->prox){
		if(i == pos - 1){
			ant = aux;
			//aux = aux->prox;
			//break;
		}
	}
	ant->prox = aux->prox;
	if(pos == 0) lst->first = aux->prox;
	if(pos == lst->numItens) lst->last = ant;

	lst->numItens--;
	return aux->info;
}

void moveToPos(Lista* lst, int origin, int destiny){
	Item* aux = newItem(removeFromPos(lst, origin));
	addAtPos(lst, destiny, aux);
}


int isEmpty(Lista* lst){
	if(lst->numItens > 0) return 0;
	return 1;
}
