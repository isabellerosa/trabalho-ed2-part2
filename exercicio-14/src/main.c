/**
14 - Apresente os resultados dos percursos em pré-ordem, ordem simétrica e
pós-ordem aplicados à árvore binária do Exercício 13.
 */

#include <stdio.h>
#include <stdlib.h>

#include "asprintf.h"
#include "isa/arvore/tree.h"
#include "isa/pilha/stack.h"


Tree* arvoreQuestao() {
	char *a, *b, *c, *d, *e, *f, *g, *h, *i;
	asprintf(&a, "%c", 'A');
	asprintf(&b, "%c",'B');
	asprintf(&c, "%c",'C');
	asprintf(&d, "%c",'D');
	asprintf(&e, "%c",'E');
	asprintf(&f, "%c",'F');
	asprintf(&g, "%c",'G');
	asprintf(&h, "%c",'H');
	asprintf(&i, "%c",'I');


	//folhas
	Tree *G, *H, *I, *F;
	G = newTree(g, NULL, NULL);
	H = newTree(h, NULL, NULL);
	I = newTree(i, NULL, NULL);
	F = newTree(f, NULL, NULL);

	//intermediarios
	Tree *B, *C, *D, *E;
	D = newTree(d, NULL, G);
	B = newTree(b, D, NULL);

	E = newTree(e, H, I);
	C = newTree(c, E, F);

	//raiz
	return newTree(a, B, C);
}

void percorreArvoreBinariaPreOrdem(Tree *arvore) {
	if (arvore != NULL) {
		printf("%s ", arvore->content);
		percorreArvoreBinariaPreOrdem(arvore->left);
		percorreArvoreBinariaPreOrdem(arvore->right);
	}
}

void percorreArvoreBinariaOrdemSimetrica(Tree *arvore) {
	if (arvore != NULL) {
		percorreArvoreBinariaOrdemSimetrica(arvore->left);
		printf("%s ", arvore->content);
		percorreArvoreBinariaOrdemSimetrica(arvore->right);
	}
}

void percorreArvoreBinariaPosOrdem(Tree *arvore) {
	if (arvore != NULL) {
		percorreArvoreBinariaPosOrdem(arvore->left);
		percorreArvoreBinariaPosOrdem(arvore->right);
		printf("%s ", arvore->content);
	}
}

int main(void) {
	Tree* arvore = arvoreQuestao();

	printf("== PRE ORDEM ==\n\n");
	percorreArvoreBinariaPreOrdem(arvore);

	printf("\n\n\n== ORDEM SIMETRICA ==\n\n");

	percorreArvoreBinariaOrdemSimetrica(arvore);

	printf("\n\n\n== POS ORDEM ==\n\n");
	percorreArvoreBinariaPosOrdem(arvore);
	return EXIT_SUCCESS;
}

