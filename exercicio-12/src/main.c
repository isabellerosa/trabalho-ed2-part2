/**
 * 12 - Dada uma árvore binária que representa uma expressão aritmética
 * (considerando-se apenas operações binárias), gerar a mesma expressão em
 * notação completamente parentizada. Sugestão: utilizar o percurso em ordem
 * simétrica.
 */

#include <stdio.h>
#include <stdlib.h>

#include "isa/arvore/tree.h"
#include "isa/pilha/stack.h"

#define ABRE_PARENTESES "("
#define FECHA_PARENTESES ")"

int noFolha(Tree* arvore) {
	return (arvore->left == NULL && arvore->right == NULL);
}

void montaEquacaoParentizada(Tree* arvore, Stack** pilha) {

	if ((*pilha) == NULL) {
		(*pilha) = newStack();
	}

	if (noFolha(arvore)) {
		push((*pilha), arvore->content);
	} else {
		push((*pilha), &FECHA_PARENTESES);
		montaEquacaoParentizada(arvore->right, pilha);
		push((*pilha), arvore->content);
		montaEquacaoParentizada(arvore->left, pilha);
		push((*pilha), &ABRE_PARENTESES);
	}



}

void printStack(Stack* pilha){
	while(!isStackEmpty(pilha)){
		printf("%s", pop(pilha));
	}
}

int main(void) {

	// EQUACOES DO EXERCICIO
	// Nota: para funcionar, tem que haver espacamento entre cada operador
	char str1[] = "( ( a + b ) * ( c + d ) / e ) - ( ( f + g ) * h )";
	char str2[] = "a - ( b / c ) * ( d + e ) - f";

	// CONVERTE EQUACOES PARA NOTACAO POLONESA E PASSA PARA UMA PILHA
	Stack* pilha1 = strToStk(infixaParaPrefixa(str1));
	Stack* pilha2 = strToStk(infixaParaPrefixa(str2));

	// TRANSFORMA PRIMEIRA EQUACAO EM ARVORE
	Tree* arvore1 = NULL;
	montaArvorePrefixa(&arvore1, pilha1);

	//TRANSFORMA SEGUNDA EQUACAO EM ARVORE
	Tree* arvore2 = NULL;
	montaArvorePrefixa(&arvore2, pilha2);

	//--

	Stack* pilhaP1 = NULL;
	Stack* pilhaP2 = NULL;

	montaEquacaoParentizada(arvore1, &pilhaP1);
	montaEquacaoParentizada(arvore2, &pilhaP2);

	printf("Equacao: ((a+b)*(c+d)/e)-((f+g)*h) \nTotalmente Parentizada: ");
	printStack(pilhaP1);
	printf("\n\n\n");
	printf("Equacao: a-(b/c)*(d+e)-f\nTotalmente Parentizada: ");
	printStack(pilhaP2);

	return EXIT_SUCCESS;
}

