#include"ponto.h"

Ponto* criaponto(int x, int y)
{
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    p->x=x;
    p->y=y;

    return p;
}

void imprimePonto(void *info)
{
   printf("x: %i \t y: %i",((Ponto*)info)->x,((Ponto*)info)->y);
}


int comparaPonto(void *info,void *info2)
{
    if((((Ponto*)info)->x > ((Ponto*)info2)->x))
    {
        return 1;
    }
    else if(((Ponto*)info)->x < ((Ponto*)info2)->x)
    {
        return -1;
    }
    return 0;
}