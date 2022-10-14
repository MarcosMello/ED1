/*
    Calculo da complexidade:
        Esse código é O(n+m) pois passa por cada um dos elementos de ambas as listas até chegar no final de ambas.
        É O(n+m) pois ele passa elemento por elemento de l1 ou l2 uma única vez para ser adicionado na l3.

        No pior caso de execução, ele terá que passar por todos elementos de l1 (tamanho 3) e após por todos elementos de l2 (tamanho 4).
        l1 (i) e l2 (j) serão do tipo i0 < i1 < i2 < j0 < j1 < j2 < j3.

        Logo ele fará 3 auxl1->prox para só depois começar a fazer os 4 auxl2->prox (no else, uma vez que auxl1 já vai ser NULL).
*/

#include "lista.h"

Lista* concatLista(Lista* l1, Lista* l2){
    Lista* f = NULL;
    Lista* ant = NULL;
    Lista* antF = NULL;
    Lista* auxL1 = l1;
    Lista* auxL2 = l2;

    int v1, v2;

    while (auxL1 != NULL || auxL2 != NULL){
        if (auxL1 != NULL && auxL2 != NULL){
            v1 = auxL1->info;
            v2 = auxL2->info;

            if (v1 < v2){
                ant = auxL1;
                auxL1 = auxL1->prox;
            } else{
                ant = auxL2;
                auxL2 = auxL2->prox;
            }

            if (f == NULL){
                f = ant;
                antF = f;
            } else{
                antF->prox = ant;
                antF = ant;
            }
        } else {
            if (auxL1 == NULL){
                ant = auxL2;
                auxL2 = auxL2->prox;
            } else{
                ant = auxL1;
                auxL1 = auxL1->prox;
            }

            if (f == NULL){
                f = ant;
                antF = f;
            } else{
                antF->prox = ant;
                antF = ant;
            }
        }
    }

    return f;
}

int main(){
    Lista* l2 = criaNo(10);
    l2 = insereFinal(l2, 20);
    l2 = insereFinal(l2, 30);

    imprimeLista(l2);

    Lista* l1 = criaNo(40);
    l1 = insereFinal(l1, 50);
    l1 = insereFinal(l1, 60);

    imprimeLista(l1);

    Lista* l3 = concatLista(l1, l2);

    imprimeLista(l3);

    return 0;
}