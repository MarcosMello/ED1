#include "no.h"
#include "ponto.h"
#include "arvore.h"
#include <stdlib.h>

int main(void)
{
  printf("iniciando o prog1\n");

  Arvore* A = criaArvore();

  printf("\n Inserindo ponto 10\n\n");
  insereNode(A,criaNo(criaponto(10,15)),comparaPonto);

  printf("\n Inserindo ponto 15\n\n");
  insereNode(A,criaNo(criaponto(15,25)),comparaPonto);

  printf("\n Inserindo ponto 25\n\n");
  insereNode(A,criaNo(criaponto(25,5)),comparaPonto);

  printf("\n Inserindo ponto 35\n\n");
  insereNode(A,criaNo(criaponto(35,10)),comparaPonto);

  printf("\n Inserindo ponto 5\n\n");
  insereNode(A,criaNo(criaponto(5,10)),comparaPonto);
  printf("\n Inserindo ponto 4\n\n");
  insereNode(A,criaNo(criaponto(4,10)),comparaPonto);
  printf("\n Inserindo ponto 6\n\n");
  insereNode(A,criaNo(criaponto(6,10)),comparaPonto);

  printf("\n Inserindo ponto 16\n\n");
  insereNode(A,criaNo(criaponto(16,10)),comparaPonto);

  printf("\n Imprime Arvore\n\n");

  arv_imprime(A,imprimePonto);

  return 0;
}
/*
        10
     /      \
    5       15
   / \     /  \
  4   6       25
             /  \
            16  35
*/