#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct ponto{
    int x;
    int y;
} Ponto;

Ponto *criaPonto(int x, int y);

int comparaPontos(void *info1, void *info2);
void imprimePonto(void *info);

#endif