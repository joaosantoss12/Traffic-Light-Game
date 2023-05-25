// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#ifndef ESSENTIALS_H
#define ESSENTIALS_H

// ESTRUTURA PARA GUARDAR DADOS DOS JOGADORES

typedef struct JOGADOR jogador;
struct JOGADOR{
    char jogador;
};

// ESTRUTURA PARA GUARDAR AS JOGADAS DO JOGO

typedef struct dados tabu, *pnttabuleiro;
struct dados
{
    char **tab;             // ponteiro para o inicio do tabuleiro
    int linhas;             // Número de linhas
    int colunas;            // Número de colunas
    char jogador;           // Caracter do jogador
    int jogada;             // Jogada realizada
    int linhaJogada, colunaJogada;  // Linha e coluna escolhidas na jogada
    int njogada;            // Número da jogada
    pnttabuleiro proximo;      // ponteiro para o próximo elemento
};

char **gerarTab(int a, int b);                          // Função para gerar o tabuleiro
// Recebe o número de linhas e colunas como parâmetros
// Retorna o tabuleiro já gerado

void mostrarTab(int a, int b, char **c);                // Função para mostrar todo o tabuleiro (incluindo as peças jogadas)
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna o tabuleiro

char **expandirLin(int a, int b, char **c);             // Função para realocar uma nova linha no tabuleiro (jogada 5)
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna o tabuleiro atualizado com +1 linha

char **expandirCol(int a, int b, char **c);             // Função para realocar uma nova coluna no tabuleiro (jogada 6)
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna o tabuleiro atualizado com +1 coluna

void delay(int a);                                      // Função para fazer o programa aguradar x segundos antes de avançar no código
// Recebe o número de segundos desejados para que o programa aguarde

int verifica_linha(int a, int b, char **c);             // Função para detetar vitória através de uma linha
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna 1 em caso de vitória por linha, ou 0 caso não seja verificada uma vitória nessa jogada

int verifica_coluna(int a, int b, char **c);            // Função para detetar vitória através de uma coluna
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna 1 em caso de vitória por coluna, ou 0 caso não seja verificada uma vitória nessa jogada

int verifica_diagonalPrin(int a, int b, char **c);      // Função para detetar vitória através da diagonal principal
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna 1 em caso de vitória pela diagonal principal, ou 0 caso não seja verificada uma vitória nessa jogada

int verifica_diagonalSec(int a, int b, char **c);       // Função para detetar vitória através da diagonal secundária
// Recebe o número de linhas e colunas e um ponteiro para o tabuleiro como parâmetros
// Retorna 1 em caso de vitória pela diagonal secundária, ou 0 caso não seja verificada uma vitória nessa jogada

int terminar(int a, int b, char **c, char d);           // Função para detetar o fim do jogo (depois de haver uma vitória)
// Recebe o número de linhas e colunas, um ponteiro para o tabuleiro e o caracter de indentificação do jogador como parâmetros
// Retorna 1 caso detete o final de um jogo (em caso de vitória), ou 0 caso não seja detetado o final do jogo (não há vitória nessa jogada)

int inverteLista(pnttabuleiro p, int c);              // Procura o elemento na lista ligada (número da jogada)
// Recebe um ponteiro para o inicio da lista ligada e o número da jogada a ser procurada
// Retorna 1 se o elemento for encontrado na lista ligada ou 0 se não for encontrado

void preencheLista(pnttabuleiro p, char **tabuleiro, int lin, int col, int i, char jogador, int jogada, int linJogada, int colJogada);           // Preenche a lista ligada com a informação recebida
// Recebe um ponteiro para o inicio da lista ligada, um para o tabuleiro, numero de linhas, numero de colunas, o numero de jogadas, identificador do jogador, numero da jogada, numero da linha jogada e da coluna jogada

pnttabuleiro insere_novo(pnttabuleiro p, char **tabuleiro, int l, int c, int i, char jogador, int jogada, int linJogada, int colJogada);   // Alocação de memória para um novo elemento que é colocado no final da lista ligada
// Recebe um ponteiro para o inicio da lista ligada, um para o tabuleiro, o numero de linhas e colunas, o caracter de indentificaçao do jogador, a jogada realizada, a linha e coluna jogadas
// Retorna um ponteiro para o inicio da lista ligada mas com o novo elemento inserido no final

int nElementos(pnttabuleiro p);                        // Obtém o número de elementos da lista ligada
// Recebe um ponteiro para o inicio da lista ligada
// Retorna o número de elementos na lista ligada

void liberta_memLista(pnttabuleiro p);                     // Liberta a memória alocada para a lista ligada
// Recebe um ponteiro para o inicio da lista ligada

#endif //ESSENTIALS_H