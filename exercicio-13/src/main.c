/**
 *Seja um percurso em uma árvore binária definido pelas seguintes
 *operações:
 *	 Ordem A
 *	 visitar a raiz;
 *	 percorrer a subárvore esquerda na ordem A;
 *	 percorrer a subárvore direita de na ordem B.
 *	 Ordem B
 *	 percorrer a subárvore esquerda na ordem B;
 *	 visitar a raiz;
 *	 percorrer a subárvore direita na ordem A
 */

#include <stdio.h>
#include <stdlib.h>

#include "asprintf.h"
#include "isa/arvore/tree.h"
#include "isa/pilha/stack.h"

void ordemA(Tree*);
void ordemB(Tree*);

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

void ordemA(Tree* arvore) {
	printf("%s ", (char*) arvore->content);
	if (arvore->left != NULL) {
		ordemA(arvore->left);

	}
	if (arvore->right != NULL) {
		ordemB(arvore->right);

	}
}

void ordemB(Tree* arvore) {
	if (arvore->left != NULL) {
		ordemB(arvore->left);

	}
	printf("%s ", (char*) arvore->content);

	if (arvore->right != NULL) {
		ordemA(arvore->right);

	}

}

int main(void) {
	Tree* arvore = arvoreQuestao();

	ordemA(arvore);
	return EXIT_SUCCESS;
}

