#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int lin;
    int col;
} Posicao;

typedef struct NoPilha {
    Posicao pos;
    struct NoPilha *prox;
} NoPilha;

void push(NoPilha **topo, int lin, int col);
int pop(NoPilha **topo, Posicao *p);
int pilha_vazia(NoPilha *topo);
void liberar_pilha(NoPilha **topo);
void marcar_caminho_no_mapa(NoPilha *topo, char *mapa, int colunas);

#endif