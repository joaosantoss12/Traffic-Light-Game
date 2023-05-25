// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>

#include "menu-inicial.h"

int menu_i(){
    
    int opcaoi;
    
    do{
        printf("\n\t|=====================|\t");
        printf("\n\t|     MENU INICIAL    |\t");
        printf("\n\t|=====================|\t\n\n");
        printf(" [1] - Jogar novo jogo (humano vs humano)\n");
        printf(" [2] - Jogar novo jogo (humano vs programa)\n");
        printf(" [3] - Carregar jogo guardado\n");
        printf(" [4] - Sair\n");
    
        printf("\nOpcao: ");
        scanf("%d",&opcaoi);
        printf("\n\n");
    }
    while(opcaoi < opc_i1 || opcaoi > opc_i4);  // Mostrar sempre o menu inicial sempre que a opção escolhida for menor que 1 ou maior que 4

    return opcaoi;
}