#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->dados = (int*)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

void destruir_pilha(Pilha* pilha) {
    free(pilha->dados);
    free(pilha);
}

int esta_vazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha* pilha, int valor) {
    pilha->dados[++pilha->topo] = valor;
}

int desempilhar(Pilha* pilha) {
    return pilha->dados[pilha->topo--];
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;
    int j;

    for (j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    return (i + 1);
}

void quicksort_nao_recursivo(int arr[], int n) {
    Pilha* pilha = criar_pilha(n);

    empilhar(pilha, 0);
    empilhar(pilha, n - 1);

    while (!esta_vazia(pilha)) {
        int alto = desempilhar(pilha);
        int baixo = desempilhar(pilha);

        int pivo = particionar(arr, baixo, alto);

        if (pivo - 1 > baixo) {
            empilhar(pilha, baixo);
            empilhar(pilha, pivo - 1);
        }

        if (pivo + 1 < alto) {
            empilhar(pilha, pivo + 1);
            empilhar(pilha, alto);
        }
    }

    destruir_pilha(pilha);
}

int main() {

    int n,i;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort_nao_recursivo(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

