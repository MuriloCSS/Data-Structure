#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct {
    char nome[50];
    char tipo;  // 'p' para prioridade, 'g' para geral
} t_cliente;

typedef struct {
    t_cliente clientes[MAX];
    int inicio;
    int fim;
    int tamanho;
} t_fila;

// Declarações de funções
void inicializar_fila(t_fila *fila);
int fila_vazia(t_fila *fila);
int fila_cheia(t_fila *fila);
void enfileirar(t_fila *fila, t_cliente cliente);
t_cliente desenfileirar(t_fila *fila);

#endif
