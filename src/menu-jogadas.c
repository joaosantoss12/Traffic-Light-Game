// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>

#include "menu-jogadas.h"

int menu_j(){
    
    int opcaoj;

    do{
        printf("\n\n\t|=========================|\t");
        printf("\n\t|      MENU DE JOGADAS    |\t");
        printf("\n\t|=========================|\t\n\n");
        printf(" [1] - Colocar peca verde numa celula vazia do tabuleiro\n");
        printf(" [2] - Trocar uma peca verde do tabuleiro por uma amarela\n");
        printf(" [3] - Trocar uma peca amarela do tabuleiro por uma vermelha\n");
        printf(" [4] - Colocar uma pedra numa celula vazia do tabuleiro\n");
        printf(" [5] - Adicionar uma linha vazia ao final do tabuleiro\n");
        printf(" [6] - Adicionar uma coluna vazia ao final do tabuleiro\n");
        printf(" [7] - Rever jogadas (maximo de 3 jogadas anteriores)\n");
        printf(" [8] - Guardar jogo e sair para o menu inicial\n\n");

        printf("Opcao: ");
        scanf("%d",&opcaoj);
        printf("\n");
    }
    while(opcaoj < opc_j1 || opcaoj > opc_j8);  // Mostrar sempre o menu jogadas sempre que a opção escolhida menor que 1 ou maior que 8
    
    return opcaoj;
}