#ifndef ARVORE_H
#define ARVORE_H

#include "no.h"
#include "ponto.h"

typedef struct arvore{
    No *root;
} Arvore;

Arvore *criaArvore();
void insereNo(Arvore *A, No *no, int (*cb) (void *, void *));
void imprimeDFS(Arvore *A, void (*cb) (void *));

#endif