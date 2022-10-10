#include "lista.h"

Lista* criaNo(int valor){
    Lista* novo = (Lista*) calloc(1, sizeof(Lista));

    if (novo == NULL){
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    novo->info = valor;

    return novo;
}

Lista* insereInicio(Lista *l, int valor){
    Lista* novo = criaNo(valor);

    novo->prox = l;
    l = novo;

    return l;
}

Lista* insereFinal(Lista *l, int valor){
    Lista* novo = criaNo(valor);
    Lista* aux = l;

    if (l == NULL){
        l = novo;
    } else{
        while (aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    return l;
}

Lista* buscaNo(Lista *l, int valor){
    Lista* aux = l;

    if (l == NULL){
        return NULL;
    } else{
        while (aux != NULL && aux->info != valor){
            aux = aux->prox;
        }
    }

    return aux;
}

Lista* excluiInicio(Lista *l){
    Lista* aux = l;

    if (l == NULL){
        return NULL;
    } else{
        l = l->prox;
        free(aux);
    }

    return l;
}

Lista* excluiFinal(Lista *l){
    Lista* aux = l;
    Lista* ant = NULL;

    if (l == NULL){
        return NULL;
    } else{
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }

        if (ant == NULL){
            l = NULL;
        } else{
            ant->prox = NULL;
        }

        free(aux);
    }

    return l;
}

Lista* excluiNo(Lista *l, int valor){
    Lista* aux = l;
    Lista* ant = NULL;

    if (l == NULL){
        return NULL;
    } else{
        while (aux != NULL && aux->info != valor){
            ant = aux;
            aux = aux->prox;
        }

        if (ant == NULL){
            l = aux->prox;
        } else{
            ant->prox = aux->prox;
        }

        free(aux);
    }

    return l;
}

void imprimeLista(Lista *l){
    Lista* aux = l;

    while (aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }

    printf("\n");
}