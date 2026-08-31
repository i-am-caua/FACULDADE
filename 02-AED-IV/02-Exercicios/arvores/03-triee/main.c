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
    if (palavra == NULL) return;
    int i = palavra[0] - 'a';
    if (palavra[0] == '\0') (*raiz)->palavra = 0;
    
    remover(&((*raiz)->letras[i]), palavra + 1);
    
    if (vetorNULL((*raiz)->letras) && !(*raiz)->palavra) {
        free(*raiz);
    }
   
}