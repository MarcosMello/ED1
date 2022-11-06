#ifndef LISTA_H
#define LISTA_H

#include "no.h"

typedef struct lista{
    int tamanho;
    NO* inicio;
    NO* fim;
} LISTA;

LISTA* criaLista();

void insereInicio(LISTA* L, int valor);
void insereFinal(LISTA* L, int valor);
NO* buscaChave(LISTA* L, int valor);
void excluiInicio(LISTA* L);
void excluiFinal(LISTA* L);
void excluiChave(LISTA* L, int valor);

NO* buscaChaveOrd(LISTA* L, int valor);
void insereOrd(LISTA* L, int valor);

void limpaLista(LISTA* L);
LISTA* deletaLista(LISTA* L);
void imprimeLista(LISTA* L);

#endif