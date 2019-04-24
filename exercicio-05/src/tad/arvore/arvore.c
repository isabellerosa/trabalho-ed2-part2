#include "../arvore/arvore.h"

#include <stdio.h>
#include <stdlib.h>

void criaArvoreBinariaVazia(TipoArvore *arvore) {
	arvore = NULL;
}

int testaArvoreBinariaVazia(TipoArvore *arvore) {
	return (arvore == NULL);
}

void criaArvoreBinaria(TipoItem item, TipoArvore **arvore, TipoArvore *esquerda, TipoArvore *direita){
	(*arvore) = (TipoArvore *) malloc(sizeof(TipoArvore));
	(*arvore)->item = item;
	(*arvore)->esquerda = esquerda;
	(*arvore)->direita = direita;
}

TipoArvore * liberaArvoreBinaria(TipoArvore *arvore) {
	if (!testaArvoreBinariaVazia(arvore)) {
		liberaArvoreBinaria(arvore->esquerda);
		liberaArvoreBinaria(arvore->direita);
		free(arvore);
	}
	return NULL;
}

int pertenceArvoreBinaria(TipoArvore *arvore, TipoItem item) {
	if (testaArvoreBinariaVazia(arvore))
		return 0;
	else
		return arvore->item.chave == item.chave
				|| pertenceArvoreBinaria(arvore->esquerda, item)
				|| pertenceArvoreBinaria(arvore->direita, item);
}

void imprimeArvoreBinaria(TipoArvore *arvore, int l) {
	int i;
	if (!testaArvoreBinariaVazia(arvore)) {
		imprimeArvoreBinaria(arvore->direita, l + 1);
		for (i = 0; i < l; i++)
			printf(" ");
		printf("%i\n", arvore->item.chave);
		imprimeArvoreBinaria(arvore->esquerda, l + 1);
	}
}
