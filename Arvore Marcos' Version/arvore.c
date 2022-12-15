#include "arvore.h"

void recursiveInsert(No *atual, No *novo, int (*cb) (void *, void*), int direction);
void imprimeBranch(No *no, void (*cb) (void *), int counter);

Arvore *criaArvore(){
    Arvore *novo = (Arvore *) calloc(1, sizeof(Arvore));

    if (novo == NULL){
        perror("Falta memoria!");
        exit(1);
    }

    return novo;
}

void insereNo(Arvore *A, No *no, int (*cb) (void *, void *)){
    if (A != NULL){
        if (A->root != NULL){
            if (cb(A->root->info, no->info) == 1){
                recursiveInsert(A->root, no, cb, 1);
            } else if (cb(A->root->info, no->info) == -1){
                printf("entrei");
                recursiveInsert(A->root, no, cb, -1);
            } else{
                return;
            }
        } else{
            A->root = no;
        }
    }
}

void recursiveInsert(No *atual, No *novo, int (*cb) (void *, void*), int direction){
    if (atual == NULL){
        if (direction == -1){
            atual->dir = novo;
        } else {
            atual->esq = novo;
        }

        return;
    } else {
        if (cb(atual->info, novo->info) == 1){
            recursiveInsert(atual->esq, novo, cb, 1);
        } else if (cb(atual->info, novo->info) == -1){
            recursiveInsert(atual->dir, novo, cb, -1);
        } else{
            return;
        }
    }
}

void imprimeDFS(Arvore *A, void (*cb) (void *)){
    if (A != NULL && A->root != NULL){
        printf("Root: ");
        cb(A->root->info);
        printf("\n");

        if (A->root->esq != NULL){
            printf("Esquerda (0): ");
            imprimeBranch(A->root->esq, cb, 1);
        }

        if (A->root->dir != NULL){
            printf("Direita (0): ");
            imprimeBranch(A->root->dir, cb, 1);
        }
    } else{
        printf("Arvore vazia!");
    }
}

void imprimeBranch(No *no, void (*cb) (void *), int counter){
    cb(no->info);
    printf("\n");

    if (no->esq != NULL){
        printf("Esquerda (%d): ", counter);
        imprimeBranch(no->esq, cb, counter++);
    }

    if (no->dir != NULL){
        printf("Direita (%d): ", counter);
        imprimeBranch(no->esq, cb, counter++);
    }
}