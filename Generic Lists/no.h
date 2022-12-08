#ifndef NO_H

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

typedef struct no{
    void *info;

    struct no *prox;
    struct no *ant;

    void *(*typeF) (int);
} No;

No *criaNo(void *info, void *(*typeF) (int));

#endif