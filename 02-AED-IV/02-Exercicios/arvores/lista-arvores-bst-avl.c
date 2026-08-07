#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int chave;
    char nome[];
    struct no *esq, *dir;
}No;

No *criarNo (int chave, char *nome) {
    No *noNovo = malloc (sizeof (No));

    noNovo->chave = chave;
    strcpy(noNovo->nome, nome);
    noNovo->dir = NULL;
    noNovo->esq = NULL;
    return noNovo;
}

void inserir (No **raiz, int chave, char *nome) {
    if (raiz == NULL) {
        *raiz = criarNo(chave,nome);
        return;
    }
    if (chave > (*raiz)->chave) {
        inserir(&(*raiz)->dir, chave, nome);
    }
    else if (chave < (*raiz->chave)) {
        inserir(&(*raiz)->esq, chave, nome);
    }

}
char *encontrarNo (No *raiz, int chave) {
    if (*raiz == NULL) return NULL;
    if ((*raiz)->chave == chave) return (*raiz)->nome;

    if (chave > (*raiz)->chave) {
        return encontrarNo(&(*raiz)->dir, chave, nome);
    }
    else if (chave < (*raiz->chave)) {
        return encontrarNo(&(*raiz)->esq, chave, nome);
    }
}

int menor (No *raiz) {
    if (raiz == NULL) return -1; //arv vazia

    No *aux = raiz;

    while (aux->esq != NULL) {
        aux = aux->esq;
    }
    return aux->chave;

}
int maior (No *raiz) {
    if (raiz == NULL) return -1; //arv vazia

    No *aux = raiz;

    while (aux->dir != NULL) {
        aux = aux->dir;
    }
    return aux->chave;

}

char *remover (No **raiz, int chave) {

}



int main () {

    return 0;
}
