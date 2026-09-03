#include <stdio.h>
#include <stdlib.h>

typedef struct No {
   struct No *letras[26];
   int palavra;

}No;

No *criarNo () {
    No *no = malloc (sizeof(No));
    for (int i = 0; i < 26; i++) {
        no->letras[i] = NULL;
    }
    no->palavra = 0;
    return no;
}

void inserir (No **raiz, char *palavra) {
    
    if (*raiz == NULL) *raiz = criarNo();
    int index = palavra[0] - 'a';
    if ((*raiz)->letras[index] == NULL) (*raiz)->letras[index] = criarNo();
    if (palavra[1] == '\0') {
        (*raiz)->letras[index]->palavra = 1;
        return;
    }
    inserir (&((*raiz)->letras[index]), palavra + 1);   
}
int vetorNULL (No *vtr[]) {
    for (int i = 0; i < 26; i++) {
        if (vtr[i] != NULL) return 0;
    }
    return 1;
}

void remover (No **raiz, char *palavra) {
    if (raiz == NULL || *raiz == NULL || palavra == NULL) return;
    
    if (palavra[0] == '\0') (*raiz)->palavra = 0; 
    else {
        int i = palavra[0] - 'a';
        remover(&((*raiz)->letras[i]), palavra + 1);
    } 
    if (vetorNULL((*raiz)->letras) && !(*raiz)->palavra) {
        free(*raiz);
        *raiz = NULL;
    }
   
}
void imprimirTrieRec(No *raiz, char *buffer, int nivel) {
    if (raiz == NULL) return;

    if (raiz->palavra) {
        buffer[nivel] = '\0';
        printf(" - %s\n", buffer);
    }

    for (int i = 0; i < 26; i++) {
        if (raiz->letras[i] != NULL) {
            buffer[nivel] = 'a' + i;
            imprimirTrieRec(raiz->letras[i], buffer, nivel + 1);
        }
    }
}

void imprimirTrie(No *raiz) {
    if (raiz == NULL || (vetorNULL(raiz->letras) && !raiz->palavra)) {
        printf("Arvore Trie vazia.\n\n");
        return;
    }
    printf("\n--- Palavras na Trie ---\n");
    char buffer[100];
    imprimirTrieRec(raiz, buffer, 0);
    printf("------------------------\n\n");
}

int buscar(No *raiz, char *palavra) {
    if (raiz == NULL || palavra == NULL) return 0;
    if (palavra[0] == '\0') return raiz->palavra;
    int index = palavra[0] - 'a';
    if (index < 0 || index >= 26 || raiz->letras[index] == NULL) return 0;
    return buscar(raiz->letras[index], palavra + 1);
}

int main() {
    No *raiz = NULL;
    int opcao;
    char palavra[100];

    do {
        printf("=== MENU ARVORE TRIE ===\n");
        printf("1. Inserir palavra\n");
        printf("2. Remover palavra\n");
        printf("3. Buscar palavra\n");
        printf("4. Imprimir palavras\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                printf("Digite a palavra para inserir: ");
                scanf("%s", palavra);
                inserir(&raiz, palavra);
                printf("Palavra '%s' inserida!\n\n", palavra);
                break;
            case 2:
                printf("Digite a palavra para remover: ");
                scanf("%s", palavra);
                remover(&raiz, palavra);
                printf("Remocao de '%s' processada!\n\n", palavra);
                break;
            case 3:
                printf("Digite a palavra para buscar: ");
                scanf("%s", palavra);
                if (buscar(raiz, palavra)) {
                    printf("A palavra '%s' ESTA na arvore!\n\n", palavra);
                } else {
                    printf("A palavra '%s' NAO esta na arvore.\n\n", palavra);
                }
                break;
            case 4:
                imprimirTrie(raiz);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}