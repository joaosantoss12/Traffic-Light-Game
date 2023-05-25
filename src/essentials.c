// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "essentials.h"

char **gerarTab(int linhas,int colunas){
    int i,j;            // Variáveis auxiliares para percorrer o tabuleiro
    char **tabuleiro;   // Variável para armazenar o tabuleiro

    tabuleiro=(char**)malloc(sizeof(char*)*linhas); // Alocação de memória das linhas (cada uma com tamanho para um char*) do tabuleiro

    if(tabuleiro==NULL){    // Caso não haja memória disponivel
        printf("Erro na alocacao de memoria!"); // Erro
        exit(0);
    }

    for(i=0;i<linhas;i++){  // Para cada linha do tabuleiro
        tabuleiro[i]=(char *)malloc(sizeof(char)*colunas);  // Alocação de memória para colunas(cada uma com tamanho para um char)

        if(tabuleiro[i]==NULL){ // Caso não haja memória disponivel
            printf("Erro na alocacao de memoria!"); // Erro
            exit(0);
        }
    }

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){     // Percorrer todas as linhas e colunas do tabuleiro
            tabuleiro[i][j]='-';    // Colocar o caracter '-' em todos os espaços do tabuleiro (torná-lo vazio)
        }
    }
    return tabuleiro;   // Retorna ponteiro para o início do tabuleiro de jogo
}

void mostrarTab(int lin,int col,char **tab){
    int i,j;    // Variáveis auxiliares

    printf("\n");
    printf("   TABULEIRO:\n");
    printf("   ----------\n\n");
    for(int u=0;u<col;u++){         // Para cada coluna:
        printf("\t C%d  ",u+1);     // Adicionar informação sobre o número da coluna
    }
        printf("\n\n");

    for(i=0;i<lin;i++){             // Para cada linha:
        printf("   L%d  ",i+1);     // Adicionar informação sobre o número da linha
        for(j=0;j<col;j++){
            printf("\t %c  ",tab[i][j]);    // Colocar na posição, o caracter correspondente
        }
        printf("\n");
    }
}

char **expandirLin(int lin, int col, char **tab)
{
    int j;          // Variável auxiliar
    char **auxl;    // Variável para alojar o tabuleiro

        auxl=(char**)realloc(tab,sizeof(char*)*lin);    // Realocação de memória para o número de linhas
        if(auxl==NULL){ // Caso não haja memória disponivel:
            printf("  Erro na realocacao de memoria!\n\n"); // Erro
            exit(0);
        }

        auxl[lin-1]=(char*)malloc(sizeof(char)*col);  // Alocação de memória para as colunas da nova linha
        if(auxl[lin-1]==NULL){    // Caso não haja memória disponivel:
            printf("  Erro na realocacao de memoria!\n\n"); // Erro
            exit(0);
        }

        tab=auxl;

        for(j=0;j<col;j++){     // Para todas as colunas (as novas colunas da nova linha)
            tab[lin-1][j]='-';  // Colocar o caracter '-' (como se um "espaço" vazio)
        }

    return tab;
}

char **expandirCol(int lin, int col, char **tab)
{
    int i;      // Variável auxiliar
    char *auxc; // Variável auxiliar para alojar o tabuleiro

        for(i=0;i<lin;i++){ // Para todas as linhas
            auxc=(char*)realloc(tab[i],sizeof(char)*col);   // Realocar memória para as "novas" colunas
        }
        if(auxc==NULL){ // Caso não haja memória disponivel:
            printf("  Erro na realocacao de memoria!\n\n"); // Erro
            exit(0);
        }
        tab[i]=auxc;

        for(i=0;i<lin;i++){ // Para todas as linhas (da nova coluna)
            tab[i][col-1]='-';  // Colocar o caracter '-' nesses "espaços" (como se estivesse "vazio")
        }

    return tab;
}

