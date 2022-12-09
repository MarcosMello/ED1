#include "lista.h"
#include "ponto.h"

Lista *criaLista(){
    Lista *novo = (Lista *) calloc(1, sizeof(Lista));

    if (novo == NULL){
        perror("Falta memoria!");
        exit(1);
    }

    return novo;
}

void insereInicio(Lista *L, No *no){
    if (L != NULL){
        if (L->ini == NULL){
            L->ini = no;
            L->fim = no;
            L->aux = no;
        } else{
            no->prox = L->ini;
            L->ini->ant = no;

            L->ini = no;
        }

        L->tamanho++;
    }
}
void insereFinal(Lista *L, No *no){
    if (L != NULL){
        if (L->fim == NULL){
            L->ini = no;
            L->fim = no;
            L->aux = no;
        } else{
            no->ant = L->fim;
            L->fim->prox = no;

            L->fim = no;
        }

        L->tamanho++;
    }
}
void excluiInicio(Lista *L){
    if (L != NULL){
        if (L->ini != NULL){
            if (L->fim == L->ini){
                L->ini = NULL;
                L->fim = NULL;
                L->aux = NULL;
            } else{
                L->ini = L->ini->prox;
                free(L->ini->ant);
                L->ini->ant = NULL;
            }
        }
    }
}
void excluiFinal(Lista *L){
    if (L != NULL){
        if (L->fim != NULL){
            if (L->fim == L->ini){
                L->ini = NULL;
                L->fim = NULL;
                L->aux = NULL;
            } else{
                L->fim = L->fim->ant;
                free(L->fim->prox);
                L->fim->prox = NULL;
            }
        }
    }
}

// void insereOrd(Lista *L, No *no);
// void insereEsq(Lista *L, No *no);
// void insereDir(Lista *L, No *no);
// void insereOrdCB(Lista *L, No *no, int (*cb) (void *, void *));

void imprimeLista(Lista *L){
    int contador = 0;

    if (L != NULL){
        L->aux = L->ini;

        while (L->aux != NULL){
            printf("Posicao %d => ", contador++);
            void (*print) (void *) = L->aux->typeF(0);
            print(L->aux->info);
            printf("\n");

            L->aux = L->aux->prox;
        }
    } else{
        printf("Lista Vazia!\n");
    }
}
// void limpaLista(Lista *L);
// Lista *deletaLista(Lista *L);