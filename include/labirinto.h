#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct {
    char *mapa;
    int linhas;
    int colunas;
    int inicioLin;
    int inicioCol;
} Labirinto;

int carregar_labirinto(const char *nomeArquivo, Labirinto *lab);
void imprimir_labirinto(const Labirinto *lab, int playerLin, int playerCol);
int salvar_solucao(const char *nomeArquivo, const Labirinto *lab);
int posicao_valida(const Labirinto *lab, int lin, int col);
char get_celula(const Labirinto *lab, int lin, int col);
void set_celula(Labirinto *lab, int lin, int col, char valor);
void liberar_labirinto(Labirinto *lab);
void limpar_visitados(Labirinto *lab);

#endif