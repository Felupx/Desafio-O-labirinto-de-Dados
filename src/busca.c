#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

int buscar_saida(Labirinto *lab, int lin, int col, NoPilha **caminho, NoTesouro **mochila) {
    if (!posicao_valida(lab, lin, col)) {
        return 0;
    }

    char atual = get_celula(lab, lin, col);

    if (atual == '#' || atual == '.') {
        return 0;
    }

    push(caminho, lin, col);

    if (atual == 'S') {
        return 1;
    }

    int tesouro_encontrado = -1;
    int tesouro_removido = -1;

    if (atual == 'T') {
        tesouro_encontrado = rand() % 100 + 1;
        inserir_ordenado(mochila, tesouro_encontrado);
    } else if (atual == 'A') {
        tesouro_removido = remover_primeiro(mochila);
    }

    if (atual != 'P') {
        set_celula(lab, lin, col, '.');
    }

    imprimir_labirinto(lab, lin, col);
    imprimir_mochila(*mochila);
    printf("Valor total: %d\n", somar_mochila(*mochila));

    if (buscar_saida(lab, lin - 1, col, caminho, mochila) ||
        buscar_saida(lab, lin + 1, col, caminho, mochila) ||
        buscar_saida(lab, lin, col - 1, caminho, mochila) ||
        buscar_saida(lab, lin, col + 1, caminho, mochila)) {
        return 1;
    }

    if (tesouro_encontrado != -1) {
        remover_valor(mochila, tesouro_encontrado);
    }

    if (tesouro_removido != -1) {
        inserir_ordenado(mochila, tesouro_removido);
    }

    Posicao p;
    pop(caminho, &p);

    return 0;
}