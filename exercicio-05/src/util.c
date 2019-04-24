#include "util.h"
#include <stdio.h>
#include <stdlib.h>

TipoItem criaItem() {
	TipoItem item;
	item.chave = rand() % 100;
	return item;
}

TipoArvore* criaNoArvore(){
	TipoArvore* no = (TipoArvore*) malloc(sizeof(TipoArvore));
	no->item = criaItem();
	no->direita = NULL;
	no->esquerda = NULL;

	return no;
}
