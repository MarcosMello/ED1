#ifndef PONTO_H
#define PONTO_H

#include<stdlib.h>
#include<stdio.h>

typedef struct ponto
{
    int x;
    int y;
}Ponto;

Ponto* criaponto(int x, int y);

void imprimePonto(void *info);
int comparaPonto(void *info,void *info2);

#endif