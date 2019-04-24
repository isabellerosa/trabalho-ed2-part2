/*
 * main.h
 *
 *  Created on: 24 de abr de 2019
 *      Author: ibell
 */

#ifndef MAIN_H_
#define MAIN_H_

//#define _GNU_SOURCE  // stdio.h to include asprintf
#include <stdio.h>
#include <stdlib.h>

#include "asprintf.h"
#include "isa/pilha/stack.h"
#include "isa/arvore/tree.h"
#include "isa/string/strCol.h"

int operador(char*);
int precedencia(char*);
char* infixaParaPrefixa(char*);
void montaArvorePrefixa(Tree**, Stack*);
Stack* stringToStack(char*);
Stack* strToStk(char*);

#endif /* MAIN_H_ */
