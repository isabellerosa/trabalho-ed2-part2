#ifndef NODE_H_
#define NODE_H_ "node.h"

typedef struct {
	int chave;
} TipoItem;

typedef struct celula {
	TipoItem item;
	struct celula *proximo;
} TipoCelula;

#endif
