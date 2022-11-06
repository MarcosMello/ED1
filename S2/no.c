#include "no.h"

NO *criaNo (int valor){
    NO *novo = (NO*) calloc(1, sizeof(NO));

    if (novo == NULL){
        perror("Erro no calloc! Falta de memoria.");
        exit(1);
    }

    novo->chave = valor;

    return novo;
}