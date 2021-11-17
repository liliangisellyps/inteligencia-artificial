#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "queue.h"
#define DEBUG if(1)

typedef struct state State;
typedef struct data Data;
typedef struct data* Queue;

Queue* createQueue(){
    Queue* fronteira = (Queue*) malloc(sizeof(Queue));
    if(fronteira != NULL)
        *fronteira = NULL;
    return fronteira;
}

int enqueue(Queue* fronteira, State* state, Data* prevState){
    if(fronteira == NULL)
        return 0;
    Data* node = (Data*) malloc(sizeof(Data));
    if(node == NULL)
        return 0;
    if(!validState(state))
        return 0;
    node->state = (*state);
    node->prev = prevState;
    node->next = NULL;

    // printf("INSERINDO: ");
    // printState(node->state);
    // printf("\n------\n");

    if((*fronteira) == NULL){ // lista vazia: insere no inicio
        *fronteira = node;
    }else{
        Data *aux = *fronteira;
        while(aux->next != NULL) // procurando o ultimo elemento
            aux = aux->next;
        aux->next = node;
        node->next = NULL;
    }
    return 1;
}

Data* dequeue(Queue* fronteira){
    if(fronteira == NULL)
        return NULL;
    
        
    if(*fronteira == NULL)
        return NULL;
    
    Data *node = *fronteira;
    State s = node->state;
    *fronteira = node->next;
    // printf("PAI: ");
    // printState(s);
    return node;
}

void printQueue(Queue* fronteira){
    Data *node = *fronteira;
    if(fronteira == NULL) return;
    if(*fronteira == NULL) return;

    while(node != NULL){
        State temp = node->state;
        printState(temp);
        node = node->next;
    }
    printf("\n-----------------------\n");
}