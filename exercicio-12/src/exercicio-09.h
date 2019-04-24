/*
 * exercicio-9.h
 *
 *  Created on: 24 de abr de 2019
 *      Author: ibell
 */

#ifndef EXERCICIO_09_H_
#define EXERCICIO_09_H_


//#define _GNU_SOURCE  // stdio.h to include asprintf
#include <stdio.h>
#include <stdlib.h>

#include "asprintf.h"
#include "isa/pilha/stack.h"
#include "isa/arvore/tree.h"

int operador(char*);
int precedencia(char*);
char* infixaParaPrefixa(char*);
void montaArvorePrefixa(Tree**, Stack*);
Stack* stringToStack(char*);
Stack* strToStk(char*);

#endif /* EXERCICIO_09_H_ */
