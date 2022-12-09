#include "ponto.h"

Ponto *criaPonto(int x, int y){
    Ponto *novo = (Ponto *) calloc(1, sizeof(Ponto));

    if (novo == NULL){
        perror("Falta memoria!");
        exit(1);
    }

    novo->x = x;
    novo->y = y;

    novo->typeF = typeF;

    return novo;
}

int comparaP(void *p1, void *p2){
    Ponto *pt1 = (Ponto *) p1;
    Ponto *pt2 = (Ponto *) p2;

    return ((pt1->x + pt1->y) > (pt2->x + pt2->y));
}

void printP(void *p1){
    printf("Ponto:\nX: %d\nY: %d\n", ((Ponto *) p1)->x, ((Ponto *) p1)->y);
}

void *typeF(int opc){
    if (opc == 1){
        return comparaP;
    } else {
        return printP;
    }
}