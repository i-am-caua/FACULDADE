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
    if (aux->esq != NULL) 
        aux->esq->pai = raiz;

    aux->pai = raiz->pai;
    if (raiz->pai != NULL) {
        if (raiz->pai->esq == raiz)
            raiz->pai->esq = aux;
        else
            raiz->pai->dir = aux;
    }

    aux->esq = raiz;
    raiz->pai = aux;

    return aux;
}

No *rotacaoDireita(No *raiz) {
    No *aux = raiz->esq;

    raiz->esq = aux->dir;
    if (aux->dir != NULL)
        aux->dir->pai = raiz;

    aux->pai = raiz->pai;
    if (raiz->pai != NULL) {
        if (raiz->pai->esq == raiz)
            raiz->pai->esq = aux;
        else
            raiz->pai->dir = aux;
    }

    aux->dir = raiz;
    raiz->pai = aux;

    return aux;
}

void reparacao(No **raiz_arvore, No *no) {
    // Enquanto o nó não for a raiz e o pai for VERMELHO (conflito)
    while (no->pai != NULL && no->pai->cor == VERMELHO) {
        No *pai = no->pai;
        No *avo = pai->pai;

        // Se o pai é filho esquerdo do avô
        if (pai == avo->esq) {
            No *tio = avo->dir;

            // Caso 1: Tio é VERMELHO (apenas recolorir)
            if (tio != NULL && tio->cor == VERMELHO) {
                pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
                no = avo; // Conflito sobe para o avô
            } else {
                // Caso 2: Tio é PRETO e nó é filho direito (joelho)
                if (no == pai->dir) {
                    no = pai;
                    pai = rotacaoEsquerda(no);
                }
                // Caso 3: Tio é PRETO e nó é filho esquerdo (linha reta)
                pai->cor = PRETO;
                avo->cor = VERMELHO;
                No *novo_topo = rotacaoDireita(avo);
                if (novo_topo->pai == NULL)
                    *raiz_arvore = novo_topo;
            }
        } 
        // Se o pai é filho direito do avô (simétrico)
        else {
            No *tio = avo->esq;

            // Caso 1: Tio é VERMELHO (apenas recolorir)
            if (tio != NULL && tio->cor == VERMELHO) {
                pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
                no = avo; // Conflito sobe para o avô
            } else {
                // Caso 2: Tio é PRETO e nó é filho esquerdo (joelho)
                if (no == pai->esq) {
                    no = pai;
                    pai = rotacaoDireita(no);
                }
                // Caso 3: Tio é PRETO e nó é filho direito (linha reta)
                pai->cor = PRETO;
                avo->cor = VERMELHO;
                No *novo_topo = rotacaoEsquerda(avo);
                if (novo_topo->pai == NULL)
                    *raiz_arvore = novo_topo;
            }
        }
    }

    // A raiz principal da árvore deve ser sempre PRETA
    (*raiz_arvore)->cor = PRETO;
}

void inserir(No **raiz_arvore, int chave) {
    No *novo = criarNo(chave);
    No *pai = NULL;
    No *atual = *raiz_arvore;

    // Busca pela posição correta de inserção
    while (atual != NULL) {
        pai = atual;
        if (chave < atual->chave)
            atual = atual->esq;
        else if (chave > atual->chave)
            atual = atual->dir;
        else {
            free(novo); // Chave duplicada, não insere
            return;
        }
    }

    novo->pai = pai;

    if (pai == NULL) {
        *raiz_arvore = novo;
    } else if (chave < pai->chave) {
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }

    // Chama a reparação passando a raiz da árvore e o nó recém-inserido
    reparacao(raiz_arvore, novo);
}
