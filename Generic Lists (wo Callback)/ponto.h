#ifndef PONTO_H

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

typedef struct ponto{
    int x;
    int y;

    void *(*typeF) (int);
} Ponto;

Ponto *criaPonto(int x, int y);

int comparaP(void *p1, void *p2);
void printP(void *p1);

void *typeF(int opc);

#endif