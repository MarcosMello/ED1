#include"arvore.h"


void node_imprime(No* node,void (*cb) (void *));

Arvore* criaArvore()
{
    Arvore* A = (Arvore*) malloc(sizeof(Arvore));
    A->root=NULL;
    return A;
}

 void insereNode(Arvore* A, No* novo,int (*cb) (void *, void *))
{
     if(A->root!=NULL)
     {
        printf("root !NULL\n");
         int retorno = cb(A->root->info,novo->info);
         printf("retorno: %i\n",retorno);
         if(retorno==1)
         {
            printf("InsereLeaf esq\n");
            if(A->root->esq==NULL)
            {
                A->root->esq=novo;
            }
            else
            {
                insereLeafNode(A->root->esq,novo,cb);
            }

         }
         else if(retorno ==-1)
         {
            printf("InsereLeaf dir\n");

            //printf("InsereLeaf esq\n");
            if(A->root->dir==NULL)
            {
                A->root->dir=novo;
            }
            else
            {
                insereLeafNode(A->root->dir,novo,cb);
            }

            //insereLeafNode(A->root->dir,novo,cb);
         }
         else
         {
            //printf("\n");
            printf("valor igual\n");
         }
     }
     else
     {
        printf("root NULL\n");
         A->root=novo;
     }

}




void insereLeafNode(No* node, No* novo,int (*cb) (void *, void *))
{
    if(node!=NULL)
    {
        printf("node !NULL\n");
        int retorno = cb(node->info,novo->info);
         printf("retorno: %i\n",retorno);
         if(retorno==1)
         {
            printf("InsereLeaf esq\n");
            if(node->esq==NULL)
            {
                node->esq=novo;
            }
            else
            {
                insereLeafNode(node->esq,novo,cb);
            }

         }
         else if(retorno ==-1)
         {
            printf("InsereLeaf dir\n");

            //printf("InsereLeaf esq\n");
            if(node->dir==NULL)
            {
                node->dir=novo;
            }
            else
            {
                insereLeafNode(node->dir,novo,cb);
            }

            //insereLeafNode(A->root->dir,novo,cb);
         }
         else
         {
            //printf("\n");
            printf("valor igual\n");
         }
    }
    else
    {
        printf("node NULL\n");
        node=novo;
    }

}

void arv_imprime(Arvore* a,void (*cb) (void *))
{
  //printf("<");
  if(a != NULL)
  {
   // printf("%i",a->info);
    node_imprime(a->root,cb);
  }
  //printf(">");
}

void node_imprime(No* node,void (*cb) (void *))
{
    //printf("node_imprime\n");
    printf("\n<");
    if(node != NULL)
    {
        cb(node->info);
    }
    if(node->esq !=NULL)
    {
        //printf("e:");
        //cb(node->esq->info);
        node_imprime(node->esq,cb);
    }

    if(node->dir != NULL)
    {
        //printf("d:");
        //cb(node->dir->info);
        node_imprime(node->dir,cb);
    }
    printf(">");
}