// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021
// João Santos - a2020136093

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "novo-jogo.h"
#include "essentials.h"
#include "menu-jogadas.h"

// ======================= Jogo vs Humano ==========================

int jogar(int lin, int col, char **tab, int njogada)
{

    jogador jogadorA; // Struct para guardar informações sobre o jogador A
    jogador jogadorB; // Struct para guardar informações sobre o jogador B

    pnttabuleiro lista = NULL; // Inicialização de uma lista ligada para guardar a sucessão de jogadas
    pnttabuleiro aux; // Lista ligada para auxiliar na iteração pela lista original

    lista = insere_novo(lista, tab, lin, col, 0, 'X', 0, -1, -1); // Inserir a jogada 0 (inicialização do tabuleiro) na lista ligada

    int opc,elin,ecol,done,jogada; // Variáveis auxiliares(opção escolhida, linha e coluna escolhidas,variável para indicar sucesso na realização da jogada e variável referente ao número da jogada)
    int flag_pedra_a=0;   // Flag para contar as vezes que o jogador a usou a opção de adicionar uma pedra
    int flag_pedra_b=0;   // Flag para contar as vezes que o jogador b usou a opção de adicionar uma pedra
    int flag_lincol_a=0;  // Flag para contar quantas vezes o jogador a usou a opção de adicionar uma linha/coluna
    int flag_lincol_b=0;  // Flag para contar quantas vezes o jogador b usou a opção de adicionar uma linha/coluna
    int flag_lin_a=0,flag_lin_b=0,flag_col_a=0,flag_col_b=0; // Variaveis auxiliares para quando chamar a funçao 'terminar' aumentar o numero de linhas/colunas enviadas para a função


    char jogador,tecla;

    lista->tab=tab;
    lista->jogada=0;
    lista->linhas=lin;
    lista->colunas=col;

    do{

        // ======================= Jogada do jogador A ==========================

        lista->njogada+=1;
        done=0;
        jogador='A';    // Variável jogador agora guarda o caracter 'A'
        lista->jogador=jogador;

        do{
        system("@cls||clear");  // Limpar tela de jogo
        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
        printf("\n\n\t      || Jogador A ||");

        opc=menu_j();   // Menu de jogadas é chamado
        switch(opc){
            case opc_j1:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peca
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peca

                    lista->jogada=1;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local"(linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='G';    // Então coloca uma peça verde
                        done=1;
                    }
                    else{                       // Se não:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'dealy')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j2:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peca
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peca

                    lista->jogada=2;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='G'){   // Se o "local"(linha e coluna) escolhido para a peça estiver ocupado por uma peça verde:
                        tab[elin-1][ecol-1]='Y';    // Então colocar uma peça amarela
                        done=1;
                    }
                    else{                           // Se não:
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca verde ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j3:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peça
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peça

                    lista->jogada=3;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Errp
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='Y'){   // Se o "local"(linha e coluna) escolhido para a peça estiver ocupado por uma peça amarela:
                        tab[elin-1][ecol-1]='R';    // Então colocar uma peça vermelha
                        done=1;
                    }
                    else{
                        system("@cls||clear");
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca amarela ou nao existe!\n\n");
                        done=0;
                        mostrarTab(lin,col,tab);
                        delay(3);
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j4:
                do{
                    if(flag_pedra_a==1){    // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de colocar uma pedra no tabuleiro for 1:
                        system("@cls||clear");  //Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida uma vez por jogador!\n  Escolha outra opcao.\n\n");   // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a pedra
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a pedra

                    lista->jogada=4;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local" (linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='x';    // Então coloca uma pedra
                        flag_pedra_a++;             // Contador referente ao número de vezes que o jogador usou a opção de colocar uma pedra
                        done=1;
                    }
                    else{                           // Se não
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j5:
                do{
                    if(flag_lincol_a==2){   // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de adicionar uma linha/coluna for 2:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");    // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }

                    lista->jogada=5;
                //nova linha
                ++lin;  // Número de linhas aumenta instântaneamente(+1 linha)
                    tab=expandirLin(lin,col,tab);   // Tabuleiro vai sofrer alterções (Chamada da função 'expandirLin' que faz aumentar e alocar +1 linha e respetivas colunas para essa linha)
                    flag_lincol_a++;    // Contador referente ás vezes que o jogador utilizou a opção de adicionar uma linha/coluna
                    flag_lin_a++;
                    done=1;
                }
                while(done!=1);
            break;
            case opc_j6:
                do{
                    if(flag_lincol_a==2){   // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de adicionar uma linha/coluna for 2:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");    // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }
                    lista->jogada=6;
                //nova coluna
                ++col;  // Número de colunas aumenta instântaneamente(+1 coluna)
                    tab=expandirCol(lin,col,tab);   // Tabuleiro vai sofrer alterções (Chamada da função 'expandirCol' que faz aumentar e alocar +1 coluna e respetivas linha para essa coluna)
                    flag_lincol_a++;    // Contador referente ás vezes que o jogador utilizou a opção de adicionar uma linha/coluna
                    flag_col_a++;
                    done=1;
                }
                while(done!=1);
            break;
            case opc_j7:
                system("@cls||clear");  // Limpar tela
                int k; // Variável referente ao número de jogadas anteriores que o jogador quer visulizar
                char continuar = '\0';

                do {
                    if(lista->njogada == 1){
                        k = 0; // Se só tiver havido uma jogada, então mostrar o tabuleiro no estado atual
                    }
                    else if(lista->njogada == 2){
                        k = 1; // Se só tiver havido duas jogadas, então mostrar o tabuleiro no estado anterior
                    }
                    else{
                        printf("Quantas jogadas atras quer visualizar? (entre 1 e 3): ");
                        scanf("%d", &k);
                        printf("\n");
                    }

                    inverteLista(lista, nElementos(lista)-k-1); // Inverter a lista e obter os k elementos do início
                    delay(3);
                    getchar();


                } while (k < nElementos(lista) ||  k >= 0); // Se os valores selecionados pelo jogador não forem válidos, então repete o ciclo para esta jogada (jogada 7)

                printf("\n\n  Pressione qualquer tecla para continuar!");
                scanf("%c",&tecla);
                if(tecla!=NULL){
                    break;
                }
            case opc_j8:
                // No caso do utilizador querer sair
                system("@cls||clear");   //Limpar tela

                guardaJogo(lista, &jogadorA, &jogadorB);
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada

                free(tab); // Liberta a memória alocada para o tabuleiro
                exit(0);
                return 0;
            break;
        };
        }while(done!=1);

        lista = insere_novo(lista, tab, lin, col, lista->njogada, lista->jogador, lista->jogada, lista->linhaJogada, lista->colunaJogada);

        terminar(lin,col,tab,jogador);
        if(terminar(lin,col,tab,jogador)==1){
            char fname[30]; // Nome do ficheiro
                printf("\nIntroduza um nome para o ficheiro\n>> ");
                fflush(stdin);
                fgets(fname, 30, stdin); // Obtém o nome para o ficheiro
                exportarJogo(fname, lista, njogada); // Exporta as sucessões do jogo para o ficheiro
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada
            break;}

        // ======================= Jogada do jogador B ==========================

        lista->njogada+=1;
        done=0;
        jogador='B'; // Variável jogador agora guarda o caracter 'B'
        lista->jogador=jogador;

            do{
                system("@cls||clear");      //Limpar tela
                mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                printf("\n\n\t      || Jogador B ||");

            opc=menu_j();   // Menu de jogadas é chamado
            switch(opc){
            case opc_j1:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peça
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peça

                    lista->jogada=1;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local"(linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='G';     // Então coloca uma peça verde
                        done=1;
                    }
                    else{                           // Se não:
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j2:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peça
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peça

                    lista->jogada=2;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='G'){   // Se o "local" (linha e coluna) escolhido para a peça estiver ocupado por uma peça verde:
                        tab[elin-1][ecol-1]='Y';    // Então coloca uma peça amarela
                        done=1;
                    }
                    else{                           // Se não:
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca verde ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j3:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peça
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peça

                    lista->jogada=3;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='Y'){   // Se o "local" (linha e coluna) escolhido para a peça estiver ocupado por uma peça amarela:
                        tab[elin-1][ecol-1]='R';    // Então coloca uma peça vermelha
                        done=1;
                    }
                    else{                           // Se não:
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca amarela ou nao existe!\n\n");   // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j4:
                do{
                    if(flag_pedra_b==1){        // Caso o contador referente ás vezes que o jogador 'B' usou a jogada de colocar uma pedra no tabuleiro for 1:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida uma vez por jogador!\n  Escolha outra opcao.\n\n");   // Erro (só pode usar 1 vez por jogo)
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }

                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a pedra
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a pedra

                    lista->jogada=4;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local" (linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='x';    // Então coloca uma pedra
                        flag_pedra_b++;             // Contador referente ao número de vezes que o jogador usou a opção de colocar uma pedra
                        done=1;
                    }
                    else{                       // Se não
                        system("@cls||clear");  // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j5:
                do{
                    if(flag_lincol_b==2){   // Caso o contador referente ás vezes que o jogador 'B' usou a jogada de adicionar uma linha/coluna for 2:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");    // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }

                    lista->jogada=5;
                //nova linha
                ++lin;  // Número de linhas aumenta instântaneamente(+1 linha)
                    tab=expandirLin(lin,col,tab);   // Tabuleiro vai sofrer alterções (Chamada da função 'expandirLin' que faz aumentar e alocar +1 linha e respetivas colunas para essa linha)
                    flag_lincol_b++;    // Contador referente ás vezes que o jogador utilizou a opção de adicionar uma linha/coluna
                    flag_lin_b++;
                    done=1;
                    lista->jogada=5;
                }
                while(done!=1);
            break;
            case opc_j6:
                do{
                    if(flag_lincol_b==2){
                        system("@cls||clear");
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }

                    lista->jogada=6;
                //nova coluna
                ++col;
                    tab=expandirCol(lin,col,tab);
                    flag_lincol_b++;
                    flag_col_b++;
                    done=1;
                }while(done!=1);
            break;
            case opc_j7:
                system("@cls||clear");  // Limpar tela
                int k; // Variável referente ao número de jogadas anteriores que o jogador quer visulizar
                char continuar = '\0';
                do {
                    if(njogada == 1){
                        k = 0; // Se só tiver havido uma jogada, então mostrar o tabuleiro no estado atual
                    }
                    else if(njogada == 2){
                        k = 1; // Se só tiver havido duas jogadas, então mostrar o tabuleiro no estado anterior
                    }
                    else{
                        printf("Quantas jogadas atras quer visualizar? (entre 1 e 3): ");
                        scanf("%d", &k);
                        printf("\n");
                    }

                    inverteLista(lista, nElementos(lista)-k-1); // Inverter a lista e obter os k elementos do início
                    delay(3);
                    getchar();


                } while (k > nElementos(lista) || k <= 0); // Se os valores selecionados pelo jogador não forem válidos, então repete o ciclo para esta jogada (jogada 7)

                printf("\n\n  Pressione qualquer tecla para continuar!");
                scanf("%c",&tecla);
                if(tecla!=NULL){
                    break;
                }
            case opc_j8:
                // No caso do utilizador querer sair e guardar do jogo
                system("@cls||clear");

                guardaJogo(lista, &jogadorA, &jogadorB);
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada

                free(tab); // Liberta a memória alocada para o tabuleiro
                exit(0); // Sai do jogo
                return 0;
            break;
        };
        }while(done!=1);

        lista = insere_novo(lista, tab, lin, col, lista->njogada, lista->jogador, lista->jogada, lista->linhaJogada, lista->colunaJogada);
        
        terminar(lin,col,tab,jogador);
        if(terminar(lin,col,tab,jogador)==1){
            char fname[30]; // Nome do ficheiro
                printf("\nIntroduza um nome para o ficheiro\n>> ");
                fflush(stdin);
                fgets(fname, 30, stdin); // Obtém o nome para o ficheiro escolhido pelo utilizador
                exportarJogo(fname, lista, njogada); // Exporta as sucessões do jogo para um ficheiro de texto
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada
            break;}

    }while(terminar(lin,col,tab,jogador)!=1);

    free(tab);
    return 0;
}

// ======================= Jogo vs Computador ==========================

int jogarComputador(int lin, int col, char **tab)
{
    jogador jogadorA; // Struct para guardar informações sobre o jogador A
    jogador jogadorB; // Struct para guardar informações sobre o jogador B

    pnttabuleiro lista = NULL; // Inicialização de uma lista ligada para guardar a sucessão de jogadas
    pnttabuleiro aux; // Lista ligada para auxiliar na iteração pela lista original

    lista = insere_novo(lista, tab, lin, col, 0, 'X', 0, -1, -1); // Inserir a jogada 0 (inicialização do tabuleiro) na lista ligada

    int opc,elin,ecol,done,jogada,njogada; // Variáveis auxiliares
    int flag_pedra_a=0;   // Flag para contar as vezes que o jogador a usou a opção de adicionar uma pedra
    int flag_lincol_a=0;  // Flag para contar quantas vezes o jogador a usou a opção de adicionar uma linha/coluna
    int flag_lin_a=0;
    int flag_col_a=0;
    char jogador,tecla;

    do{

        // ======================= Jogada do jogador A ==========================

        lista->njogada+=1;
        done=0;
        jogador='A';    // Variável jogador agora guarda o caracter 'A'
        lista->jogador=jogador;

        do{
        system("@cls||clear");  // Limpar tela de jogo
        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
        printf("\n\n\t      || Jogador A ||");

        opc=menu_j();   // Menu de jogadas é chamado
        switch(opc){
            case opc_j1:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peca
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peca

                    lista->jogada=1;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local"(linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='G';    // Então coloca uma peça verde
                        done=1;
                    }
                    else{                       // Se não:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'dealy')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j2:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peca
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peca

                    lista->jogada=2;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='G'){   // Se o "local"(linha e coluna) escolhido para a peça estiver ocupado por uma peça verde:
                        tab[elin-1][ecol-1]='Y';    // Então colocar uma peça amarela
                        done=1;
                    }
                    else{                           // Se não:
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca verde ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j3:
                do{
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a peça
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a peça

                    lista->jogada=3;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Errp
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='Y'){   // Se o "local"(linha e coluna) escolhido para a peça estiver ocupado por uma peça amarela:
                        tab[elin-1][ecol-1]='R';    // Então colocar uma peça vermelha
                        done=1;
                    }
                    else{
                        system("@cls||clear");
                        printf("\n  A posicao escolhida nao esta a ser ocupada por uma peca amarela ou nao existe!\n\n");
                        done=0;
                        mostrarTab(lin,col,tab);
                        delay(3);
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j4:
                do{
                    if(flag_pedra_a==1){    // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de colocar uma pedra no tabuleiro for 1:
                        system("@cls||clear");  //Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida uma vez por jogador!\n  Escolha outra opcao.\n\n");   // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }
                    printf("Linha: ");
                    scanf("%d",&elin);  // Guardar valor digitado pelo utilizador referente á linha onde colocar a pedra
                    printf("Coluna: ");
                    scanf("%d",&ecol);  // Guardar valor digitado pelo utilizador referente á coluna onde colocar a pedra

                    lista->jogada=4;

                    if(elin>lin || elin<0 || ecol>col || ecol<0){   // Caso os valores digitados sejam maiores ou menores aos valores válidos (tamanho do tabuleiro)
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Escolha invalida!\n\n");    // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir
                        break;
                    }

                    lista->linhaJogada=elin;
                    lista->colunaJogada=ecol;

                    if(tab[elin-1][ecol-1]=='-'){   // Se o "local" (linha e coluna) escolhido para a peça estiver vazio:
                        tab[elin-1][ecol-1]='x';    // Então coloca uma pedra
                        flag_pedra_a++;             // Contador referente ao número de vezes que o jogador usou a opção de colocar uma pedra
                        done=1;
                    }
                    else{                           // Se não
                        system("@cls||clear");      // Limpar tela
                        printf("\n  A posicao escolhida ja esta a ser ocupada ou nao existe!\n\n"); // Erro
                        done=0;
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        break;
                    }
                }
                while(done!=1);
            break;
            case opc_j5:
                do{
                    if(flag_lincol_a==2){   // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de adicionar uma linha/coluna for 2:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");    // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }

                    lista->jogada=5;
                //nova linha
                ++lin;  // Número de linhas aumenta instântaneamente(+1 linha)
                    tab=expandirLin(lin,col,tab);   // Tabuleiro vai sofrer alterções (Chamada da função 'expandirLin' que faz aumentar e alocar +1 linha e respetivas colunas para essa linha)
                    flag_lincol_a++;    // Contador referente ás vezes que o jogador utilizou a opção de adicionar uma linha/coluna
                    flag_lin_a++;
                    done=1;
                }
                while(done!=1);
            break;
            case opc_j6:
                do{
                    if(flag_lincol_a==2){   // Caso o contador referente ás vezes que o jogador 'A' usou a jogada de adicionar uma linha/coluna for 2:
                        system("@cls||clear");  // Limpar tela
                        printf("\n  Esta jogada so pode ser escolhida duas vezes por jogador!\n  Escolha outra opcao.\n\n");    // Erro
                        mostrarTab(lin,col,tab);    // Chamada da função 'mostrarTab'
                        delay(3);                   // Esperar 3 segundos antes de prosseguir (função 'delay')
                        done=0;
                        break;
                    }
                    lista->jogada=6;
                //nova coluna
                ++col;  // Número de colunas aumenta instântaneamente(+1 coluna)
                    tab=expandirCol(lin,col,tab);   // Tabuleiro vai sofrer alterções (Chamada da função 'expandirCol' que faz aumentar e alocar +1 coluna e respetivas linha para essa coluna)
                    flag_lincol_a++;    // Contador referente ás vezes que o jogador utilizou a opção de adicionar uma linha/coluna
                    flag_col_a++;
                    done=1;
                }
                while(done!=1);
            break;
            case opc_j7:
                system("@cls||clear");  // Limpar tela
                int k; // Variável referente ao número de jogadas anteriores que o jogador quer visulizar
                char continuar = '\0';

                do {
                    if(lista->njogada == 1){
                        k = 0; // Se só tiver havido uma jogada, então mostrar o tabuleiro no estado atual
                    }
                    else if(lista->njogada == 2){
                        k = 1; // Se só tiver havido duas jogadas, então mostrar o tabuleiro no estado anterior
                    }
                    else{
                        printf("Quantas jogadas atras quer visualizar? (entre 1 e 3): ");
                        scanf("%d", &k);
                        printf("\n");
                    }

                    inverteLista(lista, nElementos(lista)-k-1); // Inverter a lista e obter os k elementos do início
                    delay(3);
                    getchar();


                } while (k > nElementos(lista) || k <= 0); // Se os valores selecionados pelo jogador não forem válidos, então repete o ciclo para esta jogada (jogada 7)

                printf("\n\n  Pressione qualquer tecla para continuar!");
                scanf("%c",&tecla);
                if(tecla!=NULL){
                    break;
                }
            case opc_j8:
                // No caso do utilizador querer sair
                system("@cls||clear");   //Limpar tela

                guardaJogo(lista, &jogadorA, &jogadorB);
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada

                free(tab); // Liberta a memória alocada para o tabuleiro
                exit(0);
                return 0;
            break;
        };
        }while(done!=1);

        lista = insere_novo(lista, tab, lin, col, lista->njogada, lista->jogador, lista->jogada, lista->linhaJogada, lista->colunaJogada);

        terminar(lin,col,tab,jogador);
        if(terminar(lin,col,tab,jogador)==1){
            char fname[30]; // Nome do ficheiro
                printf("\nIntroduza um nome para o ficheiro\n>> ");
                fflush(stdin);
                fgets(fname, 30, stdin); // Obtém o nome para o ficheiro
                exportarJogo(fname, lista, njogada); // Exporta as sucessões do jogo para o ficheiro
                liberta_memlista(lista); // Liberta a memória alocada para a lista ligada
            break;}

        // ======================= Jogada do computador ==========================

        initRandom();
        done=0;
        int sucesso=0,op1,op2,op3,op4,flag_pedra_bot=0,jogadaBot,bot;
        jogador='C';
        lista->jogador=jogador;
        do{
            system("@cls||clear");           // Limpar tela
            mostrarTab(lin,col,tab);         // Chamada da função 'mostrarTab'
            printf("\n\n\n\t      || Computador ||");

                jogadaBot=intUniformRnd(1,4);   // Jogada do Computador escolhida de forma aleatoria entre 1 e 4

                if(jogadaBot==4 && flag_pedra_bot==1){  // Se o computador "escolher" a opção 4 (adicionar pedra) e já tiver "escolhido" esta opção 1 vez anteriormente, repete a "escolha" da jogada
                    sucesso=0;
                }
                if(jogadaBot==4){       // Se o computador "escolher" a opção 4 (adicionar pedra), aumenta o contador para evitar que volte a usar esta jogada limitada a 1 jogada
                    flag_pedra_bot++;
                }

                bot=jogadaCPU(lin,col,tab,jogadaBot); // Função que "realiza" a jogada do computador
                if(bot==1){                     // Se a jogada 1 tiver sido realizada com sucesso:
                    printf("\n\n  O COMPUTADOR COLOCOU UMA PECA VERDE!");
                    lista->jogada=1;
                    sucesso=1;
                }
                else if(bot==2){                // Se a jogada 2 tiver sido realizada com sucesso:
                    printf("\n\n  O COMPUTADOR COLOCOU UMA PECA AMARELA!");
                    lista->jogada=2;
                    sucesso=1;
                }
                else if(bot==3){                // Se a jogada 3 tiver sido realizada com sucesso:
                    printf("\n\n  O COMPUTADOR COLOCOU UMA PECA VERMELHA!");
                    lista->jogada=3;
                    sucesso=1;
                }
                else if(bot==4){                // Se a jogada 4 tiver sido realizada com sucesso:
                    printf("\n\n  O COMPUTADOR COLOCOU UMA PEDRA!");
                    lista->jogada=4;
                    flag_pedra_bot++;
                    sucesso=1;
                }

            delay(3);       // Esperar 3 segundos antes de prosseguir (função 'delay')
        }while(sucesso!=1);

        lista = insere_novo(lista, tab, lin, col, lista->njogada, lista->jogador, lista->jogada, lista->linhaJogada, lista->colunaJogada);
        terminar(lin,col,tab,jogador); // Chamada da função 'terminar'
        if(terminar(lin,col,tab,jogador)==1){   // Se a função 'terminar' devolver 1 (caso de vitória):
            char fname[30];                     // Nome do ficheiro
                printf("\nIntroduza um nome para o ficheiro\n>> ");
                fflush(stdin);
                fgets(fname, 30, stdin);        // Obtém o nome para o ficheiro escolhido pelo utilizador
                exportarJogo(fname, lista, njogada);     // Exporta todas as jogadas do jogo para o ficheiro
                liberta_memlista(lista);           // Libertar memória alocada para a lista ligada
            break;}

    }while(terminar(lin,col,tab,jogador)!=1);

    free(tab);  // Libertar memória alocada para o tabuleiro
    return 0;
}

// ======================= Retomar Jogo guardado anteriormente =============================

void **retomarJogo(){

    int linhas,colunas,jogada,ronda; // Variáveis correspondentes ás linhas, colunas, a jogada realizada e o número da jogada
    char turno; // Variável correspondente ao jogador ('A' , 'B' ou 'C' sendo este último o computador)
    char **tab; // Variável para armazenar o tabuleiro do jogo

    jogador jogadorA; // Struct para informações sobre o jogador A
    jogador jogadorB; // Struct para informações sobre o jogador B

    pnttabuleiro lista = NULL; // Inicialização da lista ligada para sucessão de jogadas
    pnttabuleiro aux;          // Lista ligada para auxiliar na iteração pela lista original

    if(existeFile()){
        lista = recuperaJogo(&jogadorA, &jogadorB); // Função para "recuperar" a lista ligada com as jogadas do jogo que foi guardado

        aux = lista;            // Variável auxiliar
        while(aux != NULL){     // Enquanto o elemento atual não for nulo, associa os valores do jogo anterior às variáveis do jogo atual
            linhas = aux->linhas;
            colunas = aux->colunas;
            jogada = aux->jogada;
            turno = aux->jogador;
            tab = aux->tab;
            ronda = aux->njogada;
            aux = aux->proximo;
        }
        jogar(linhas, colunas, tab, ronda); // Inicialização da função 'jogar', para prosseguir o jogo após recuperar os dados guardados
    }

    else{
        printf("  Nao existe nenhum jogo guardado anteriormente!\n\n"); // Caso a função 'recuperaJogo' não encontre nenhum ficheiro com os dados do jogo guardados
    }
}
