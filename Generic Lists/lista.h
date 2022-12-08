#ifndef LISTA_H
#define LISTA_H

#include "no.h"

typedef struct lista{
    No *ini;
    No *fim;
    No *aux;
    int tamanho;
} Lista;

Lista *criaLista();

void insereInicio(Lista *L, No *no);
void insereFinal(Lista *L, No *no);
void excluiInicio(Lista *L);
void excluiFinal(Lista *L);

// void insereOrd(Lista *L, No *no);
// void insereEsq(Lista *L, No *no);
// void insereDir(Lista *L, No *no);
// void insereOrdCB(Lista *L, No *no, int (*cb) (void *, void *));

void imprimeLista(Lista *L);
// void limpaLista(Lista *L);
// Lista *deletaLista(Lista *L);

#endif