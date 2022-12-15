#include "no.h"

No *criaNo(void *info)
{
  No *novo=(No*)malloc(sizeof(No));
  if(novo==NULL)
  {
    perror("Erro no malloc");
    exit(1);
  }
  novo->info = info;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}
