#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "board.h"
#include "minimax.h"
#define DEBUG if(1)

typedef struct tictactoe Tictactoe;
typedef struct node Elem;
typedef struct node* Stack;

struct node {
    Tictactoe *state;
    Elem *next;
};

Stack* createStack(){
    Stack* st = (Stack*) malloc(sizeof(Stack));
    if(st != NULL)
        *st = NULL;
    return st;
}

void push(Stack* st, Tictactoe* newTurn){
    Elem* node = (Elem*) malloc(sizeof(Elem));
    if(st == NULL || node == NULL) printf("Deu ruim na push!\n");
    node->state = newTurn;
    node->next = *st;
    *st = node;
}

Stack pop(Stack* st){
    Stack node = *st;
    if(st == NULL || node == NULL) printf("Deu ruim na pop!\n");
    *st = (node->next);
    return node;
}

int utility(Tictactoe *tictactoe, int player){
    int i, j=0;
    char computer;
    int min=0, max=0;
     //checando se as linhas possuem vitoria
    if(player == 'X') computer = 'O';
    else computer = 'X';

    for(i=0; i<3; i++){
        if(tictactoe->board[i][j] != computer){
            if(tictactoe->board[i][j+1] != computer){
                if(tictactoe->board[i][j+2] != computer){
                    min++;
                }
            }
        }
        else if(tictactoe->board[i][j] != player){
            if(tictactoe->board[i][j+1] != player){
                if(tictactoe->board[i][j+2] != player){
                    max++;
                }
            }
        }
    }

    //col
    i=0;
    for(j=0; j<3; j++){
        if(tictactoe->board[i][j] != computer){
            if(tictactoe->board[i+1][j] != computer){
                if(tictactoe->board[i+2][j] != computer){
                    min++;
                }
            }
        }
        else if(tictactoe->board[i][j] != player){
            if(tictactoe->board[i+1][j] != player){
                if(tictactoe->board[i+2][j] != player){
                    max++;
                }
            }
        }
    }
    //diagonal
    i=0;
    if(tictactoe->board[i][i] != computer){
        if(tictactoe->board[i+1][i+1] != computer){
            if(tictactoe->board[i+2][i+2] != computer){
                min++;
            }
        }
    }
    if(tictactoe->board[0][2] != player){
        if(tictactoe->board[1][1] != player){
            if(tictactoe->board[2][0] != player){
                max++;
            }
        }
    }

    if(isFinalGame(tictactoe, player) == 1) return INT_MAX;
    else if(isFinalGame(tictactoe, player) == -1) return INT_MIN;
    return max-min;
}
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int min(int a, int b){
    if(a < b) return a;
    else return b;
}
int maximize(Tictactoe* state, Tictactoe* savedState, int begin, int alpha, int beta, char player, char computer){
    if(isFinalGame(state, player)) {
        int ut = utility(state, player);
        // printf("ut: %d\n", ut);
        // printBoard(state);
        return ut;
    }

    int v = alpha;
    Stack *st = createStack();
    createNewStates(st, state, computer);
    while(*st){
        Stack aux = pop(st);
        int min = minimize(aux->state, savedState, 0, alpha, beta, player, computer);
        if(begin && min > v) *savedState = *aux->state;
        v = max(v, min);
        if(v >= beta) return v;
        alpha = max(alpha, v);
    }
    return v;
}
int minimize(Tictactoe* state, Tictactoe* savedState, int begin, int alpha, int beta, char player, char computer){
    if(isFinalGame(state, player)){
        int ut = utility(state, player);
        // printf("ut: %d\n", ut);
        // printBoard(state);
        return ut;
    }
    int v = beta;
    Stack *st = createStack();
    createNewStates(st, state, player);
    while(*st){
        Stack aux = pop(st);
        v = min(v, maximize(aux->state, savedState, 0, alpha, beta, player, computer));
        if(v <= alpha) return v;
        beta = min(beta, v);
    }
    return v;
}
Tictactoe* alphaBeta(Tictactoe* state, char player, char computer){
    int v;
    Tictactoe* savedState = (Tictactoe*) malloc(sizeof(Tictactoe));
    v = maximize(state, savedState, 1, INT_MIN, INT_MAX, player, computer);
    return savedState;
}