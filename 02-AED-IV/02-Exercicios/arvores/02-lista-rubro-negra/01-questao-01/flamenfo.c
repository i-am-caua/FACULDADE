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

/* =========================================================================
 * FUNCOES AUXILIARES PARA VISUALIZACAO E DEBUG (Sem alterar o codigo acima)
 * ========================================================================= */

#ifdef _WIN32
#include <windows.h>
static void habilitarCoresWindows(void) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
            SetConsoleMode(hOut, dwMode);
        }
    }
    SetConsoleOutputCP(65001); // UTF-8
}
#else
static void habilitarCoresWindows(void) {}
#endif

#define ANSI_RESET       "\033[0m"
#define ANSI_BOLD        "\033[1m"
#define ANSI_RED_TEXT    "\033[1;31m"
#define ANSI_RED_BG      "\033[1;37;41m"
#define ANSI_BLACK_BG    "\033[1;37;40m"
#define ANSI_BLACK_TEXT  "\033[1;90m"
#define ANSI_GRAY        "\033[1;90m"
#define ANSI_GREEN       "\033[1;32m"
#define ANSI_YELLOW      "\033[1;33m"
#define ANSI_BLUE        "\033[1;34m"
#define ANSI_CYAN        "\033[1;36m"

static const char* obterCorTexto(int cor) {
    if (cor == VERMELHO) return ANSI_RED_TEXT "VERMELHO" ANSI_RESET;
    if (cor == PRETO)    return ANSI_BLACK_TEXT "PRETO" ANSI_RESET;
    return ANSI_YELLOW "DESCONHECIDO" ANSI_RESET;
}

static const char* obterTagCor(int cor) {
    if (cor == VERMELHO) return ANSI_RED_BG " V " ANSI_RESET;
    if (cor == PRETO)    return ANSI_BLACK_BG " P " ANSI_RESET;
    return ANSI_YELLOW "[?]" ANSI_RESET;
}

/* Imprime detalhes completos de um no (chave, cor, pai, filhos) */
void exibirDetalhesNo(No *no) {
    if (no == NULL) {
        printf("(NULL)\n");
        return;
    }
    printf("Chave: %s%3d%s | Cor: %-18s | Pai: ",
           (no->cor == VERMELHO ? ANSI_RED_TEXT : ANSI_BLACK_TEXT),
           no->chave,
           ANSI_RESET,
           obterCorTexto(no->cor));

    if (no->pai != NULL) {
        printf("%s%3d%s (%s)",
               (no->pai->cor == VERMELHO ? ANSI_RED_TEXT : ANSI_BLACK_TEXT),
               no->pai->chave,
               ANSI_RESET,
               (no->pai->cor == VERMELHO ? "V" : "P"));
    } else {
        printf("%sRAIZ (NULL)%s", ANSI_CYAN, ANSI_RESET);
    }

    printf(" | Esq: ");
    if (no->esq != NULL) printf("%3d", no->esq->chave);
    else printf(" - ");

    printf(" | Dir: ");
    if (no->dir != NULL) printf("%3d", no->dir->chave);
    else printf(" - ");

    printf("\n");
}

/* Percurso Pre-Ordem detalhado */
void preOrdemDetalhada(No *raiz) {
    if (raiz == NULL) return;
    exibirDetalhesNo(raiz);
    preOrdemDetalhada(raiz->esq);
    preOrdemDetalhada(raiz->dir);
}

/* Percurso Em-Ordem formatado */
void emOrdemFormatada(No *raiz) {
    if (raiz == NULL) return;
    emOrdemFormatada(raiz->esq);
    printf(" [%s%d%s: %s] ",
           (raiz->cor == VERMELHO ? ANSI_RED_TEXT : ANSI_BLACK_TEXT),
           raiz->chave,
           ANSI_RESET,
           obterCorTexto(raiz->cor));
    emOrdemFormatada(raiz->dir);
}

/* Percurso Pos-Ordem formatado */
void posOrdemFormatada(No *raiz) {
    if (raiz == NULL) return;
    posOrdemFormatada(raiz->esq);
    posOrdemFormatada(raiz->dir);
    printf(" [%s%d%s: %s] ",
           (raiz->cor == VERMELHO ? ANSI_RED_TEXT : ANSI_BLACK_TEXT),
           raiz->chave,
           ANSI_RESET,
           obterCorTexto(raiz->cor));
}

