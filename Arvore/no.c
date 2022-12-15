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
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}
