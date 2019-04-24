#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "tad/lista/lista.h"
#include "tad/arvore/arvore.h"

typedef struct {
	int levels;
	Lista *nodes_matched;
} TreeSearchResult;

typedef struct {
	void *node;
	int lvl;
} TreeNodeResult;

TreeNodeResult* createResultNode(void*, int);
void find(TipoArvore*, TipoItem, int, TreeSearchResult*);
int calculaAlturaDoNo(TipoArvore*, TipoItem);

#endif /* MAIN_H_ */
