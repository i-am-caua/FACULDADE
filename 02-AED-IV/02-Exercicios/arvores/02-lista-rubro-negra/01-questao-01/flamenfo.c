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

void reparacao (No **raiz) {
    if ((*raiz)->pai->cor == PRETO) return;
    // se verdade, tio fica a esq
    if ((*raiz)->pai->dir == *raiz) {
        if ((*raiz)->pai->esq->cor == VERMELHO) {
            (*raiz)->cor = PRETO;
            (*raiz)->pai->esq->cor = PRETO;
            (*raiz)->pai->cor = VERMELHO;
            reparacao(&(*raiz));
        }
    }


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