#ifndef TREE_ARVORE_H_
#define TREE_ARVORE_H_

#include "../node.h"

typedef struct arvore {
	TipoItem item;
	struct arvore *esquerda;
	struct arvore *direita;
} TipoArvore; //tipo das células com os itens da árvore binária


void criaArvoreBinariaVazia(TipoArvore*);
int testaArvoreBinariaVazia(TipoArvore*);
void criaArvoreBinaria(TipoItem, TipoArvore**, TipoArvore*, TipoArvore*);
TipoArvore* liberaArvoreBinaria(TipoArvore*);
int pertenceArvoreBinaria(TipoArvore*, TipoItem);
void imprimeArvoreBinaria(TipoArvore*, int);

void percorreArvoreBinariaPreOrdem(TipoArvore*);
void percorreArvoreBinariaOrdemSimetrica(TipoArvore*);
void percorreArvoreBinariaPosOrdem(TipoArvore*);
void percorreArvoreBinariaProfundidade(TipoArvore*);
void percorreArvoreBinariaLargura(TipoArvore*);

#endif  //TREE_ARVORE_H_
