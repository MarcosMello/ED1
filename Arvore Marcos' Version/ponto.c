#include "ponto.h"

Ponto *criaPonto(int x, int y){
    Ponto *novo = (Ponto *) calloc(1, sizeof(Ponto));

    if (novo == NULL){
        perror("Falta memoria!");
        exit(1);
    }

    novo->x = x;
    novo->y = y;

    return novo;
}

int comparaPontos(void *info1, void *info2){
    return (((Ponto *) info1)->x) == (((Ponto *) info2)->x) ? 0 : ((((Ponto *) info1)->x) > (((Ponto *) info2)->x) ? 1 : -1);
}

void imprimePonto(void *info){
    printf("x = %d, y = %d", ((Ponto *) info)->x, ((Ponto *) info)->y);
}