void delay(int segundos)                                // Função delay para que o programa aguarde a avançar para a próxima linha de código
{                                                       // ou seja, aguarde para avançar para a próxima "ordem"
    // Converting time into milli_seconds               // Útil para por exemplo, após uma mensagem de erro ou qualquer mensagem que o programa
    int milli_seconds = 1000 * segundos;                // mostre ao utilizador, este ter tempo de a ler e interpretar

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int verifica_linha(int lin,int col,char **tab){

    int contadorG=0, contadorY=0, contadorR=0;  // Variáveis auxiliares para detetar vitória

    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){ // Percorrer todo o tabuleiro
            if(tab[i][j]=='G'){ // Se um "espaço" do tabuleiro tiver o caracter 'G' (peça verde)
                contadorG++;    // Incrementar o contador de peças verdes no tabuleiro
            }
            if(tab[i][j]=='Y'){ // Se um "espaço" do tabuleiro tiver o caracter 'Y' (peça amarela)
                contadorY++;    // Incrementar o contador de peças amarelas no tabuleiro
            }
            if(tab[i][j]=='R'){ // Se um "espaço" do tabuleiro tiver o caracter 'R' (peça vermelha)
                contadorR++;    // Incrementar o contador de peças vermelhas no tabuleiro
            }
        }
        if(contadorG==col || contadorY==col || contadorR==col){ // Se algum dos contadores for igual ao número de colunas,
            return 1;   // retorna 1 (indica que houve unma vitória)
        }
        contadorG=0;
        contadorY=0;    // Reseta todos os contadores para depois de verificar todas as colunas, passe a verificar todas essas mesmas colunas mas para uma linha diferente
        contadorR=0;
    }
    return 0;
}

int verifica_coluna(int lin,int col,char **tab){

    int contadorG=0, contadorY=0, contadorR=0;  // Variáveis auxiliares para detetar vitória

    for(int j=0;j<col;j++){
        for(int i=0;i<lin;i++){ // Percorrer todo o tabuleiro
            if(tab[i][j]=='G'){ // Se um "espaço" do tabuleiro tiver o caracter 'G' (peça verde)
                contadorG++;    // Incrementar o contador de peças verdes no tabuleiro
            }
            if(tab[i][j]=='Y'){ // Se um "espaço" do tabuleiro tiver o caracter 'Y' (peça amarela)
                contadorY++;    // Incrementar o contador de peças amarelas no tabuleiro
            }
            if(tab[i][j]=='R'){ // Se um "espaço" do tabuleiro tiver o caracter 'R' (peça vermelha)
                contadorR++;    // Incrementar o contador de peças vermelhas no tabuleiro
            }
        }
        if(contadorG==lin || contadorY==lin || contadorR==lin){ // Se algum dos contadores for igual ao número de linhas,
            return 1;   // retorna 1 (indica que houve unma vitória)
        }
        contadorG=0;
        contadorY=0;
        contadorR=0;
    }
    return 0;
}

int verifica_diagonalPrin(int lin,int col,char **tab){

    if(lin!=col){   // Caso o número de linhas seja diferente do número de colunas, então é impossivel haver vitória através da diagonal
        return 0;
    }

    int contadorG=0, contadorY=0, contadorR=0; // Variáveis auxiliares para detetar vitória

    for(int i=0;i<lin;i++){ // Uso de apenas uma variável pois os "espaços" da diagonal têm sempre o número da linha igual ao número da coluna
        if(tab[i][i]=='G')  // Se existir um espaço com o caracter 'G' (peça verde)
            contadorG++;    // Incrementar o contador de peças verdes no tabuleiro
        if(tab[i][i]=='Y')  // Se existir um espaço com o caracter 'Y' (peça amarela)
            contadorY++;    // Incrementar o contador de peças amarelas no tabuleiro
        if(tab[i][i]=='R')  // Se existir um espaço com o caracter 'R' (peça vermelha)
            contadorR++;    // Incrementar o contador de peças vermelhas no tabuleiro                                                           // enquanto que linhas e colunas vão de 0 a 2 (no entanto são 3 linhas/colunas) no caso de um tabuleiro 3x3
    }

    if(contadorG==lin || contadorY==lin || contadorR==lin){ // Se algum dos contadores for igual ao número de linhas/colunas(irrelevante),
        return 1;   // retorna 1 (indica que houve unma vitória)
    }
    else
        return 0;
}

