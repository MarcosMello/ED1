#include "no.h"

No *criaNo(void *info, void *(*typeF) (int)){
    No *novo = (No *) calloc(1, sizeof(No));

    if (novo == NULL){
        perror("Falta memoria!");
        exit(1);
    }

    novo->info = info;

    novo->typeF = typeF;

    return novo;
}