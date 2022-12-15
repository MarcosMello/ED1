#include "lista.h"
#include "no.h"
#include "ponto.h"
#include <stdlib.h>

int main(void)
{
  printf("iniciando o prog1\n");
  Lista* LPonto = criaLista();
  Lista* LInteiros = criaLista();

  int x=rand()%10;
  int y=rand()%10;

  int i=0;

  for(i=0;i<20;i++)
  {
    x=rand()%10;
    y=rand()%10;

    int *x2 = (int*) malloc(sizeof(int));
    *x2=i;

    insereNodeOrd(LPonto,criaNo(criaponto(x,y)),comparaPonto);
    insereNodeInicio(LInteiros,criaNo(x2));
  }

  printf("%p\n", LPonto);
  printf("%p\n", LInteiros);

  LPonto=deletaLista(LPonto);
  free(LPonto);

  LInteiros=deletaLista(LInteiros);
  free(LInteiros);

  printf("%p\n", LPonto);
  printf("%p\n", LInteiros);

  imprimeLista(LPonto, imprimePonto);
  imprimeLista(LInteiros, imprimeInt);

  // printf("O que tem na lista\n");
  // imprimeLista(LPonto,imprimePonto);
  // imprimeLista(LInteiros,imprimeInt);
 // printf("Depois do exclui incio:\n");
 // excluiInicio(L);

 // imprimeLista(L);

  //printf("\n\nlimpalista\n\n");

  // limpaLista(LPonto);
  // imprimeLista(LPonto,imprimePonto);
//printf("Conteudo:\n");

  //imprimeLista(L);
  return 0;
}
