# O Labirinto de Dados

Projeto acadêmico desenvolvido em linguagem C para a disciplina de **Estrutura de Dados**.

O sistema simula um jogo de exploração arqueológica em que um caçador de tesouros deve atravessar um labirinto, coletar tesouros, enfrentar armadilhas e encontrar a saída com o maior valor acumulado possível.

## Objetivo

Desenvolver o motor lógico de um jogo em C capaz de:

- Ler um labirinto a partir de um arquivo `.txt`
- Representar o mapa internamente
- Encontrar a saída utilizando um algoritmo de busca
- Coletar tesouros com valores aleatórios
- Gerenciar uma mochila com os tesouros encontrados
- Aplicar a lógica das armadilhas
- Exibir o percurso no terminal em formato texto
- Gerar um arquivo `.txt` de saída com o caminho correto encontrado

## Funcionamento do jogo

O labirinto é carregado por meio de um arquivo texto, em que cada caractere representa um elemento do mapa:

- `#` = parede
- ` ` = corredor
- `P` = posição inicial do personagem
- `T` = tesouro
- `A` = armadilha
- `S` = saída

Durante a exploração:

- O personagem percorre o labirinto em busca da saída
- Cada tesouro encontrado recebe um valor aleatório entre **1 e 100**
- Os tesouros são armazenados na mochila
- Ao cair em uma armadilha, o personagem perde o tesouro da **primeira posição da mochila**
- Para reduzir perdas, os menores valores devem permanecer na frente da mochila

## Estruturas de dados e conceitos utilizados

Este projeto foi proposto com foco no uso de conceitos da disciplina de Estrutura de Dados, incluindo:

- Ponteiros
- Listas
- Pilhas
- Algoritmo de ordenação, se necessário
- Algoritmo de busca para percorrer o labirinto, como backtracking

## Requisitos do projeto

O sistema deve atender aos seguintes requisitos:

- Ser implementado em **linguagem C**
- Ler o layout do labirinto de um arquivo `.txt`
- Exibir visualmente o passo a passo da travessia no terminal
- Mostrar o conteúdo atual da mochila
- Exibir o valor total dos tesouros ao encontrar a saída
- Salvar a solução final em outro arquivo `.txt`

## Estrutura do projeto

```text
Desafio-O-labirinto-de-dados/
├── src/
│   ├── main.c
│   ├── labirinto.c
│   ├── mochila.c
│   ├── busca.c
│   └── pilha.c
├── include/
│   ├── labirinto.h
│   ├── mochila.h
│   ├── busca.h
│   └── pilha.h
├── data/
│   ├── labirinto.txt
│   └── saida.txt
├── docs/
│   └── Projeto-AC2-Estrutura-de-Dados.pdf
├── README.md
└── .gitignore