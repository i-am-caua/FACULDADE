#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int chave;
    char nome[20];
    int altura;
    struct no *esq, *dir;
} No;

int altura(No *raiz) {
    if (raiz == NULL) return 0;
    return raiz->altura;
}

int maiorInteiro(int a, int b) {
    if (a > b) return a;
    return b;
}

void atualizarAltura(No *raiz) {
    if (raiz != NULL) {
        raiz->altura = 1 + maiorInteiro(altura(raiz->esq),
                                        altura(raiz->dir));
    }
}

int fatorBalanceamento(No *raiz) {
    if (raiz == NULL) return 0;
    return altura(raiz->esq) - altura(raiz->dir);
}

No *criarNo(int chave, char *nome) {
    No *noNovo = malloc(sizeof(No));

    noNovo->chave = chave;
    strcpy(noNovo->nome, nome);
    noNovo->altura = 1;
    noNovo->dir = NULL;
    noNovo->esq = NULL;
    return noNovo;
}

No *rotacaoDireita(No *raiz) {
    No *aux = raiz->esq;

    raiz->esq = aux->dir;
    aux->dir = raiz;

    atualizarAltura(raiz);
    atualizarAltura(aux);
    return aux;
}

No *rotacaoEsquerda(No *raiz) {
    No *aux = raiz->dir;

    raiz->dir = aux->esq;
    aux->esq = raiz;

    atualizarAltura(raiz);
    atualizarAltura(aux);
    return aux;
}

void balancear(No **raiz) {
    int fator;

    if (*raiz == NULL) return;

    atualizarAltura(*raiz);
    fator = fatorBalanceamento(*raiz);

    if (fator > 1) {
        if (fatorBalanceamento((*raiz)->esq) < 0) {
            (*raiz)->esq = rotacaoEsquerda((*raiz)->esq);
        }
        *raiz = rotacaoDireita(*raiz);
    }

    if (fator < -1) {
        if (fatorBalanceamento((*raiz)->dir) > 0) {
            (*raiz)->dir = rotacaoDireita((*raiz)->dir);
        }
        *raiz = rotacaoEsquerda(*raiz);
    }
}

void inserir(No **raiz, int chave, char *nome) {
    if (*raiz == NULL) {
        *raiz = criarNo(chave, nome);
        return;
    }

    if (chave > (*raiz)->chave) {
        inserir(&(*raiz)->dir, chave, nome);
    } else if (chave < (*raiz)->chave) {
        inserir(&(*raiz)->esq, chave, nome);
    } else {
        return;
    }

    balancear(raiz);
}

char *encontrarNo(No *raiz, int chave) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave) return raiz->nome;

    if (chave > raiz->chave) {
        return encontrarNo(raiz->dir, chave);
    } else {
        return encontrarNo(raiz->esq, chave);
    }
}

No *menor(No *raiz) {
    No *aux = raiz;

    if (raiz == NULL) return NULL;

    while (aux->esq != NULL) {
        aux = aux->esq;
    }
    return aux;
}

int maior(No *raiz) {
    No *aux = raiz;

    if (raiz == NULL) return -1;

    while (aux->dir != NULL) {
        aux = aux->dir;
    }
    return aux->chave;
}

int quantidadeFilhos(No *raiz) {
    int qtd = 0;

    if (raiz->esq != NULL) qtd++;
    if (raiz->dir != NULL) qtd++;
    return qtd;
}

void remover(No **raiz, int chave) {
    if (*raiz == NULL) return;

    if (chave < (*raiz)->chave) {
        remover(&(*raiz)->esq, chave);
    } else if (chave > (*raiz)->chave) {
        remover(&(*raiz)->dir, chave);
    } else {
        if (quantidadeFilhos(*raiz) == 0) {
            No *aux = *raiz;
            *raiz = NULL;
            free(aux);
        } else if (quantidadeFilhos(*raiz) == 1) {
            No *aux = *raiz;

            if ((*raiz)->dir != NULL) *raiz = (*raiz)->dir;
            else *raiz = (*raiz)->esq;
            free(aux);
        } else {
            No *aux = menor((*raiz)->dir);

            (*raiz)->chave = aux->chave;
            strcpy((*raiz)->nome, aux->nome);
            remover(&(*raiz)->dir, aux->chave);
        }
    }

    balancear(raiz);
}

void preOrdem(No *raiz) {
    if (raiz == NULL) return;

    printf("%d, %s (altura: %d, fator: %d)\n", raiz->chave, raiz->nome,
           raiz->altura, fatorBalanceamento(raiz));
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

int main() {
    No *raiz = NULL;
    int opcao;
    int chave;
    char nome[20];
    char *nomeEncontrado;

    do {
        printf("\n===== ARVORE AVL =====\n");
        printf("1 - Inserir no\n");
        printf("2 - Buscar no\n");
        printf("3 - Mostrar menor chave\n");
        printf("4 - Mostrar maior chave\n");
        printf("5 - Contar filhos de um no\n");
        printf("6 - Remover no\n");
        printf("7 - Exibir arvore em pre-ordem\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida. Digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                printf("Digite o nome (sem espacos): ");
                scanf("%19s", nome);
                inserir(&raiz, chave, nome);
                printf("No inserido (chaves repetidas sao ignoradas).\n");
                break;

            case 2:
                printf("Digite a chave que deseja buscar: ");
                scanf("%d", &chave);
                nomeEncontrado = encontrarNo(raiz, chave);
                if (nomeEncontrado != NULL) {
                    printf("No encontrado: chave %d, nome %s.\n",
                           chave, nomeEncontrado);
                } else {
                    printf("Chave nao encontrada.\n");
                }
                break;

            case 3:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    No *noMenor = menor(raiz);
                    printf("Menor chave: %d, nome: %s.\n",
                           noMenor->chave, noMenor->nome);
                }
                break;

            case 4:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    printf("Maior chave: %d.\n", maior(raiz));
                }
                break;

            case 5: {
                No *atual;

                printf("Digite a chave do no: ");
                scanf("%d", &chave);
                atual = raiz;
                while (atual != NULL && atual->chave != chave) {
                    if (chave < atual->chave) {
                        atual = atual->esq;
                    } else {
                        atual = atual->dir;
                    }
                }
                if (atual == NULL) {
                    printf("Chave nao encontrada.\n");
                } else {
                    printf("O no possui %d filho(s).\n",
                           quantidadeFilhos(atual));
                }
                break;
            }

            case 6:
                printf("Digite a chave que deseja remover: ");
                scanf("%d", &chave);
                if (encontrarNo(raiz, chave) == NULL) {
                    printf("Chave nao encontrada.\n");
                } else {
                    remover(&raiz, chave);
                    printf("No removido.\n");
                }
                break;

            case 7:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    printf("\nArvore em pre-ordem:\n");
                    preOrdem(raiz);
                }
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    while (raiz != NULL) {
        remover(&raiz, raiz->chave);
    }

    return 0;
}