int verifica_diagonalSec(int lin,int col,char **tab){

    if(lin!=col){   // Caso o número de linhas seja diferente do número de colunas, então é impossivel haver vitória através da diagonal
        return 0;
    }

    int contadorG=0,contadorY=0,contadorR=0;    // Variáveis auxiliares para detetar vitória

    int j = col-1;  // Variável j começa na última coluna e vai decrementando até chegar á primeira
    for(int i = 0; i < lin; i++){   // Percorrer as linhas do tabuleiro
        if(tab[i][j] == 'G')    // Se existir um espaço com o caracter 'G' (peça verde)
            contadorG++;        // Incrementar o contador de peças verdes no tabuleiro
        if(tab[i][j] == 'Y')    // Se existir um espaço com o caracter 'Y' (peça amarela)
            contadorY++;        // Incrementar o contador de peças amarelas no tabuleiro
        if(tab[i][j] == 'R')    // Se existir um espaço com o caracter 'R' (peça vermelha)
            contadorR++;        // Incrementar o contador de peças vermelhas no tabuleiro

        --j;    // Decrementar a variável referente ao número da coluna
    }

    if(contadorG==lin||contadorY==lin||contadorR==lin){ // Se algum dos contadores for igual ao número de linhas/colunas(irrelevante),
        return 1;   // retorna 1 (indica que houve unma vitória)
    }

    return 0;
}

int terminar(int lin, int col, char **tab,char jogador){

    if(jogador=='C'){   // Caso o jogador guarde o caracter 'C' (indica que é o computador a jogar)
        if(verifica_linha(lin,col,tab)==1 || verifica_coluna(lin,col,tab)==1 || verifica_diagonalPrin(lin,col,tab)==1 || verifica_diagonalSec(lin,col,tab)==1){ // Se alguma das funções de verificação retornar 1 (condição de vitória),
            system("@cls||clear");  // Limpar tela
            mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'

            printf("\n\n   |======================|");
            printf("\n   |  COMPUTADOR VENCEU!   |");       // Texto que aparecerá na tela
            printf("\n   |======================|");
            delay(2);   // Esperar 2 segundos antes de prosseguir (função 'delay')

            system("@cls||clear");  // Limpar tela
            return 1;   // Retorna 1 (para indicar que o jogo acabou e houve uma vitória)
        }
    }

    if(verifica_linha(lin,col,tab)==1 || verifica_coluna(lin,col,tab)==1 || verifica_diagonalPrin(lin,col,tab)==1 || verifica_diagonalSec(lin,col,tab)==1){ // Se alguma das funções de verificação retornar 1 (condição de vitória),
            system("@cls||clear");  // Limpar tela
            mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'

        printf("\n\n   |======================|");
        printf("\n   |  JOGADOR %c VENCEU!   |",jogador);   // Texto que aparecerá na tela
        printf("\n   |======================|");
        delay(2);

        system("@cls||clear");  // Limpar tela
        return 1;
    }
        return 0;
}

int jogadaCPU(int lin, int col, char **tab, int jogada){

    if(jogada==1){  // Se a jogada "escolhida" for a 1
        for(int i=0;i<lin;i++){
            for(int j=0;j<col;j++){ // Percorrer o tabuleiro
                if(tab[i][j]=='-'){ // Se o espaço estiver vazio
                    tab[i][j]='G';  // Colocar uma peça verde
                    return 1;       // Retorna 1 para indicar que a jogada 1 foi realizada
                }
                else
                    return 0;
            }
        }
    }

    else if(jogada==2){ // Se a jogada "escolhida" for a 2
        for(int i=0;i<lin;i++){
            for(int j=0;j<col;j++){ // Percorrer o tabuleiro
                if(tab[i][j]=='G'){ // Se o espaço estiver ocupado por uma peça verde
                    tab[i][j]='Y';  // Colocar uma peça amarela
                    return 2;       // Retorna 2 para indicar que a jogada 2 foi realizada
                }
                else
                    return 0;
            }
        }
    }

    else if(jogada==3){ // Se a jogada "escolhida" for a 3
        for(int i=0;i<lin;i++){
            for(int j=0;j<col;j++){ // Percorrer o tabuleiro
                if(tab[i][j]=='Y'){ // Se o espaço estiver ocupado por uma peça amarela
                    tab[i][j]='R';  // Colocar uma peça vermelha
                    return 3;       // Retorna 3 para indicar que a jogada 3 foi realizada
                }
                else
                    return 0;
            }
        }
    }

    else if(jogada==4){ // Se a jogada "escolhida" for a 4
        for(int i=0;i<lin;i++){
            for(int j=0;j<col;j++){ // Percorrer o tabuleiro
                if(tab[i][j]=='-'){ // Se o espaço estiver vazio
                    tab[i][j]='x';  // Colocar uma pedra
                    return 4;       // Retorna 4 para indicar que a jogada 4 foi realizada
                }
                else
                    return 0;
            }
        }
    }

    return 0;

}

