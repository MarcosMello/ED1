#ifndef NO_H
#define NO_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct no{
    void *info;
    struct no *esq;
    struct no *dir;
} No;

No *criaNo(void *info);

#endif