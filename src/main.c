#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "labirinto.h"
#include "pilha.h"
#include "mochila.h"
#include "busca.h"

static void aguardar_enter(void) {
    int c;

    printf("\nPressione Enter para continuar para o proximo mapa...");
    fflush(stdout);

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

static void processar_mapa(const char *nomeMapa, const char *nomeSaida) {
    Labirinto lab;
    NoPilha *caminho = NULL;
    NoTesouro *mochila = NULL;

    if (!carregar_labirinto(nomeMapa, &lab)) {
        printf("Erro ao carregar %s\n", nomeMapa);
        return;
    }

    if (buscar_saida(&lab, lab.inicioLin, lab.inicioCol, &caminho, &mochila)) {
        printf("\n==============================\n");
        printf("LABIRINTO RESOLVIDO COM SUCESSO\n");
        printf("Mapa: %s\n", nomeMapa);
        printf("Valor final acumulado: %d\n", somar_mochila(mochila));
        printf("==============================\n");

        limpar_visitados(&lab);
        marcar_caminho_no_mapa(caminho, lab.mapa, lab.colunas);
        imprimir_labirinto(&lab, -1, -1);

        if (salvar_solucao(nomeSaida, &lab)) {
            printf("Arquivo de saida salvo com sucesso em %s\n", nomeSaida);
        }
    } else {
        printf("\n==============================\n");
        printf("NAO FOI POSSIVEL ENCONTRAR A SAIDA\n");
        printf("Mapa: %s\n", nomeMapa);
        printf("==============================\n");
        imprimir_labirinto(&lab, -1, -1);
    }

    aguardar_enter();

    liberar_pilha(&caminho);
    liberar_mochila(&mochila);
    liberar_labirinto(&lab);
}

int main() {
    srand((unsigned) time(NULL));

    processar_mapa("mapas/labirinto1.txt", "output/saida_labirinto1.txt");
    processar_mapa("mapas/labirinto2.txt", "output/saida_labirinto2.txt");
    processar_mapa("mapas/labirinto3.txt", "output/saida_labirinto3.txt");

    return 0;
}
