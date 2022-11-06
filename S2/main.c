#include "lista.h"

NO *pop(LISTA *L, int index){
    NO* aux = NULL;

    if (L->tamanho > index && index >= 0){
        aux = L->inicio;

        for (int i = 0; (i < index) && (aux != NULL); i++){
            aux = aux->prox;
        }

        if (aux != NULL){
            L->tamanho--;

            if (aux->prox == NULL && aux->ant == NULL){
                L = NULL;
                L->tamanho = 0;
            } else if (aux->ant == NULL){
                aux->prox->ant = NULL;
                L->inicio = aux->prox;
            } else if (aux->prox == NULL){
                aux->ant->prox = NULL;
                L->fim = aux->ant;
            } else {
                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;
            }
        }
    }

    return aux;
}

LISTA *concatListasOrd(LISTA *l1, LISTA *l2){
    LISTA *listaFinal = criaLista();
    NO *aux1 = NULL, *aux2 = NULL;

    if (l1 != NULL && l2 != NULL){
        aux1 = l1->inicio;
        aux2 = l2->inicio;

        while (aux1 != NULL || aux2 != NULL){
            if (aux1 != NULL && aux2 != NULL){
                if (aux1->chave < aux2->chave){
                    insereFinal(listaFinal, aux1->chave);
                    aux1 = aux1->prox;
                } else{
                    insereFinal(listaFinal, aux2->chave);
                    aux2 = aux2->prox;
                }
            } else if (aux1 == NULL){
                while (aux2 != NULL){
                    insereFinal(listaFinal, aux2->chave);
                    aux2 = aux2->prox;
                }
            } else{
                while (aux1 != NULL){
                    insereFinal(listaFinal, aux1->chave);
                    aux1 = aux1->prox;
                }
            }
        }
    } else if (l1 != NULL){
        aux1 = l1->inicio;

        while (aux1 != NULL){
            insereFinal(listaFinal, aux1->chave);
            aux1 = aux1->prox;
        }
    } else{
        aux2 = l2->inicio;

        while (aux2 != NULL){
            insereFinal(listaFinal, aux2->chave);
            aux2 = aux2->prox;
        }
    }

    return listaFinal;
}

LISTA *sortedLista(LISTA* l){
    LISTA *listaFinal = criaLista();

    if (l != NULL){
        NO *aux = l->inicio;

        while (aux != NULL){
            insereOrd(listaFinal, aux->chave);

            aux = aux->prox;
        }
    }

    return listaFinal;
}

int isEqual(LISTA* l1, LISTA* l2){
    if (l1 == NULL && l2 == NULL){
        return 1;
    } else {
        if (l1->tamanho != l2->tamanho){
            return 0;
        } else{
            LISTA *l1s = sortedLista(l1);
            LISTA *l2s = sortedLista(l2);

            NO *aux1 = l1s->inicio;
            NO *aux2 = l2s->inicio;

            while (aux1 != NULL && aux2 != NULL){
                if (aux1->chave != aux2->chave){
                    return 0;
                }

                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }

            return 1;
        }
    }
}

LISTA *popWithList(LISTA *l1, LISTA *l2){
    LISTA *listaFinal = criaLista();
    NO *aux1 = l1->inicio;
    NO *aux2 = l2->inicio;

    if (aux1 != NULL){
        for (int i = 0; i < l1->tamanho; i++){
            if (aux2 != NULL && i == aux2->chave){
                aux2 = aux2->prox;
            } else{
                insereFinal(listaFinal, aux1->chave);
            }

            aux1 = aux1->prox;
        }
    }

    return listaFinal;
}

int main(){
    char opc;
    int index;

    LISTA* l1 = criaLista();

    insereInicio(l1, 20);
    insereInicio(l1, 10);
    insereFinal(l1, 30);
    insereFinal(l1, 40);
    insereFinal(l1, 50);

    LISTA* l2 = criaLista();

    insereFinal(l2, 60);
    insereFinal(l2, 70);
    insereFinal(l2, 80);

    LISTA *l3 = criaLista();

    insereFinal(l3, 1);
    insereFinal(l3, 3);
    insereFinal(l3, 7);

    LISTA *l4 = criaLista();

    insereFinal(l4, 10);
    insereFinal(l4, 30);
    insereFinal(l4, 50);

    printf("Qual questao deseja testar? ");
    scanf("%c", &opc);

    if (opc == 'a'){
        printf("Lista 1: ");
        imprimeLista(l1);

        printf("Qual a posicao item que deseja remover? ");
        scanf("%d", &index);

        NO *no = pop(l1, index);

        if (no != NULL){
            printf("%d foi removido da Lista 1. \nLista 1: ", no->chave);
        } else{
            printf("Lista 1: ");
        }

        imprimeLista(l1);
    } else if (opc == 'b'){
        printf("Lista 1: ");
        imprimeLista(l1);

        printf("Lista 2: ");
        imprimeLista(l2);

        LISTA *listaFinal = concatListasOrd(l1, l2);

        printf("Apos a concatenacao, temos: \nLista final: ");
        imprimeLista(listaFinal);
    } else if (opc == 'c'){
        printf("Lista 1: ");
        imprimeLista(l1);

        LISTA* lFinal = popWithList(l1, l3);

        printf("Apos tirarmos as posicoes 1, 3, 7 da lista 1, temos: \nLista 1: ");
        imprimeLista(lFinal);
    } else if (opc == 'd'){
        printf("Lista 1: ");
        imprimeLista(l1);

        printf("Lista 2: ");
        imprimeLista(l2);

        printf("As listas 1 e 2 sao iguais? %s\n", isEqual(l1, l2) ? "Sim" : "Nao");

        LISTA* lFinal = popWithList(l1, l3);
        printf("Lista 1 modificada (Posicoes 1 e 3 removidas): ");
        imprimeLista(lFinal);

        printf("Lista 4: ");
        imprimeLista(l4);

        printf("As lista 1 modificada (Posicoes 1 e 3 removidas) e 4 sao iguais? %s\n", isEqual(lFinal, l4) ? "Sim" : "Nao");
    } else{
        printf("OPCAO INEXISTENTE!\n");
    }
    return 0;
}