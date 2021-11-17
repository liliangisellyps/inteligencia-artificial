#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


State* createState(int missionaryL, int cannibalL, int missionaryR, int cannibalR, char side) {
    State* state = (State*) malloc(sizeof(State));
    state->missionaryL = missionaryL;
    state->cannibalL = cannibalL;
    state->missionaryR = missionaryR;
    state->cannibalR = cannibalR;
    state->side = side;

    return state;
}
State* createNewStates(Queue* fronteira, Data* node){ 
    State* currentState;
    *currentState = node->state;
    
    if(currentState->side == 'L'){
        enqueue(fronteira, createState((currentState->missionaryL) - 1, currentState->cannibalL, (currentState->missionaryR) + 1, currentState->cannibalR, 'R'), node);
        enqueue(fronteira, createState((currentState->missionaryL) - 2, currentState->cannibalL, (currentState->missionaryR) + 2, currentState->cannibalR, 'R'), node);
        enqueue(fronteira, createState((currentState->missionaryL), (currentState->cannibalL) - 1, (currentState->missionaryR), (currentState->cannibalR) + 1, 'R'), node);
        enqueue(fronteira, createState((currentState->missionaryL), (currentState->cannibalL) - 2, (currentState->missionaryR), (currentState->cannibalR) + 2, 'R'), node);
        enqueue(fronteira, createState((currentState->missionaryL) - 1, (currentState->cannibalL) - 1, (currentState->missionaryR) + 1, (currentState->cannibalR) + 1, 'R'), node);
    } else {
        enqueue(fronteira, createState((currentState->missionaryL) + 1, currentState->cannibalL, (currentState->missionaryR) - 1, currentState->cannibalR, 'L'), node);
        enqueue(fronteira, createState((currentState->missionaryL) + 2, currentState->cannibalL, (currentState->missionaryR) - 2, currentState->cannibalR, 'L'), node);
        enqueue(fronteira, createState((currentState->missionaryL), (currentState->cannibalL) + 1, (currentState->missionaryR), (currentState->cannibalR) - 1, 'L'), node);
        enqueue(fronteira, createState((currentState->missionaryL), (currentState->cannibalL) + 2, (currentState->missionaryR), (currentState->cannibalR) - 2, 'L'), node);
        enqueue(fronteira, createState((currentState->missionaryL) + 1, (currentState->cannibalL) + 1, (currentState->missionaryR) - 1, (currentState->cannibalR) - 1, 'L'), node);
    }
}
int validState(State* state){
    if((state->missionaryL >= 0) && (state->cannibalL >= 0) && (state->missionaryR >= 0) && (state->cannibalR >= 0) 
    && (state->missionaryL <= 3) && (state->cannibalL <= 3) && (state->missionaryR <= 3) && (state->cannibalR <= 3)){
        if((state->missionaryL + state->missionaryR) == 3 && (state->cannibalL + state->cannibalR) == 3){
            if((state->missionaryL >= state->cannibalL) && (state->missionaryR >= state->cannibalR)){
                return 1;
            }    
            else if(((state->missionaryL == 0) && (state->missionaryL <= state->cannibalL)) || ((state->missionaryR == 0) &&  (state->missionaryR <= state->cannibalR))){
                return 1;
            }
            else return 0;
        } else return 0;
    }
    else return 0;
}

int terminalState(State* state){
    if((state->missionaryL == 0) && (state->cannibalL == 0) && (state->missionaryR == 3) && (state->cannibalR == 3))
        return 1;
    else 
        return 0;
}

void printState(State state){
    printf("misL: %d canL: %d  misR: %d canR: %d side: %c\n", state.missionaryL, state.cannibalL, state.missionaryR, state.cannibalR, state.side);
}

void printPath(Data* node){
    Data* aux = node;
    aux->next = NULL;
    // printState(aux->state);
    while(aux->prev != NULL){
        aux->prev->next = aux;
        aux = aux->prev;
    }
    while(aux->next != NULL){
        State atual = aux->state;
        State proximo = aux->next->state;
        // printState(atual);
        // printState(proximo);
        if(atual.side == 'L') {
            int qtdMis = atual.missionaryL - proximo.missionaryL;
            int qtdCan = atual.cannibalL - proximo.cannibalL;
            if(qtdMis > 1)  printf("Execute a travessia de %d missionario(s)", qtdMis);
            else printf("Execute a travessia de %d missionario", qtdMis);

            if(qtdCan > 1)  printf(" e %d canibais para a borda direita do rio.\n", qtdCan);
            else printf(" e %d canibal para a borda direita do rio.\n", qtdCan);
        } else {
            int qtdMis = atual.missionaryR - proximo.missionaryR;
            int qtdCan = atual.cannibalR - proximo.cannibalR;

            if(qtdMis > 1)  printf("Execute a travessia de %d missionario(s)", qtdMis);
            else printf("Execute a travessia de %d missionario", qtdMis);

            if(qtdCan > 1)  printf(" e %d canibais para a borda esquerda do rio.\n", qtdCan);
            else printf(" e %d canibal para a borda esquerda do rio.\n", qtdCan);
        }
        printf("");
        
        aux = aux->next;
    }
}