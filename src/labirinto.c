#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "labirinto.h"

char get_celula(const Labirinto *lab, int lin, int col) {
    return lab->mapa[lin * lab->colunas + col];
}

void set_celula(Labirinto *lab, int lin, int col, char valor) {
    lab->mapa[lin * lab->colunas + col] = valor;
}

int posicao_valida(const Labirinto *lab, int lin, int col) {
    return lin >= 0 && lin < lab->linhas && col >= 0 && col < lab->colunas;
}

int carregar_labirinto(const char *nomeArquivo, Labirinto *lab) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    char linha[256];
    int linhas = 0;
    int colunas = -1;

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        int tam = (int) strlen(linha);

        if (tam > 0 && linha[tam - 1] == '\n') {
            linha[tam - 1] = '\0';
            tam--;
        }

        if (tam == 0) {
            continue;
        }

        if (colunas == -1) {
            colunas = tam;
        } else if (tam != colunas) {
            printf("Erro: todas as linhas do mapa devem ter o mesmo tamanho.\n");
            fclose(fp);
            return 0;
        }

        linhas++;
    }

    if (linhas <= 0 || linhas > 40 || colunas <= 0 || colunas > 40) {
        printf("Erro: dimensoes do labirinto invalidas ou fora do limite 40x40.\n");
        fclose(fp);
        return 0;
    }

    rewind(fp);

    lab->linhas = linhas;
    lab->colunas = colunas;
    lab->mapa = (char *) malloc(linhas * colunas * sizeof(char));

    if (lab->mapa == NULL) {
        printf("Erro de alocacao do mapa.\n");
        fclose(fp);
        return 0;
    }

    lab->inicioLin = -1;
    lab->inicioCol = -1;

    int i = 0;
    while (fgets(linha, sizeof(linha), fp) != NULL && i < linhas) {
        int tam = (int) strlen(linha);

        if (tam > 0 && linha[tam - 1] == '\n') {
            linha[tam - 1] = '\0';
            tam--;
        }

        if (tam == 0) {
            continue;
        }

        for (int j = 0; j < colunas; j++) {
            lab->mapa[i * colunas + j] = linha[j];

            if (linha[j] == 'P') {
                lab->inicioLin = i;
                lab->inicioCol = j;
            }
        }

        i++;
    }

    fclose(fp);

    if (lab->inicioLin == -1 || lab->inicioCol == -1) {
        printf("Erro: personagem inicial 'P' nao encontrado.\n");
        free(lab->mapa);
        lab->mapa = NULL;
        return 0;
    }

    return 1;
}

void imprimir_labirinto(const Labirinto *lab, int playerLin, int playerCol) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    for (int i = 0; i < lab->linhas; i++) {
        for (int j = 0; j < lab->colunas; j++) {
            if (i == playerLin && j == playerCol) {
                printf("P");
            } else {
                printf("%c", get_celula(lab, i, j));
            }
        }
        printf("\n");
    }

#ifdef _WIN32
    Sleep(150);
#else
    usleep(150000);
#endif
}

int salvar_solucao(const char *nomeArquivo, const Labirinto *lab) {
    FILE *fp = fopen(nomeArquivo, "w");
    if (fp == NULL) {
        printf("Erro ao criar arquivo de saida.\n");
        return 0;
    }

    for (int i = 0; i < lab->linhas; i++) {
        for (int j = 0; j < lab->colunas; j++) {
            fputc(get_celula(lab, i, j), fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
    return 1;
}

void liberar_labirinto(Labirinto *lab) {
    free(lab->mapa);
    lab->mapa = NULL;
}

void limpar_visitados(Labirinto *lab) {
    for (int i = 0; i < lab->linhas; i++) {
        for (int j = 0; j < lab->colunas; j++) {
            if (get_celula(lab, i, j) == '.') {
                set_celula(lab, i, j, ' ');
            }
        }
    }
}