/* Letra c) da lista: Mostrar o valor de todos os nos pares de cor preta */
void mostrarParesPretos(No *raiz) {
    if (raiz == NULL) return;
    mostrarParesPretos(raiz->esq);
    if (raiz->cor == PRETO && raiz->chave % 2 == 0) {
        printf(" %s[Par Preto: %d]%s", ANSI_BLACK_TEXT, raiz->chave, ANSI_RESET);
    }
    mostrarParesPretos(raiz->dir);
}

/* Letra d) da lista: Mostrar a quantidade de nos vermelhos impares */
int contarImparesVermelhos(No *raiz) {
    if (raiz == NULL) return 0;
    int cont = (raiz->cor == VERMELHO && (raiz->chave % 2 != 0)) ? 1 : 0;
    return cont + contarImparesVermelhos(raiz->esq) + contarImparesVermelhos(raiz->dir);
}

/* Visualizacao grafica da arvore em formato hierarquico (arvore 2D) */
void imprimirArvoreVisual(No *raiz, char *prefixo, int ehFilhoEsquerdo) {
    if (raiz == NULL) return;

    printf("%s", prefixo);
    printf("%s", ehFilhoEsquerdo ? "├── (E) " : "└── (D) ");

    printf("%s %s%s%d%s",
           obterTagCor(raiz->cor),
           ANSI_BOLD,
           (raiz->cor == VERMELHO ? ANSI_RED_TEXT : ANSI_BLACK_TEXT),
           raiz->chave,
           ANSI_RESET);

    if (raiz->pai != NULL) {
        printf(" %s(pai: %d)%s\n", ANSI_GRAY, raiz->pai->chave, ANSI_RESET);
    } else {
        printf(" %s[RAIZ]%s\n", ANSI_CYAN, ANSI_RESET);
    }

    char novoPrefixo[512];
    snprintf(novoPrefixo, sizeof(novoPrefixo), "%s%s", prefixo, ehFilhoEsquerdo ? "│   " : "    ");

    if (raiz->esq != NULL || raiz->dir != NULL) {
        if (raiz->esq != NULL) {
            imprimirArvoreVisual(raiz->esq, novoPrefixo, 1);
        } else {
            printf("%s├── (E) %sNULL%s\n", novoPrefixo, ANSI_GRAY, ANSI_RESET);
        }

        if (raiz->dir != NULL) {
            imprimirArvoreVisual(raiz->dir, novoPrefixo, 0);
        } else {
            printf("%s└── (D) %sNULL%s\n", novoPrefixo, ANSI_GRAY, ANSI_RESET);
        }
    }
}

/* Diagnostico de integridade e validacao das regras de Arvore Rubro-Negra */
int verificarPropriedadesRN(No *raiz, int *totalViolacoes) {
    if (raiz == NULL) return 1;

    // 1. Raiz deve ser preta
    if (raiz->pai == NULL && raiz->cor != PRETO) {
        printf("  %s[VIOLACAO 1]%s Raiz (%d) e VERMELHA! A raiz deve ser PRETA.\n",
               ANSI_RED_TEXT, ANSI_RESET, raiz->chave);
        (*totalViolacoes)++;
    }

    // 2. Ponteiros de pai
    if (raiz->esq != NULL && raiz->esq->pai != raiz) {
        printf("  %s[ERRO PONTEIRO]%s Filho esquerdo (%d) nao aponta para pai (%d)!\n",
               ANSI_RED_TEXT, ANSI_RESET, raiz->esq->chave, raiz->chave);
        (*totalViolacoes)++;
    }
    if (raiz->dir != NULL && raiz->dir->pai != raiz) {
        printf("  %s[ERRO PONTEIRO]%s Filho direito (%d) nao aponta para pai (%d)!\n",
               ANSI_RED_TEXT, ANSI_RESET, raiz->dir->chave, raiz->chave);
        (*totalViolacoes)++;
    }

    // 3. Dois nos vermelhos consecutivos (Pai vermelho com filho vermelho)
    if (raiz->cor == VERMELHO) {
        if (raiz->esq != NULL && raiz->esq->cor == VERMELHO) {
            printf("  %s[VIOLACAO 2]%s No vermelho (%d) tem filho esquerdo vermelho (%d)!\n",
                   ANSI_RED_TEXT, ANSI_RESET, raiz->chave, raiz->esq->chave);
            (*totalViolacoes)++;
        }
        if (raiz->dir != NULL && raiz->dir->cor == VERMELHO) {
            printf("  %s[VIOLACAO 2]%s No vermelho (%d) tem filho direito vermelho (%d)!\n",
                   ANSI_RED_TEXT, ANSI_RESET, raiz->chave, raiz->dir->chave);
            (*totalViolacoes)++;
        }
    }

    if (raiz->esq) verificarPropriedadesRN(raiz->esq, totalViolacoes);
    if (raiz->dir) verificarPropriedadesRN(raiz->dir, totalViolacoes);

    return (*totalViolacoes == 0);
}

