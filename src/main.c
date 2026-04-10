#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "labirinto.h"
#include "pilha.h"
#include "mochila.h"
#include "busca.h"

int main() {
    Labirinto lab;
    NoPilha *caminho = NULL;
    NoTesouro *mochila = NULL;

    srand((unsigned) time(NULL));

    if (!carregar_labirinto("mapas/labirinto1.txt", &lab)) {
        return 1;
    }

    if (buscar_saida(&lab, lab.inicioLin, lab.inicioCol, &caminho, &mochila)) {
        printf("\nSaida encontrada!\n");
        printf("Valor final acumulado: %d\n", somar_mochila(mochila));

        limpar_visitados(&lab);
        marcar_caminho_no_mapa(caminho, lab.mapa, lab.colunas);

        if (salvar_solucao("output/saida.txt", &lab)) {
            printf("Arquivo de saida salvo com sucesso em output/saida.txt\n");
        }
    } else {
        printf("\nNao foi possivel encontrar a saida.\n");
    }

    liberar_pilha(&caminho);
    liberar_mochila(&mochila);
    liberar_labirinto(&lab);

    return 0;
}