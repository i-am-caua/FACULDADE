#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap (int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void printVtr (int *vtr, int tam) {
    for (int i = 0; i < tam; i++) {
        printf ("%d ", vtr[i]);
    }
    printf("\n");
}
void vetorAleatorio (int *vtr, int tam) {
    for (int i = 0; i < tam; i++) {
        vtr[i] = (rand() % 100) + 1;
    }
}

void bubleSort (int *vtr, int tam) {
    printVtr(vtr, tam);
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vtr[j] > vtr[j + 1]) {
                swap (&vtr[j], &vtr[j + 1]);
            }
        }
        printVtr(vtr, tam);    
    }
}
void selectSort (int *vtr, int tam) {
    int menor;
    printVtr(vtr, tam);
    for (int i = 0; i < tam - 1; i++) {
        menor = i;
        for (int j = i; j < tam - 1; j++) {
            if (vtr[j + 1] < vtr[menor]) {
                menor = j + 1;
            }
        }
        swap (&vtr[i], &vtr[menor]);
        printVtr(vtr, tam);
    }
}

void insertionSort (int *vtr, int tam) {
    printVtr(vtr, tam);

    for (int i = 1; i < tam; i++) {
        int chave = vtr[i];
        int j = i - 1;

        while (j >= 0 && vtr[j] > chave) {
            vtr[j + 1] = vtr[j];
            j--;
            printVtr(vtr, tam); 
        }

        vtr[j + 1] = chave;
        printVtr(vtr, tam); 
    }
}

void shellSort (int *vtr, int tam) {
    printVtr(vtr, tam);

    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int chave = vtr[i];
            int j = i - gap;

            while (j >= 0 && vtr[j] > chave) {
                vtr[j + gap] = vtr[j];
                j -= gap;
                printVtr(vtr, tam);
            }

            vtr[j + gap] = chave;
            printVtr(vtr, tam);
        }
    }
}

void merge (int *vtr, int metade, int tam) {
    int i = 0;
    int j = metade;
    int k = 0;
    int *temp = malloc (tam * sizeof (int));

    if (temp == NULL) {
        printf ("Erro de alocacao de memoria no merge.\n");
        return;
    }

    while (i < metade && j < tam) {
        if (vtr[i] <= vtr[j]) {
            temp[k++] = vtr[i++];
        } else {
            temp[k++] = vtr[j++];
        }
    }

    while (i < metade) {
        temp[k++] = vtr[i++];
    }

    while (j < tam) {
        temp[k++] = vtr[j++];
    }

    for (int p = 0; p < tam; p++) {
        vtr[p] = temp[p];
    }

    free (temp);
    printVtr (vtr, tam);
}

void mergeSort (int *vtr, int tam) {
    if (tam <= 1) return;

    int metade = tam / 2;
    mergeSort (vtr, metade);
    mergeSort (vtr + metade, tam - metade);
    merge (vtr, metade, tam);
}

int main () {
    srand (time(NULL));
    int n = (rand() % 11) + 10;
    int vetor[n];
    int opcao;

    do {
        printf("\nEscolha o algoritmo de ordenacao:\n");
        printf("1 - Bubble sort\n");
        printf("2 - Selection sort\n");
        printf("3 - Insertion sort\n");
        printf("4 - Shell sort\n");
        printf("5 - Merge sort\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Encerrando.\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                vetorAleatorio(vetor, n);
                printf("Vetor antes do bubble sort:\n");
                bubleSort(vetor, n);
                break;
            case 2:
                vetorAleatorio(vetor, n);
                printf("Vetor antes do selection sort:\n");
                selectSort(vetor, n);
                break;
            case 3:
                vetorAleatorio(vetor, n);
                printf("Vetor antes do insertion sort:\n");
                insertionSort(vetor, n);
                break;
            case 4:
                vetorAleatorio(vetor, n);
                printf("Vetor antes do shell sort:\n");
                shellSort(vetor, n);
                break;
            case 5:
                vetorAleatorio(vetor, n);
                printf("Vetor antes do merge sort:\n");
                printVtr(vetor, n);
                mergeSort(vetor, n);
                break;
            case 0:
                printf("Encerrando.\n");
                break;
            default:
                printf("Opcao invalida. Escolha de 0 a 5.\n");
        }
    } while (opcao != 0);

    return 0;
}
