# O Labirinto de Dados

Projeto acadêmico desenvolvido em linguagem C para a disciplina de **Estrutura de Dados**.

O sistema simula um jogo de exploração arqueológica em que um caçador de tesouros deve atravessar um labirinto, coletar tesouros, enfrentar armadilhas e encontrar a saída com o maior valor acumulado possível.

---

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

---

## Funcionamento do jogo

O labirinto é carregado por meio de um arquivo texto, em que cada caractere representa um elemento do mapa:

- `#` = parede  
- ` ` = corredor  
- `P` = posição inicial do personagem  
- `T` = tesouro  
- `A` = armadilha  
- `S` = saída  

> Observação:  
> O arquivo do labirinto não contém as dimensões (linhas e colunas).  
> O sistema identifica automaticamente o tamanho do mapa ao ler o arquivo.

Durante a exploração:

- O personagem percorre o labirinto em busca da saída
- Cada tesouro encontrado recebe um valor aleatório entre **1 e 100**
- Os tesouros são armazenados na mochila (lista ordenada)
- Ao cair em uma armadilha, o personagem perde o tesouro da **primeira posição da mochila**
- Para reduzir perdas, os menores valores permanecem na frente da mochila

Durante a execução, o sistema exibe no terminal:

- O estado atual do labirinto a cada movimento
- Eventos de exploração (movimento, tesouro, armadilha)
- Conteúdo atualizado da mochila
- Valor total acumulado em tempo real

---

## Arquivo de saída

Ao final da execução, o sistema gera um arquivo `saida.txt` na pasta `output/`, contendo o labirinto com o caminho correto da entrada até a saída marcado com `*`.

---

## Estruturas de dados e conceitos utilizados

Este projeto foi desenvolvido com foco nos seguintes conceitos:

- Ponteiros
- Listas encadeadas (mochila)
- Pilhas (controle do caminho)
- Algoritmo de busca com backtracking
- Alocação dinâmica de memória
- Manipulação de arquivos

---

## Requisitos do projeto

O sistema atende aos seguintes requisitos:

- Implementação em **linguagem C**
- Leitura do labirinto a partir de arquivo `.txt`
- Exibição passo a passo da travessia no terminal
- Gerenciamento dinâmico da mochila
- Cálculo do valor total dos tesouros
- Geração de arquivo de saída com a solução final

---

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
├── mapas/
│   ├── labirinto1.txt
│   └── labirinto2.txt
├── output/
│   └── saida.txt
├── docs/
│   └── Projeto-AC2-Estrutura-de-Dados.pdf
├── README.md
└── .gitignore