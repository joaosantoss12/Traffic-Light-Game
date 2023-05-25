// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "menu-inicial.h"
#include "novo-jogo.h"

int main(void)
{
    initRandom();
    int opc, linhas=intUniformRnd(3,5), colunas=linhas;     // Inicialização de variáveis (opção escolhida, nº de linhas gerado aleatoriamente e nº de colunas=nº de linhas)
    char **tabuleiro;                                       // Matriz dinâmica

    do{
        system("@cls||clear");  // Limpar a tela
        opc=menu_i();       // Menu inicial é chamado
        switch(opc){
            case opc_i1:                                    // Se a opção 1 for escolhida:
                tabuleiro=gerarTab(linhas,colunas);         // O tabuleiro de jogo vai ser gerado pela função 'gerarTab'
                jogar(linhas,colunas,tabuleiro,0);            // Após ser gerado o tabuleiro, é iniciada a função 'jogar' (vs humano)
            break;
            case opc_i2:                                    // Se a opção 2 for escolhida:
                tabuleiro=gerarTab(linhas,colunas);         // O tabuleiro de jogo vai ser gerado pela função 'gerarTab'
                jogarComputador(linhas,colunas,tabuleiro);  // Após ser gerado o tabuleiro, é iniciada a função 'jogarComputador' (vs máquina)
            break;
            case opc_i3:                                    // Se a opção 3 for escolhida:
                retomarJogo();                              // Será iniciada a função 'retomarJogo'
            break;
        };
    }
    while(opc!=opc_i4);

    return 0;
}
