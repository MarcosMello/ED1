#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} Lista;

// Não ordenada

Lista* criaNo(int valor);
Lista* insereInicio(Lista *l, int valor);
Lista* insereFinal(Lista *l, int valor);
Lista* buscaNo(Lista *l, int valor);
Lista* excluiInicio(Lista *l);
Lista* excluiFinal(Lista *l);
Lista* excluiNo(Lista *l, int valor);
void imprimeLista(Lista *l);

#endif