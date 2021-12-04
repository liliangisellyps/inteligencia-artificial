#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "minimax.h"

void main (){

    Tictactoe *tictactoe = (Tictactoe*) malloc(sizeof(Tictactoe));
    tictactoe = createBoard(NULL);
    printf("Ola! Esse eh seu tabuleiro de jogo da velha:\n\n");
    printBoard(tictactoe);
    printf("Vamos dar inicio ao jogo? Digite seu simbolo de jogada: ('X' ou 'O'):\n");
    char opPlayer, opComputer;
    scanf(" %c", &opPlayer);
    getchar();
    while(opPlayer != 'X' && opPlayer != 'O') {
        printf("\nEsse nao eh um operador valido! Insira novamente, digitando: 'X' ou 'O'.\n");
        scanf(" %c", &opPlayer);
    }
    if(opPlayer == 'X') opComputer = 'O';
    else opComputer = 'X';
    printf("\nVoce eh o jogador '%c' e o computador eh o jogador %c!\n", opPlayer, opComputer);


    int i, j;

    while(!isFinalGame(tictactoe, opPlayer)) {
        printf("\nEm qual linha deseja inserir sua jogada? (1 - 3)? \n");
        scanf("%d", &i);
        printf("\nEm qual coluna deseja inserir sua jogada? (1 - 3)? \n");
        scanf("%d", &j);

        //player time
        while(!isValidSpot(tictactoe, i-1, j-1)){
            printf("\nEntrada invalida. Insira sua jogada novamente, escolhendo um novo local.\n\n");
            printBoard(tictactoe);
            printf("\nEm qual linha deseja inserir sua jogada? (1 - 3)? \n");
            scanf("%d", &i);
            printf("\nEm qual coluna deseja inserir sua jogada? (1 - 3)? \n");
            scanf("%d", &j);
        } 

        insertEntry(tictactoe, opPlayer, i-1, j-1);
        printf("\n\nApos a sua jogada (%c), o tabuleiro esta assim:\n", opPlayer);
        printBoard(tictactoe);
    
        
        //computer time
        printf("\n\nApos a jogada da IA (%c), o tabuleiro esta assim:\n", opComputer);
        tictactoe = alphaBeta(tictactoe, opPlayer, opComputer);
        printBoard(tictactoe);
    }

    if(isFinalGame(tictactoe, opPlayer) == 3) printf("\nO jogo empatou! :/");
    else if(isFinalGame(tictactoe, opPlayer) == -1) printf("\nParabens! Voce venceu :)\n");
    else printf("\nQue pena! Voce foi derrotado pela IA :(");
    printf("\n\n-----------------------------------------\n\n");
}