#include "lista.h"

Lista* removeDup(Lista* l){
    Lista* aux = l;
    Lista* l2 = l;

    if (l != NULL){
        l2 = criaNo(l->info);

        aux = aux->prox;

        while (aux != NULL){
            if (buscaNo(l2, aux->info) == NULL){
                l2 = insereFinal(l2, aux->info);
            }

            aux = aux->prox;
        }
    }

    return l2;
}

int main(){
    printf("1:\n");

    Lista* l = criaNo(10);

    l = insereFinal(l, 10);
    l = insereFinal(l, 20);
    l = insereFinal(l, 20);
    l = insereFinal(l, 30);
    l = insereFinal(l, 30);
    l = insereFinal(l, 30);
    l = insereFinal(l, 40);

    imprimeLista(l);

    l = removeDup(l);

    imprimeLista(l);

    printf("\n2:\n");

    Lista* l2 = criaNo(10);

    imprimeLista(l2);

    l2 = removeDup(l2);

    imprimeLista(l2);

    printf("\n3:\n");

    Lista* l3 = NULL;

    imprimeLista(l3);

    l3 = removeDup(l3);

    imprimeLista(l3);

    return 0;
}