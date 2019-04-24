#include "list.h"

List* newList(){
	List* lst = (List*) malloc(sizeof(List));

	lst->first = NULL;
	lst->last = NULL;
	lst->numItens = 0;

	return lst;
}

void insertAt(List* lst, void* element){
	Item* item = newItem(element);
	addAtPos(lst, lst->numItens, item);
}

void addAtPos(List* lst, int pos, Item* new){
	if(pos == 0){
		new->prox = lst->first;
		lst->first = new;
	} else {
		int i;
		Item* aux = NULL;

		if(pos > lst->numItens || pos < 0) pos = lst->numItens;

		for(i = 0, aux = lst->first; i<pos; i++, aux = aux->prox){
			if(i == pos - 1){
				new->prox = aux->prox;
				aux->prox = new;
			}
		}
	}

	if(pos == lst->numItens) lst->last = new;

	lst->numItens++;
}

void* getAtPos(List* lst, int pos){
	int i;
	Item* aux;

	for(i = 0, aux = lst->first; i<=pos && aux!=NULL; i++, aux = aux->prox)
		if(i==pos) return aux->info;

	return NULL;
}

void* removeFromPos(List* lst, int pos){
	if(isListEmpty(lst)) return NULL; // testa List vazia
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

	void* element = aux->info;
	free(aux);

	return element;
}

void moveToPos(List* lst, int origin, int destiny){
	Item* aux = newItem(removeFromPos(lst, origin));
	addAtPos(lst, destiny, aux);
}


int isListEmpty(List* lst){
	if(lst->numItens > 0) return 0;
	return 1;
}
