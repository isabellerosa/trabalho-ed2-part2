#include "stack.h"

Stack* newStack(){
	Stack* new  = (Stack*) malloc(sizeof(Stack));
	new->bottom = new->top = NULL;

	return new;
}

int isStackEmpty(Stack* stack){
	return (stack->top == NULL);
}

void* pop(Stack* stack){
	if(isStackEmpty(stack))
		return NULL;

	Item* item = stack->top;
	void* element = item->info;

	stack->top = stack->top->prox;

	if(stack->top == NULL)
		stack->bottom = NULL;

	free(item);
	return element;
}

void push(Stack* stack, void* element){
	Item* item = newItem(element);

	item->prox = stack->top;

	if(isStackEmpty(stack)){
		stack->bottom = item;
	}

	stack->top = item;

}

