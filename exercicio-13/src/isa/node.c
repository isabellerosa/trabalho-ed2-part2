#include "node.h"

Item* newItem(void* element){
	Item* new = (Item*) malloc(sizeof(Item));
	new->info = element;
	new->prox = NULL;

	return new;
}
