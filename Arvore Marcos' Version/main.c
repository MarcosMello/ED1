#include "no.h"
#include "ponto.h"
#include "arvore.h"
#include <stdlib.h>

int main(){
    Arvore* A = criaArvore();

    printf("\n Inserindo ponto 10\n\n");
    insereNo(A, criaNo(criaPonto(10,15)), comparaPontos);

    printf("\n Inserindo ponto 15\n\n");
    insereNo(A, criaNo(criaPonto(15,25)), comparaPontos);

    printf("\n Inserindo ponto 25\n\n");
    insereNo(A, criaNo(criaPonto(25,5)), comparaPontos);

    printf("\n Inserindo ponto 35\n\n");
    insereNo(A, criaNo(criaPonto(35,10)), comparaPontos);

    printf("\n Inserindo ponto 5\n\n");
    insereNo(A, criaNo(criaPonto(5,10)), comparaPontos);

    printf("\n Inserindo ponto 4\n\n");
    insereNo(A, criaNo(criaPonto(4,10)), comparaPontos);

    printf("\n Inserindo ponto 6\n\n");
    insereNo(A, criaNo(criaPonto(6,10)), comparaPontos);

    printf("\n Inserindo ponto 16\n\n");
    insereNo(A, criaNo(criaPonto(16,10)), comparaPontos);

    imprimePonto(A->root->dir->info);

    imprimeDFS(A, imprimePonto);

    return 0;
}