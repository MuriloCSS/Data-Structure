#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* criar_pilha(int capacidade);
void destruir_pilha(Pilha* pilha);
int esta_vazia(Pilha* pilha);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);

#endif

