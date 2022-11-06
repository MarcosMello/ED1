#include "lista.h"

LISTA* criaLista(){
    LISTA* L = (LISTA*) calloc(1, sizeof(LISTA*));

    if (L == NULL){
        perror("Erro no calloc! Falta de memoria.");
        exit(1);
    }

    return L;
}

void insereInicio(LISTA* L, int valor){
    NO *novo = criaNo(valor);
    novo->prox = L->inicio;

    if (L->inicio == NULL){
        L->inicio = novo;
        L->fim = novo;
    } else{
        L->inicio->ant = novo;
        L->inicio = novo;
    }

    L->tamanho++;
}

void insereFinal(LISTA* L, int valor){
    NO *novo = criaNo(valor);

    if (L->inicio == NULL){
        L->inicio = novo;
        L->fim = novo;
    } else{
        L->fim->prox = novo;
        novo->ant = L->fim;
        L->fim = novo;
    }

    L->tamanho++;
}

NO* buscaChave(LISTA* L, int valor){
    NO *aux = L->inicio;

    while (aux != NULL && valor != aux->chave){
        if (aux->prox == NULL){
            break;
        }

        aux = aux->prox;
    }

    return aux;
}

void excluiInicio(LISTA* L){
    if (L != NULL){
        NO *aux = L->inicio;
        L->inicio = aux->prox;

        if (L->inicio != NULL){
            L->inicio->ant = NULL;
        }

        free(aux);
    }
}

void excluiFinal(LISTA* L){
    NO *aux = L->fim;

    if (aux->ant == NULL){
        free(L->inicio);
        free(L->fim);

        L->inicio = NULL;
        L->fim = NULL;
    } else{
        aux = aux->ant;
        free(aux->prox);
        aux->prox = NULL;
    }
}

void excluiChave(LISTA* L, int valor){
    NO *aux = L->inicio;

    if (aux->prox != NULL){
        while (aux->prox != NULL && aux->chave != valor){
            aux = aux->prox;
        }

        if (aux->prox == NULL && aux->chave == valor){
            aux->ant->prox = NULL;
            L->fim = aux->ant;

            free(aux);

            L->tamanho--;
        } else if (aux->chave == valor){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;

            free(aux);
            L->tamanho--;
        }
    } else{
        if (aux != NULL && aux->chave == valor){
            free(L->inicio);
            free(L->fim);

            L->inicio = NULL;
            L->fim = NULL;
            L->tamanho = 0;
        }
    }
}

NO* buscaChaveOrd(LISTA* L, int valor){
    NO *aux = L->inicio;

    while (aux != NULL && valor > aux->chave){
        if (aux->prox == NULL){
            break;
        }

        aux = aux->prox;
    }

    return aux;
}

void insereOrd(LISTA* L, int valor){
    NO *novo = criaNo(valor);
    NO *aux = buscaChaveOrd(L, valor);

    if (aux == NULL){
        L->inicio = novo;
        L->fim = novo;
    } else{
        if (aux->chave < valor){
            aux->prox = novo;
            novo->ant = aux;
        } else{
            novo->prox = aux;

            if (aux->ant == NULL){
                L->inicio = novo;
            } else{
                aux->ant->prox = novo;
                novo->ant = aux->ant;
            }

            aux->ant = novo;
        }
    }

    L->tamanho++;
}

void limpaLista(LISTA* L){
    NO *aux = L->inicio;

    while (aux != NULL){
        NO *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    L->inicio = NULL;
    L->fim = NULL;
    L->tamanho = 0;
}

LISTA* deletaLista(LISTA* L){
    limpaLista(L);
    free(L);

    return NULL;
}

void imprimeLista(LISTA* L){
    NO *aux = L->inicio;

    if (aux != NULL){
        printf("[\n");

        for(int i = 0; aux != NULL; i++){
            printf("%d => %d\n", i, aux->chave);
            aux = aux->prox;
        }

        printf("]\n");
    } else{
        printf("[]\n");
    }
}