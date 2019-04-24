/*
 * tree.h
 *
 *  Created on: 23 de abr de 2019
 *      Author: ibell
 */

#ifndef ISA_ARVORE_TREE_H_
#define ISA_ARVORE_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
	void* content;
	struct _tree *left;
	struct _tree *right;
} Tree; //tipo das células com os itens da árvore binária


Tree* newTree(void*, Tree*, Tree*);
int isTreeEmpty(Tree*);
void printTree(Tree*, int);
int isLeaf(Tree*);

#endif /* ISA_ARVORE_TREE_H_ */
