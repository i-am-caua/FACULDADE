#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int chave;
    char nome[20];
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
    if (*raiz == NULL) {
        *raiz = criarNo(chave,nome);
        return;
    }
    if (chave > (*raiz)->chave) {
        inserir(&(*raiz)->dir, chave, nome);
    }
    else if (chave < (*raiz)->chave) {
        inserir(&(*raiz)->esq, chave, nome);
    }

}
char *encontrarNo (No *raiz, int chave) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave) return raiz->nome;

    if (chave > raiz->chave) {
        return encontrarNo(raiz->dir, chave);
    }
    else if (chave < raiz->chave) {
        return encontrarNo(raiz->esq, chave);
    }
}

No  *menor (No *raiz) {
    if (raiz == NULL) return NULL; //arv vazia

    No *aux = raiz;

    while (aux->esq != NULL) {
        aux = aux->esq;
    }
    return aux;

}
int maior (No *raiz) {
    if (raiz == NULL) return -1; //arv vazia

    No *aux = raiz;

    while (aux->dir != NULL) {
        aux = aux->dir;
    }
    return aux->chave;

}
int quantidadeFilhos (No *raiz) {
    int qtd = 0;
    if (raiz->esq != NULL) qtd++;
    if (raiz->dir != NULL) qtd++;
    return qtd;
}

void remover (No **raiz, int chave) {
    if (*raiz == NULL) return;
    if (chave < (*raiz)->chave) remover (&(*raiz)->esq, chave);
    else if (chave > (*raiz)->chave) remover (&(*raiz)->dir, chave);
    else {
        if (quantidadeFilhos(*raiz) == 0) {
            No *aux = *raiz;
            *raiz = NULL;
            free (aux);
        } else if (quantidadeFilhos(*raiz) == 1) {
            No *aux = *raiz;
            if ((*raiz)->dir != NULL) *raiz = (*raiz)->dir;
            else *raiz = (*raiz)->esq;
            free (aux);
        } else {
            No *aux = menor ((*raiz)->dir);
            (*raiz)->chave = aux->chave;
            strcpy((*raiz)->nome, aux->nome);
            remover (&(*raiz)->dir, aux->chave);

        }
    }
}



int main () {

    return 0;
}
