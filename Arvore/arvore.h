#ifndef ARVORE_H
#define ARVORE_H

#include"no.h"
#include"ponto.h"


typedef struct arvore
{
  No* root;
}Arvore;

//Arvore* A;

Arvore* criaArvore();
void insereNode(Arvore* A, No* novo,int (*cb) (void *, void *));
//void insereNodeOrd(Arvore* A, No* novo,int (*cb) (void *, void *));
void removeNode(Arvore* A, No* novo,int (*cb) (void *, void *));
void removeNodeOrd(Arvore* A, No* novo,int (*cb) (void *, void *));
//void imprimeArvore(Arvore* A,void (*cb) (void *));
//void insereNodeEsquerda(No* node, No* novo,int (*cb) (void *, void *));
//void insereNodeDireita(No* node, No* novo,int (*cb) (void *, void *));
void arv_imprime(Arvore* a,void (*cb) (void *));
//void node_imprime(No* node,void (*cb) (void *));
void insereLeafNode(No* node, No* novo,int (*cb) (void *, void *));

#endif