/**
 * 09 - Represente as expressões aritméticas a seguir por meio de árvores binárias.
 *
 * A: ( ( a + b ) * ( c + d ) / e ) – ( ( f + g ) * h )
 * B: a – (b / c) * (d + e) – f
 */

#include "main.h"

int operador(char* op) {
	return !(strcmp(op, "+") && strcmp(op, "-") && strcmp(op, "*")
			&& strcmp(op, "/"));
}

int precedencia(char* operador) {
	switch (operador[0]) {
	case '-':
	case '+':
		return 1;
	case '*':
	case '/':
		return 2;
	}

	return 0;
}

char* infixaParaPrefixa(char* expressao) {
	Stack* operadores = newStack();
	Stack* operandos = newStack();

	char separador[] = " ";
	char* token;

	token = strtok(expressao, separador);

	while (token != NULL) {
		if (token[0] == '(') {
			push(operadores, token);
		} else if (token[0] == ')') {
			while (!isStackEmpty(operadores)
					&& strcmp(operadores->top->info, "(") != 0) {
				char* num1 = pop(operandos);
				char* num2 = pop(operandos);
				char* op = pop(operadores);

				char* tmp;

				asprintf(&tmp, "%s %s %s", op, num2, num1);
				push(operandos, tmp);

			}

			pop(operadores);
		}

		else if (!operador(token)) {
			push(operandos, token);
		}

		else {
			while (!isStackEmpty(operadores)
					&& precedencia(token) <= precedencia(operadores->top->info)) {

				char* num1 = pop(operandos);
				char* num2 = pop(operandos);
				char* op = pop(operadores);

				char* tmp ;

				asprintf(&tmp, "%s %s %s", op, num2, num1);

				push(operandos, tmp);

			}

			push(operadores, token);
		}

		token = strtok(NULL, separador);
	}

	while (!isStackEmpty(operadores) && (operandos->top != operandos->bottom)) {

		char* num1 = pop(operandos);
		char* num2 = pop(operandos);
		char* op = pop(operadores);

		char* tmp ;

		asprintf(&tmp, "%s %s %s", op, num2, num1);

		push(operandos, tmp);

	}
	char* temp = pop(operandos);
	return temp;
}

void montaArvorePrefixa(Tree** arvore, Stack* pilha) {

	if (!isStackEmpty(pilha)) {
		char* E = pop(pilha);
		Tree* no = newTree(E, NULL, NULL);

		if ((*arvore) == NULL) {
			(*arvore) = no;
		}
		else if ((*arvore)->left == NULL) {
			(*arvore)->left = no;
			if (operador(E)) {
				montaArvorePrefixa(&no, pilha);
			}
		} else if ((*arvore)->right == NULL) {
			(*arvore)->right = no;
			if (operador(E)) {
				montaArvorePrefixa(&no, pilha);
			}
		}

		if ((*arvore)->left != NULL && (*arvore)->right != NULL)
			return;

		montaArvorePrefixa(arvore, pilha);

	}
}

Stack* stringToStack(char* str){
	Stack* stack = newStack();

	int i;
	for(i = strlen(str); i>-1; i--){
		char* E;
		asprintf(&E ,"%c", str[i]);
		push(stack, E);

	}
	return stack;
}

Stack* strToStk(char* str){
	Stack* tmp = newStack();

	char* token = strtok(str, " ");

	while(token != NULL){
		push(tmp, token);
		token = strtok(NULL, " ");
	}

	//reverse

	Stack* stack = newStack();

	while(!isStackEmpty(tmp)){
		push(stack, pop(tmp));
	}

	return stack;
}


int main(void) {
	char str1[] = "( ( a + b ) * ( c + d ) / e ) - ( ( f + g ) * h )";
	char str2[] = "a - (b / c) * (d + e) - f";

	Stack* pilha1 = strToStk(infixaParaPrefixa(str1));
	Stack* pilha2 = strToStk(infixaParaPrefixa(str2));

	Tree* arvore1 = NULL;
	montaArvorePrefixa(&arvore1, pilha1);

	Tree* arvore2 = NULL;
	montaArvorePrefixa(&arvore2, pilha2);

	printf("== ARVORE 1 ==\n");

	printTree(arvore1, 0);

	printf("\n\n");
	printf("== ARVORE 2 ==\n");

	printTree(arvore1, 0);


	//TESTE COM NUMEROS
/*	char str[] = "4 - ( 34 / 67 ) * ( 89 + 3 ) - 0";
	Stack* pilha = strToStk(infixaParaPrefixa(str));

	Tree* arvore = NULL;
	montaArvorePrefixa(&arvore, pilha);

	printf("== ARVORE NUMEROS ==\n");
	printTree(arvore, 0);*/

	return EXIT_SUCCESS;
}
