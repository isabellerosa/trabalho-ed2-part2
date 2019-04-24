#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Tree* newTree(void* content, Tree* left, Tree* right){
	Tree* new = (Tree*) malloc(sizeof(Tree));
	new->content = content;
	new->left = left;
	new->right = right;

	return new;
}

int isTreeEmpty(Tree* tree){
	return (tree == NULL);
}
void printTree(Tree* tree, int level){
	int i;
	if(!isTreeEmpty(tree)){
		printTree(tree->right, level+1);
		for(i=0;i<level;i++)
			printf("   ");
		printf("%s\n", tree->content);
		printTree(tree->left, level+1);
	}
}

int isLeaf(Tree* tree) {
	return (tree->left == NULL && tree->right == NULL);
}

