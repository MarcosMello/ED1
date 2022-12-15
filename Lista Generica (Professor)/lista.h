#ifndef LISTA_H
#define LISTA_H

#include"no.h"

typedef struct lista
{
  int tamanho;
  No* pri;
  No* aux;
  No* fim;
}Lista;

//Lista* L;

Lista* criaLista();
void insereNodeInicio(Lista* L, No* node);
void insereNodeFinal(Lista* L, No* node);
void excluiInicio(Lista* L);
void excluiFinal(Lista* L);
void imprimeLista(Lista * L,void (*cb) (void*));
void limpaLista(Lista* L);

void insereNodeOrd(Lista* L, No* node,int (*cb) (void *, void *));
void insereNodeEsquerda(Lista* L, No* novo);
void insereNodeDireita(Lista* L, No* novo);
void imprimeInt(void *info);
Lista* deletaLista(Lista* L);

#endif