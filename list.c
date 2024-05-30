#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void inicializar_fila(t_fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

int fila_vazia(t_fila *fila) {
    return fila->tamanho == 0;
}

int fila_cheia(t_fila *fila) {
    return fila->tamanho == MAX;
}

void enfileirar(t_fila *fila, t_cliente cliente) {
    if (!fila_cheia(fila)) {
        fila->clientes[fila->fim] = cliente;
        fila->fim = (fila->fim + 1) % MAX;
        fila->tamanho++;
    } else {
        printf("Fila está cheia\n");
    }
}

t_cliente desenfileirar(t_fila *fila) {
    t_cliente cliente = {"", '\0'};
    if (!fila_vazia(fila)) {
        cliente = fila->clientes[fila->inicio];
        fila->inicio = (fila->inicio + 1) % MAX;
        fila->tamanho--;
    }
    return cliente;
}
