#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVtr (int *vtr, int tam) {
    for (int i = 0; i < tam; i++) {
        printf ("%d ", vtr[i]);
    }
    printf ("\n");
}

void vetorAleatorio (int *vtr, int tam) {
    for (int i = 0; i < tam; i++) {
        vtr[i] = (rand() % 900) + 10;
    }
}

int obterMaior (int *vtr, int tam) {
    int maior = vtr[0];
    for (int i = 1; i < tam; i++) {
        if (vtr[i] > maior) {
            maior = vtr[i];
        }
    }
    return maior;
}

// Counting sort pelo digito da posicao exp (1 = unidades, 10 = dezenas, 100 = centenas...)
void countingSort (int *vtr, int tam, int exp) {
    int *saida = malloc (tam * sizeof (int));
    if (saida == NULL) {
        printf ("Erro de alocacao de memoria no counting sort.\n");
        return;
    }

    int contagem[10] = {0};

    // 1. Frequencia dos digitos
    for (int i = 0; i < tam; i++) {
        int digito = (vtr[i] / exp) % 10;
        contagem[digito]++;
    }

    // 2. Acumula para achar as posicoes
    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    // 3. Monta o vetor de tras para frente para manter estabilidade
    for (int i = tam - 1; i >= 0; i--) {
        int digito = (vtr[i] / exp) % 10;
        saida[contagem[digito] - 1] = vtr[i];
        contagem[digito]--;
    }

    // 4. Copia de volta
    for (int i = 0; i < tam; i++) {
        vtr[i] = saida[i];
    }

    free (saida);
}

void radixSort (int *vtr, int tam) {
    int maior = obterMaior (vtr, tam);

    printf ("\nVetor inicial:\n");
    printVtr (vtr, tam);

    int passo = 1;
    // exp multiplica por 10 a cada rodada: unidades, dezenas, centenas...
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSort (vtr, tam, exp);
        printf ("Passo %d (ordenado por exp = %d):\n", passo++, exp);
        printVtr (vtr, tam);
    }
}

int main () {
    srand (time(NULL));
    int opcao;
    int n = 10;
    int vetor[10];

    do {
        printf ("\nEscolha uma opcao:\n");
        printf ("1 - Radix sort com vetor de exemplo\n");
        printf ("2 - Radix sort com vetor aleatorio\n");
        printf ("0 - Sair\n");
        printf ("Opcao: ");

        if (scanf ("%d", &opcao) != 1) {
            printf ("Entrada invalida. Encerrando.\n");
            return 1;
        }

        switch (opcao) {
            case 1: {
                int exemplo[] = {170, 45, 75, 90, 802, 24, 2, 66};
                int tamExemplo = sizeof (exemplo) / sizeof (exemplo[0]);
                radixSort (exemplo, tamExemplo);
                break;
            }
            case 2:
                vetorAleatorio (vetor, n);
                radixSort (vetor, n);
                break;
            case 0:
                printf ("Encerrando.\n");
                break;
            default:
                printf ("Opcao invalida. Escolha 0, 1 ou 2.\n");
        }
    } while (opcao != 0);

    return 0;
}
