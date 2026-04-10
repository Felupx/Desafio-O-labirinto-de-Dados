#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void push(NoPilha **topo, int lin, int col) {
    NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro de alocacao na pilha.\n");
        return;
    }

    novo->pos.lin = lin;
    novo->pos.col = col;
    novo->prox = *topo;
    *topo = novo;
}

int pop(NoPilha **topo, Posicao *p) {
    if (*topo == NULL) {
        return 0;
    }

    NoPilha *temp = *topo;
    *p = temp->pos;
    *topo = temp->prox;
    free(temp);
    return 1;
}

int pilha_vazia(NoPilha *topo) {
    return topo == NULL;
}

void liberar_pilha(NoPilha **topo) {
    Posicao lixo;
    while (pop(topo, &lixo));
}

void marcar_caminho_no_mapa(NoPilha *topo, char *mapa, int colunas) {
    NoPilha *atual = topo;

    while (atual != NULL) {
        int indice = atual->pos.lin * colunas + atual->pos.col;

        if (mapa[indice] != 'P' && mapa[indice] != 'S') {
            mapa[indice] = '*';
        }

        atual = atual->prox;
    }
}