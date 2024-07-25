#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

void lerArrayDoArquivo(const char *nomeArquivo, int **arr, int *tamanho) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%d", tamanho) != 1) {
        fprintf(stderr, "Falha ao ler o tamanho do arquivo %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    *arr = (int *)malloc(*tamanho * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *tamanho; i++) {
        if (fscanf(file, "%d", &(*arr)[i]) != 1) {
            fprintf(stderr, "Falha ao ler elemento do arquivo %s\n", nomeArquivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void testarAlgoritmoOrdenacao(void (*funcaoOrdenacao)(int*, int), const char *nomeAlgoritmo, const char *nomeArquivo) {
    int *arr;
    int tamanho;
    lerArrayDoArquivo(nomeArquivo, &arr, &tamanho);

    clock_t inicio, fim;
    double tempo_cpu;

    inicio = clock();
    funcaoOrdenacao(arr, tamanho);
    fim = clock();

    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo usado pelo %s no arquivo %s: %f segundos\n", nomeAlgoritmo, nomeArquivo, tempo_cpu);

    printf("Array ordenado usando %s:\n", nomeAlgoritmo);
    printArray(arr, tamanho);

    free(arr);
}

int main() {
    const char *nomeArquivo = "num.1000.1.in";

    testarAlgoritmoOrdenacao(selectionSort, "Selection Sort", nomeArquivo);
    testarAlgoritmoOrdenacao(insertionSort, "Insertion Sort", nomeArquivo);

    return 0;
}
