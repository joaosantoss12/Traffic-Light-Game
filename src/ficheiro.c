// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "essentials.h"
#include "ficheiro.h"

int existeFile(){
    FILE *f;

    f = fopen("jogo.bin", "rb");
    if(f == NULL) return 0;
    fclose(f);
    return 1;
}

int guardaJogo(pnttabuleiro p, jogador *A, jogador *B){
    FILE *f; // Criar um ponteiro para o ficheiro
    f = fopen("jogo.bin", "wb"); // Abrir o ficheiro "jogo.bin" no modo de escrita binária
    if(f == NULL) return 0; // Se algum erro tiver surgido retorna 0

    fwrite(A, sizeof(jogador), 1, f); // Escreve a struct referente ao jogador A
    fwrite(B, sizeof(jogador), 1, f); // Escreve a struct referente ao jogador B
    while(p != NULL){ // Percorre a lista ligada até ao último elemento
        fwrite(p, sizeof(tabu), 1, f); // Escreve o elemento da lista ligada
        for(int j = 0; j<p->linhas; j++) // Percorre o tabuleiro do elemento atual
            fwrite(p->tab[j], p->colunas*sizeof(char), 1, f ); // Escreve o tabuleiro desse elemento da lista ligada
        p = p->proximo; // Avança para o próximo elemento da lista ligada
    }

    fclose(f); // Fecha o ficheiro
    return 1; // Retorna o sucesso da operação
}

pnttabuleiro recuperaJogo(jogador *A, jogador *B){
    FILE *f; // Criar um ponteiro para o ficheiro
    tabu *p = NULL, novo; // Criar uma lista ligada para colocar as sucessões do jogo anterior e uma variável auxiliar

    f = fopen("jogo.bin", "rb"); // Abrir o ficheiro "jogo.bin" no modo leitura binária
    if(f == NULL) return 0; // Se algum erro tiver surgido retorna 0

    char **tabuleiro; // Cria uma variável para armazenar o tabuleiro
    tabuleiro = gerarTab(9, 9); // Aloca memória para receber o tabuleiro

    fread(A, sizeof(jogador), 1, f); // Lê a struct referente ao jogador A
    fread(B, sizeof(jogador), 1, f); // Lê a struct referente ao jogador B
    while(fread(&novo, sizeof(tabu), 1, f) > 0){ // Lê os elementos da lista ligada para a variável novo enquanto existir coisas para ler
        novo.tab = tabuleiro; // A memória alocada passa para a variável que vai receber o tabuleiro

        for(int j = 0; j<novo.linhas; j++) // Percorre o tabuleiro guardado
            fread(novo.tab[j], novo.colunas*sizeof(char), 1, f ); // Lê o tabuleiro para a variável "novo.tab"

        // Adiciona este novo objeto ao final da lista ligada
        p = insere_novo(p, novo.tab, novo.linhas, novo.colunas, novo.njogada, novo.jogador, novo.jogada, novo.linhaJogada, novo.colunaJogada);
    }

    fclose(f); // Fecha o ficheiro
    return p; // Retorna um ponteiro para o início da lista ligada que foi recuperada
}

int exportarJogo(char *ficheiro, pnttabuleiro p){
    ficheiro[strlen(ficheiro) - 1] = '\0'; // Adiciona um ESCAPE CHARACTER para tornar o array numa string válida
    char extension[5] = ".txt"; // Array que contém a string que representa o formato do ficheiro (.txt)
    strcat(ficheiro, extension); // Concatena o nome do ficheiro e a extensão do ficheiro

    FILE *f; // Criar um ponteiro para o ficheiro
    f = fopen(ficheiro, "w+"); // Criar o ficheiro e abri-lo no modo de escrita
    if(f == NULL) return 0; // Se algum erro tiver surgido retorna 0

    int lin, col, linJogada, colJogada, jogada, n_jogada; // Decalração das variáveis para armazenaram informação em cada iteração
    char jogador, nome; // Decalração das variáveis para armazenaram informação em cada iteração
    char **tabuleiro; // Variável onde o tabuleiro vai ser guardado em cada iteração
    while(p != NULL){ // Enquanto o elemento atual não for NULO
        tabuleiro = p->tab;
        lin = p->linhas;
        col = p->colunas;
        n_jogada = p->njogada;
        jogador = p->jogador;
        jogada = p->jogada;
        linJogada = p->linhaJogada;
        colJogada = p->colunaJogada;

        fprintf(f, "JOGADA %d\n", n_jogada); // Escreve o número da jogada no ficheiro
        if(jogador == 'A') nome = 'A'; // Escreve o nome do jogador A na jogada atual no ficheiro (caso a jogada tenha sido feita pelo jogador A)
        else if(jogador == 'B') nome = 'B'; // Escreve o nome do jogador B na jogada atual no ficheiro (caso a jogada tenha sido feita pelo jogador B)
        else nome = '\0'; // Caso contrário o nome do jogador é NULO

        // Inclui uma mensagem com o detalhe do que é que aconteceu na jogada atual

        if(jogada == 4) fprintf(f, "O jogador %c colocou uma pedra na linha: %d e coluna: %d\n", nome, linJogada, colJogada);
        else if(jogada == 5 || jogada==6) fprintf(f, "O jogador %c expandiu o tabuleiro\n", nome);
        else if(jogada == 1) fprintf(f, "O jogador %c colocou uma peca verde na linha: %d e coluna: %d\n", nome, linJogada, colJogada);
        else if(jogada == 2) fprintf(f, "O jogador %c colocou uma peca amarela na linha: %d e coluna: %d\n", nome, linJogada, colJogada);
        else if(jogada == 3) fprintf(f, "O jogador %c colocou uma peca vermelha na linha: %de coluna: %d\n", nome, linJogada, colJogada);
        else fprintf(f, "ERRO! O jogador %c realizou uma jogada invalida!\n", nome);

        for(int i = 0; i < lin; i++){ // Percorre as linhas do tabuleiro
            for(int j = 0; j < col; j++){ // Percorre as colunas do tabuleiro
                fprintf(f, "%c ", tabuleiro[i][j]); // Escreve o tabuleiro no ficheiro
            }
            fprintf(f, "\n"); // Escreve uma linha em branco no ficheiro
        }
        fprintf(f, "\n\n"); // Escreve duas linhas em branco no ficheiro
        p = p->proximo; // Salta para o próximo elemento da lista ligada
    }

    fclose(f); // Fecha o ficheiro
    return 1; // Retorna o sucesso da operação
}
