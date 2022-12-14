#include "lista.h"
#include "ponto.h"

int comparaI(void *i1, void *i2){
    return *((int *) i1) > *((int *) i2);
}

void printI(void *i1){
    printf("Int: %d\n", *((int *) i1));
}

void *typeFI(int opc){ //type int
    if (opc == 1){
        return comparaI;
    } else {
        return printI;
    }
}

int main(){
    Lista *listaPontos = criaLista();
    Ponto *p1 = criaPonto(10, 20);
    Ponto *p2 = criaPonto(10, 30);
    No *noP1 = criaNo(p1, p1->typeF);

    int a = 10;
    int *i1 = &a;

    No *noI1 = criaNo(i1, typeFI);

    insereInicio(listaPontos, noP1);
    insereFinal(listaPontos, noI1);
    imprimeLista(listaPontos);

    int (*compara) (void*, void*) = p1->typeF(1);

    printf("É maior? %s\n", compara(p2, p1) ? "True" : "False");

    return 0;
}