/* Liberacao de memoria */
void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

/* =========================================================================
 * FUNCAO PRINCIPAL (MAIN) DETALHADA PARA TESTE E DEBUG
 * ========================================================================= */

int main(void) {
    habilitarCoresWindows();

    No *raiz = NULL;
    int opcao;
    int chave;

    printf("\n%s=======================================================%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%s   TESTADOR & DEBUGGER: ARVORE RUBRO-NEGRA (AED IV)   %s\n", ANSI_BOLD, ANSI_RESET);
    printf("%s=======================================================%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%sLegenda de Cores: %s[ V ] Vermelho%s  %s[ P ] Preto%s\n",
           ANSI_CYAN, ANSI_RED_BG, ANSI_RESET, ANSI_BLACK_BG, ANSI_RESET);

    do {
        printf("\n%s--------------------- MENU DE OPCOES ---------------------%s\n", ANSI_BLUE, ANSI_RESET);
        printf("%s1%s - Inserir uma chave individual\n", ANSI_GREEN, ANSI_RESET);
        printf("%s2%s - Inserir lote de teste automatico (10, 20, 30, 15, 25, 5, 1)\n", ANSI_GREEN, ANSI_RESET);
        printf("%s3%s - Exibir Arvore Visual (Estrutura 2D com cores)\n", ANSI_GREEN, ANSI_RESET);
        printf("%s4%s - Exibir Tabela Detalhada de Nos (Chave, Cor, Pai, Filhos)\n", ANSI_GREEN, ANSI_RESET);
        printf("%s5%s - Executar Percursos (Pre-Ordem, Em-Ordem, Pos-Ordem)\n", ANSI_GREEN, ANSI_RESET);
        printf("%s6%s - Questoes da Lista (Pares Pretos & Qtd Impares Vermelhos)\n", ANSI_GREEN, ANSI_RESET);
        printf("%s7%s - Diagnostico e Validacao das Regras Rubro-Negras\n", ANSI_GREEN, ANSI_RESET);
        printf("%s8%s - Limpar toda a arvore\n", ANSI_GREEN, ANSI_RESET);
        printf("%s0%s - Sair\n", ANSI_RED_TEXT, ANSI_RESET);
        printf("%sEscolha uma opcao: %s", ANSI_BOLD, ANSI_RESET);

        if (scanf("%d", &opcao) != 1) {
            printf("%s[ERRO] Entrada invalida. Digite apenas numeros.%s\n", ANSI_RED_TEXT, ANSI_RESET);
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite a chave inteira para inserir: ");
                if (scanf("%d", &chave) == 1) {
                    printf("\n%s>> Inserindo chave %d...%s\n", ANSI_YELLOW, chave, ANSI_RESET);
                    inserir(&raiz, chave, NULL);
                    printf("%s[SUCESSO] Operacao de insercao finalizada.%s\n", ANSI_GREEN, ANSI_RESET);
                    printf("\n--- Estrutura Atual da Arvore ---\n");
                    imprimirArvoreVisual(raiz, "", 0);
                } else {
                    printf("%sValor invalido!%s\n", ANSI_RED_TEXT, ANSI_RESET);
                    while (getchar() != '\n');
                }
                break;

            case 2: {
                int lote[] = {10, 20, 30, 15, 25, 5, 1};
                int tamLote = sizeof(lote) / sizeof(lote[0]);
                printf("\n%s>> Inserindo lote de %d chaves...%s\n", ANSI_YELLOW, tamLote, ANSI_RESET);
                for (int i = 0; i < tamLote; i++) {
                    printf("-> Inserindo %d...\n", lote[i]);
                    inserir(&raiz, lote[i], NULL);
                }
                printf("%s[OK] Lote inserido com sucesso.%s\n\n", ANSI_GREEN, ANSI_RESET);
                printf("--- Estrutura Apos Insercao do Lote ---\n");
                imprimirArvoreVisual(raiz, "", 0);
                break;
            }

            case 3:
                if (raiz == NULL) {
                    printf("%s[AVISO] A arvore esta vazia!%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    printf("\n%s=== ESTRUTURA VISUAL DA ARVORE RUBRO-NEGRA ===%s\n", ANSI_CYAN, ANSI_RESET);
                    imprimirArvoreVisual(raiz, "", 0);
                }
                break;

            case 4:
                if (raiz == NULL) {
                    printf("%s[AVISO] A arvore esta vazia!%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    printf("\n%s=== TABELA DETALHADA DE NOS (PRE-ORDEM) ===%s\n", ANSI_CYAN, ANSI_RESET);
                    preOrdemDetalhada(raiz);
                }
                break;

            case 5:
                if (raiz == NULL) {
                    printf("%s[AVISO] A arvore esta vazia!%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    printf("\n%s=== PERCURSOS DA ARVORE ===%s\n", ANSI_CYAN, ANSI_RESET);

                    printf("\n%s1. Pre-Ordem:%s\n", ANSI_BOLD, ANSI_RESET);
                    preOrdemDetalhada(raiz);

                    printf("\n%s2. Em-Ordem (Ordenado):%s\n", ANSI_BOLD, ANSI_RESET);
                    emOrdemFormatada(raiz);
                    printf("\n");

                    printf("\n%s3. Pos-Ordem:%s\n", ANSI_BOLD, ANSI_RESET);
                    posOrdemFormatada(raiz);
                    printf("\n");
                }
                break;

            case 6:
                if (raiz == NULL) {
                    printf("%s[AVISO] A arvore esta vazia!%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    printf("\n%s=== QUESTOES DA LISTA DE EXERCICIOS ===%s\n", ANSI_CYAN, ANSI_RESET);

                    printf("\n%sc) Nos pares de cor PRETA:%s\n", ANSI_BOLD, ANSI_RESET);
                    mostrarParesPretos(raiz);
                    printf("\n");

                    printf("\n%sd) Quantidade de nos vermelhos IMPARES:%s %s%d%s\n",
                           ANSI_BOLD, ANSI_RESET,
                           ANSI_RED_TEXT, contarImparesVermelhos(raiz), ANSI_RESET);
                }
                break;

            case 7:
                if (raiz == NULL) {
                    printf("%s[AVISO] A arvore esta vazia!%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    printf("\n%s=== DIAGNOSTICO DE REGRAS RUBRO-NEGRAS ===%s\n", ANSI_CYAN, ANSI_RESET);
                    int totalViolacoes = 0;
                    verificarPropriedadesRN(raiz, &totalViolacoes);
                    if (totalViolacoes == 0) {
                        printf("%s[SUCESSO] Nenhuma violacao basica encontrada!%s\n", ANSI_GREEN, ANSI_RESET);
                    } else {
                        printf("\n%s[ALERTA] Foram detectadas %d violacoes nas regras da Rubro-Negra!%s\n",
                               ANSI_RED_TEXT, totalViolacoes, ANSI_RESET);
                    }
                }
                break;

            case 8:
                if (raiz == NULL) {
                    printf("%sA arvore ja esta vazia.%s\n", ANSI_YELLOW, ANSI_RESET);
                } else {
                    liberarArvore(raiz);
                    raiz = NULL;
                    printf("%s[OK] Arvore liberada e zerada.%s\n", ANSI_GREEN, ANSI_RESET);
                }
                break;

            case 0:
                printf("\n%sEncerrando o programa de teste. Ate mais!%s\n", ANSI_CYAN, ANSI_RESET);
                break;

            default:
                printf("%s[ERRO] Opcao invalida. Escolha entre 0 e 8.%s\n", ANSI_RED_TEXT, ANSI_RESET);
        }

    } while (opcao != 0);

    if (raiz != NULL) {
        liberarArvore(raiz);
        raiz = NULL;
    }

    return 0;
}