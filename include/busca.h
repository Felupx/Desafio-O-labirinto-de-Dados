#ifndef BUSCA_H
#define BUSCA_H

#include "labirinto.h"
#include "pilha.h"
#include "mochila.h"

int buscar_saida(Labirinto *lab, int lin, int col, NoPilha **caminho, NoTesouro **mochila);

#endif