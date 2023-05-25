// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#ifndef FICHEIRO_H
#define FICHEIRO_H

#include "essentials.h"

int existeFile();

int guardaJogo(pnttabuleiro p, jogador *A, jogador *B);

pnttabuleiro recuperaJogo(jogador *A, jogador *B);

int exportarJogo(char *ficheiro, pnttabuleiro p);

#endif //FICHEIRO_H
