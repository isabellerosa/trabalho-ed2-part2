/*
 * 05 - Escreva uma função para calcular a altura de um nó de uma árvore binária.
 */

#include "main.h"

TreeNodeResult* createResultNode(void* node, int lvl){
	TreeNodeResult* treeNodeResult = (TreeNodeResult*) malloc(sizeof(TreeNodeResult));

	treeNodeResult->lvl = lvl;
	treeNodeResult->node = node;

	return treeNodeResult;
}

void find(TipoArvore* no, TipoItem item, int lvl, TreeSearchResult* result){
	if(result->levels < lvl+1) result->levels = lvl+1;

	if(no->item.chave == item.chave){
		insertAt(result->nodes_matched, ((Lista*)result->nodes_matched)->numItens, createResultNode(no, lvl+1));
	}
		if(no->direita != NULL) find(no->direita, item, lvl+1, result);
		if(no->esquerda != NULL) find(no->esquerda, item, lvl+1, result);


}

int calculaAlturaDoNo(TipoArvore* arvore, TipoItem item){

	TreeSearchResult* results = (TreeSearchResult*) malloc(sizeof(TreeSearchResult));
	results->levels = 0;
	results->nodes_matched = newList();

	find(arvore, item, 0, results);

	//printf("%i\n", ((TreeNodeResult*) results->nodes_matched->first->info)->lvl);
	//printf("%i\n", ((TipoArvore*) ((TreeNodeResult*) results->nodes_matched->first->info)->node)->item.chave);

	int noLvl = ((TreeNodeResult*) results->nodes_matched->first->info)->lvl;

	return results->levels - noLvl + 1;
}


int main(void){
	TipoArvore* arvore = NULL;

	TipoArvore *no1, *no2, *no3, *no4, *no5, *no6;

	no1 = criaNoArvore();
	no2 = criaNoArvore();
	no3 = criaNoArvore();
	no4 = criaNoArvore();
	no5 = criaNoArvore();
	no6 = criaNoArvore();

	no1->esquerda = no2;
	no1->direita = no3;
	no2->esquerda = no4;
	no2->direita = no5;
	no3->direita = no6;

	arvore = no1;

	imprimeArvoreBinaria(arvore, 5);


	printf("\nNo:%i\tAltura:%i\n", no3->item.chave, calculaAlturaDoNo(arvore, no3->item));

	printf("No:%i\tAltura:%i\n", no1->item.chave, calculaAlturaDoNo(arvore, no1->item));

	printf("No:%i\tAltura:%i", no6->item.chave, calculaAlturaDoNo(arvore, no6->item));

	return EXIT_SUCCESS;
}

