#include "sorts.h"
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, indice_min;
    for (i = 0; i < n-1; i++) {
        indice_min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[indice_min])
                indice_min = j;
        int temp = arr[indice_min];
        arr[indice_min] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
