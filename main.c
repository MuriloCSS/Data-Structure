#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    t_fila fila_geral, fila_prioridade;
    inicializar_fila(&fila_geral);
    inicializar_fila(&fila_prioridade);

    char comando[10];
    t_cliente cliente;
    int contador_prioridade = 0;
    t_cliente clientes_atendidos[MAX];
    int cont_atendidos = 0;

    while (1) {
        scanf("%s", comando);
        if (strcmp(comando, "g") == 0) {
            scanf("%s", cliente.nome);
            cliente.tipo = 'g';
            enfileirar(&fila_geral, cliente);
        } else if (strcmp(comando, "p") == 0) {
            scanf("%s", cliente.nome);
            cliente.tipo = 'p';
            enfileirar(&fila_prioridade, cliente);
        } else if (strcmp(comando, "s") == 0) {
            if (!fila_vazia(&fila_prioridade) && (contador_prioridade < 3 || fila_vazia(&fila_geral))) {
                cliente = desenfileirar(&fila_prioridade);
                contador_prioridade++;
            } else if (!fila_vazia(&fila_geral)) {
                cliente = desenfileirar(&fila_geral);
                contador_prioridade = 0;
            }
            clientes_atendidos[cont_atendidos++] = cliente;
        } else if (strcmp(comando, "f") == 0) {
            break;
        }
    }

    while (!fila_vazia(&fila_prioridade)) {
        cliente = desenfileirar(&fila_prioridade);
        clientes_atendidos[cont_atendidos++] = cliente;
    }

    while (!fila_vazia(&fila_geral)) {
        cliente = desenfileirar(&fila_geral);
        clientes_atendidos[cont_atendidos++] = cliente;
    }

    for (int i = 0; i < cont_atendidos; i++) {
        printf("%s\n", clientes_atendidos[i].nome);
    }

    return 0;
}
