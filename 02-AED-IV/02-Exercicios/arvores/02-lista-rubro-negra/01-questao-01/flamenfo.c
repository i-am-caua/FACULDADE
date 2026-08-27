#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRETO 10
#define VERMELHO 20

typedef struct No {
    int chave;
    int cor;
    struct No *esq, *dir, *pai;
    int altura;
}No;

No *criarNo (int chave) {
    No *no = malloc (sizeof(No));
    no->chave = chave;
    no->altura = 1;
    no->cor = VERMELHO;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;

    return no;
}
No *rotacaoEsquerda(No *raiz) {
    No *aux = raiz->dir;

    raiz->dir = aux->esq;
    if (aux->esq != NULL) aux->esq->pai = raiz;
    aux->esq = raiz;

    aux->pai = raiz->pai;
    raiz->pai = aux;

   
    return aux;
}
No *rotacaoDireita(No *raiz) {
    No *aux = raiz->esq;

    raiz->esq = aux->dir;
    if (aux->dir != NULL) aux->dir->pai = raiz;
    aux->dir = raiz;

    aux->pai = raiz->pai;
    raiz->pai = aux;

    return aux;
}

void reparacao (No **raiz) {
    if ((*raiz)->pai == NULL) {
        (*raiz)->cor = PRETO;
        return;
    }
    // se verdade, tio fica a esq
    if ((*raiz)->pai->pai->dir == (*raiz)->pai) {
        if ((*raiz)->pai->pai->esq->cor == VERMELHO) {
            
            (*raiz)->pai->pai->esq->cor = PRETO;
            (*raiz)->pai->cor = PRETO;
            if ((*raiz)->pai->pai != NULL) {
                (*raiz)->pai->pai->cor = VERMELHO;
            }
        } else if ((*raiz)->pai->dir == *raiz) {
            *raiz = rotacaoEsquerda(*raiz);
        } else {
            (*raiz)->pai->cor = PRETO;
            (*raiz)->pai->pai->cor = VERMELHO;
           (*raiz)->pai->pai = rotacaoDireita((*raiz)->pai->pai);
        }
    } else {
         if ((*raiz)->pai->pai->dir->cor == VERMELHO) {
            
            (*raiz)->pai->pai->dir->cor = PRETO;
            (*raiz)->pai->cor = PRETO;
            if ((*raiz)->pai->pai != NULL) {
                (*raiz)->pai->pai->cor = VERMELHO;
            }
        } else if ((*raiz)->pai->dir == *raiz) {
            *raiz = rotacaoDireita(*raiz);
        } else {
            (*raiz)->pai->cor = PRETO;
            (*raiz)->pai->pai->cor = VERMELHO;
           (*raiz)->pai->pai = rotacaoEsquerda((*raiz)->pai->pai);
        }
    }
    reparacao(&(*raiz));


}


void inserir (No **raiz,int chave, No *pai) {
    if (*raiz == NULL) {
        *raiz = criarNo (chave);
        (*raiz)->pai = pai;
        return;
    }
    if (chave > (*raiz)->chave) inserir (&(*raiz)->dir, chave, *raiz);
    else if (chave < (*raiz)->chave) inserir (&(*raiz)->esq, chave, *raiz);
    else {
        return;
    }
    reparacao(&(*raiz));

}
