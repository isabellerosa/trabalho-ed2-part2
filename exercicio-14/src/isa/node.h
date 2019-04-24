#ifndef NODE_H_
#define NODE_H_ "node.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _item{
	void* info;
	struct _item* prox;
}Item;

Item* newItem(void* element);

#endif