int inverteLista(pnttabuleiro p, int c){

    int lidos = 0; // Elementos lidos

    if (p != NULL) { // Se o ponteiro para a lista não for NULO:
        inverteLista(p->proximo, c); // Inverte a lista
        if(p->njogada > c){ // Se o nº da jogada for menor do que a nº jogada pretendida:
            mostrarTab(p->linhas, p->colunas, p->tab); // Chamada da função 'mostrarTab'
            lidos++; // Contador de elementos lidos aumenta (+1)
        }
    }

    return lidos; // Retorna o número de elementos lidos

}

void preencheLista(pnttabuleiro p, char **tabuleiro, int lin, int col, int i, char jogador, int jogada, int linJogada, int colJogada){
    char **aux; // Variável auxiliar para alojar o tabuleiro

    aux = (char **)malloc(sizeof(char *)*lin); // Alocação de memória para as linhas (cada uma com tamanho para um char*)

    for(int a = 0; a < lin; a++){ // Para cada linha do tabuleiro:
        aux[a] = (char *)malloc(sizeof(char)*col); // Alocação de memória para as colunas (cada uma com tamanho para um char)
    }

    for(int b = 0; b < lin; b++){
        for(int d = 0; d < col; d++){ // Percorre o tabuleiro auxiliar
            aux[b][d] = tabuleiro[b][d]; // Iguala os dois tabuleiros
        }
    }

    // Preenche o elemento da lista ligada com as informações da função
    p->tab = aux;                   // Igualar 'tab' da lista ligada ao tabuleiro auxiliar
    p->linhas = lin;                // Número de linhas
    p->colunas = col;               // Número de colunas
    p->linhaJogada = linJogada;     // Linha jogada
    p->colunaJogada = colJogada;    // Coluna jogada
    p->jogador = jogador;           // Identificação do jogador
    p->jogada = jogada;             // Opção da jogada
    p->njogada = i;                 // Número da jogada
    p->proximo = NULL;
}

pnttabuleiro insere_novo(pnttabuleiro p, char **tabuleiro, int l, int c, int i, char jogador, int jogada, int linJogada, int colJogada){
    pnttabuleiro novo, aux; // Declaração de uma variável para o novo elemento e uma variável auxiliar

    novo = malloc(sizeof(tabu)); // Alocação de memória para um novo elemento
    if(novo == NULL) return p; // Caso não haja memória disponivel para a alocação, retorna o ponteiro para o início da lista inalterada
    preencheLista(novo, tabuleiro, l, c, i, jogador, jogada, linJogada, colJogada); // Preenche o novo elemento da lista com a informação de cada parâmetro

    if(p == NULL) p = novo; // Se a lista ligada estiver vazia, o novo elemento será colocado no início da lista ligada
    else { // Caso não esteja vazia,
        aux = p; // Iguala a variável auxiliar à lista ligada
        while(aux->proximo != NULL) aux = aux->proximo; // Percorre a lista ligada até encontrar o último elemento e coloca lá o novo elemento
        aux->proximo = novo; // O ponteiro para o novo elemento é o novo elemento adicionado ao final da lista
    }

    return p; // Retorna um ponteiro para o ínicio da lista com o novo elemento no final
}

int nElementos(pnttabuleiro p){
    int contador = 0; // Inicia o contador de elementos a 0
    while(p->proximo != NULL){ // Enquanto o ponteiro para o próximo elemento não for nulo,
        contador++; // Incrementa o contador de elementos
        p = p->proximo; // Vai para o próximo elemento da lista ligada
    }
    return contador + 1; // Retorna o contador do número de elementos
}

void liberta_memlista(pnttabuleiro p){

    pnttabuleiro aux; // Variável auxiliar

    while(p != NULL){ // Enquanto o elemento atual não for NULO
        aux = p; // A variável auxiliar toma o valor do elemento atual
        p = p->proximo; // Vai para o próximo elemento da lista ligada
        free(aux); // Liberta a memória alocada para a lista auxiliar "aux" e liberta também a lista utilizada durante o jogo
    }
}
