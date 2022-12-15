#include "lista.h"

Lista* criaLista()
{
	Lista* L = (Lista*) malloc(sizeof(Lista));
	L->pri=NULL;
	L->fim=NULL;
  L->aux=NULL;
	L->tamanho=0;
  return L;
}

void insereNodeInicio(Lista* L, No* node)
{
  node->prox=L->pri;
  if(L->pri==NULL)
  {
	  L->pri=node;
    L->aux=node;
    L->fim=node;
  }
  else
  {
    L->pri->ant=node;
    L->pri = node;
  }

}

void insereNodeFinal(Lista* L, No* node)
{
  if(L->pri==NULL)
  {
	  L->pri=node;
    L->aux=node;
    L->fim=node;
  }
  else
  {
    L->fim->prox=node;
    node->ant=L->fim;
    L->fim=node;
  }
}

Lista* deletaLista(Lista* L)
{
  limpaLista(L);
  free(L);
  printf("\n#####Lista Deletada####\n");
  return NULL;
}

void limpaLista(Lista* L)
{
  int cont=0;

  printf("\n#####Excluindo####\n");
  if(L->pri!=NULL)
  {
    printf("\n#####Lista nao vazia####\n");
    if(L->pri != L->fim)
    {
      L->aux = L->pri;
      while(L->aux!=NULL)
      {
        //printf("Excluindo posicao %i:\t valor: %i \t...OK!\n",cont,aux->chave);
        L->aux = L->aux->prox;
        free(L->pri);
        L->pri = L->aux;
        //L->aux = L->aux->prox;
        cont++;
      }

      if(L->pri != NULL)
      {
        printf("estranho....");
      }
      //free(L->pri);
      //L->pri=NULL;
      L->fim=NULL;
      //L->aux=NULL;
    }
    else
    {
      printf("\n#####Lista com um elemento####\n");
      free(L->pri);
      L->pri=NULL;
      L->fim=NULL;
      L->aux=NULL;
    }

  }



  printf("\n#####Lista Limpa####\n");
  L->pri=NULL;
  L->aux=NULL;
  L->fim=NULL;

}


void insereNodeOrd(Lista* L, No* node,int (*cb) (void *, void *))
{
  if(L->pri!=NULL)
  {
    int retorno = cb(node->info,L->pri->info);
    if(retorno==0)
    {
      insereNodeInicio(L,node);
    }
    else if(retorno==-1)
    {
      insereNodeInicio(L,node);
    }
    else
    {
      retorno = cb(node->info,L->fim->info);

      if(retorno==0)
      {
        insereNodeFinal(L,node);
      }
      else if(retorno==1)
      {
        insereNodeFinal(L,node);
      }
      else
      {
        retorno = cb(node->info,L->aux->info);

        if(retorno==0)
        {
          insereNodeDireita(L,node);
        }
        else if(retorno==1)
        {
          int retornoProx = cb(node->info,L->aux->prox->info);

          while (retornoProx == 1 && L->aux->prox != L->fim)
          {
            L->aux = L->aux->prox;
            retornoProx = cb(node->info,L->aux->prox->info);
          }

          if(retornoProx==0)
          {
            insereNodeDireita(L,node);
          }
          else if(retornoProx==-1)
          {
              L->tamanho++;
              //printf("insere direita aux\n");
              insereNodeDireita(L,node);
          }
          else
          {
              printf("else do retorno %i e retornoProx: %i codigo: ", retorno,retornoProx);
          }
        }
        else
        {
          int retornoProx = cb(node->info,L->aux->ant->info);

          while (retornoProx == -1 && L->aux->ant != L->pri)
          {
            L->aux = L->aux->ant;
            retornoProx = cb(node->info,L->aux->ant->info);
          }

          if(retornoProx==0)
          {
              insereNodeEsquerda(L,node);
          }
          else if(retornoProx==1)
          {
              L->tamanho++;
              insereNodeEsquerda(L,node);
          }
          else
          {
              printf("else do retorno %i e retornoProx: %i codigo: ", retorno,retornoProx);
          }


        }

      }

    }

  }
  else
  {
    insereNodeInicio(L,node);
  }

}

void excluiInicio(Lista* L)
{
  if(L!=NULL)
  {
    No *aux=L->pri;
    L->pri=aux->prox;

    if(L->pri!=NULL)
    {
	    L->pri->ant=NULL;
    }

    free(aux);

  }
  //return L;
}

//Lista*  excluiFinal(Lista *L)
void excluiFinal(Lista *L)
{
  No *aux=L->pri;

  if(aux->prox!=NULL)
  {
  	while(aux->prox!=NULL)
  	{
    		aux=aux->prox;
  	}
	  aux=aux->ant;
    free(aux->prox);
    aux->prox=NULL;
  }
  else
  {
	  free(L->pri);
    L->pri=NULL;
  }

//return L;
}


void imprimeInt(void *info)
{
  int *temp = (int *) info;
  printf("%i", *temp);

}


void insereNodeDireita(Lista* L, No* novo)
{
    novo->prox=L->aux->prox;
    novo->ant=L->aux;
    L->aux->prox->ant=novo;
    L->aux->prox=novo;

}

void insereNodeEsquerda(Lista* L, No* novo)
{
    novo->prox = L->aux;
    novo->ant=L->aux->ant;
    L->aux->ant->prox=novo;
    L->aux->ant=novo;

}

void imprimeLista(Lista * L,void (*cb) ( void * ))
{
  int cont=0;
  L->aux=L->pri;

  if(L->aux!=NULL)
  {
    printf("\n############# Conteudo da Lista ##########\n");
    while(L->aux!=NULL)
    {
      printf("Posicao: %i\t valor: ",cont);
      cb(L->aux->info);
      printf("\n");
      L->aux=L->aux->prox;
      cont++;
    }

    printf("#######################\n");
  }
  else
  {
    printf("\n############# Lista Vazia ##########\n");
  }
  //return L;
}

