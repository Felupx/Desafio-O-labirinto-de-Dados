#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"

void inserir_ordenado(NoTesouro **mochila, int valor) {
    NoTesouro *novo = (NoTesouro *) malloc(sizeof(NoTesouro));
    if (novo == NULL) {
        printf("Erro de alocacao na mochila.\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (*mochila == NULL || valor < (*mochila)->valor) {
        novo->prox = *mochila;
        *mochila = novo;
        return;
    }

    NoTesouro *atual = *mochila;
    while (atual->prox != NULL && atual->prox->valor <= valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

int remover_primeiro(NoTesouro **mochila) {
    if (*mochila == NULL) {
        return -1;
    }

    NoTesouro *temp = *mochila;
    int valor = temp->valor;
    *mochila = temp->prox;
    free(temp);

    return valor;
}

int remover_valor(NoTesouro **mochila, int valor) {
    if (*mochila == NULL) {
        return 0;
    }

    NoTesouro *atual = *mochila;
    NoTesouro *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *mochila = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return 1;
}

int somar_mochila(NoTesouro *mochila) {
    int soma = 0;
    while (mochila != NULL) {
        soma += mochila->valor;
        mochila = mochila->prox;
    }
    return soma;
}

void imprimir_mochila(NoTesouro *mochila) {
    printf("Mochila: ");

    if (mochila == NULL) {
        printf("[vazia]\n");
        return;
    }

    printf("[");
    while (mochila != NULL) {
        printf("%d", mochila->valor);
        if (mochila->prox != NULL) {
            printf(" | ");
        }
        mochila = mochila->prox;
    }
    printf("]\n");
}

void liberar_mochila(NoTesouro **mochila) {
    while (*mochila != NULL) {
        remover_primeiro(mochila);
    }
}