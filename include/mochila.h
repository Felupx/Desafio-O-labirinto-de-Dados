#ifndef MOCHILA_H
#define MOCHILA_H

typedef struct NoTesouro {
    int valor;
    struct NoTesouro *prox;
} NoTesouro;

void inserir_ordenado(NoTesouro **mochila, int valor);
int remover_primeiro(NoTesouro **mochila);
int remover_valor(NoTesouro **mochila, int valor);
int somar_mochila(NoTesouro *mochila);
void imprimir_mochila(NoTesouro *mochila);
void liberar_mochila(NoTesouro **mochila);

#endif