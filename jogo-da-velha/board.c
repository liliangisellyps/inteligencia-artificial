#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "minimax.h"
#define debug if(0)

Tictactoe* createBoard(Tictactoe *tictactoe){
    Tictactoe *newTictactoe = (Tictactoe*) malloc(sizeof(Tictactoe));
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(tictactoe == NULL) newTictactoe->board[i][j] = '-';
            else newTictactoe->board[i][j] = tictactoe->board[i][j];
        }
    }
    return newTictactoe;
}

void printBoard(Tictactoe* tictactoe){
    int i, j;
    
    printf("-------------\n");
    printf("! | 1 | 2 | 3\n");
    for(i=0; i<3; i++){
        printf("%d ", i+1);
        for(j=0; j<3; j++){
            printf("| %c ", tictactoe->board[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}

int isValidSpot(Tictactoe* tictactoe, int i, int j){
    if(i < 0 || i > 2 || j < 0 || j > 2) return 0;
    if(tictactoe->board[i][j] == '-') return 1;
    else return 0;
}

void insertEntry(Tictactoe* tictactoe, char op, int i, int j){
    tictactoe->board[i][j] = op;
}

void createNewStates(Stack* st, Tictactoe* tictactoe, char op){
    int i, j;
    Tictactoe* newState;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(tictactoe->board[i][j] == '-'){
                newState = createBoard(tictactoe);
                newState->board[i][j] = op;
                push(st, newState);
            }
        }
    }
}

int isFinalGame(Tictactoe* tictactoe, char player){
    int i = 0, j = 0;

    //checando se as linhas possuem vitoria
    for(i=0; i<3; i++){
        if(tictactoe->board[i][j] != '-') {
            if(tictactoe->board[i][j] == tictactoe->board[i][j+1]){
                if(tictactoe->board[i][j+1] == tictactoe->board[i][j+2]){
                    if(tictactoe->board[i][j] == player){
                      debug   printf("Player wins!\n");
                        return -1; 
                    } else {
                        debug printf("Computer wins!\n");
                        return 1;
                    }
                }
            }
        }
    }
    i=0;
    //checando por coluna
    for(j=0; j<3; j++){
        if(tictactoe->board[i][j] != '-') {
            if(tictactoe->board[i][j] == tictactoe->board[i+1][j]){
                if(tictactoe->board[i+1][j] == tictactoe->board[i+2][j]){
                    if(tictactoe->board[i][j] == player){
                      debug   printf("Player wins!\n");
                        return -1;
                    } else {
                        debug printf("Computer wins!\n");
                        return 1;
                    }
                }
            }
        }
    }

    // checando diagonal
    i = 0;
    if(tictactoe->board[i][0] != '-') {
        if(tictactoe->board[i][i] == tictactoe->board[i+1][i+1]){
            if(tictactoe->board[i+1][i+1] == tictactoe->board[i+2][i+2]){
                if(tictactoe->board[i][i] == player){
                  debug   printf("Player wins!\n");
                    return -1;
                } else {
                    debug printf("Computer wins!\n");
                    return 1;
                }
            }
        }
    }

    // checando ota diagonal
    if(tictactoe->board[0][2] != '-'){
        if(tictactoe->board[0][2] == tictactoe->board[1][1]){
            if(tictactoe->board[1][1] == tictactoe->board[2][0]){
                if(tictactoe->board[0][2] == player){
                  debug   printf("Player wins!\n");
                    return -1;
                } else {
                    debug printf("Computer wins!\n");
                    return 1;
                }
            }
        } 
    }

    for(i=0; i<3; i++){
        for (j = 0; j<3; j++){
           if(tictactoe->board[i][j] == '-') return 0; // nao acabou
        }
    }
    return 3; // acabou e empatou
}