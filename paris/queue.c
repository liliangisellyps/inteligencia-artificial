#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "queue.h"
#define dbg if(0)

typedef struct node Data;
typedef struct node* Queue;

Queue* createQueue(){
    Queue* fronteira = (Queue*) malloc(sizeof(Queue));
    if(fronteira != NULL)
        *fronteira = NULL;
    return fronteira;
}

int enqueue(Grafo *gr, int origem, int atual, int destino, Queue* fronteira, Data* prevState){
    if(fronteira == NULL)
        return 0;
    Data* node = (Data*) malloc(sizeof(Data));
    if(node == NULL)
        return 0;

    node->station = atual;
    node->prev = prevState;
    node->next = NULL;
    node->cost = calculaCusto(gr, origem, atual, prevState);
    node->totalCost = node->cost + calculaHeuristica(gr, atual, destino);
    dbg printf("h(n) + g(n): %d\n", node->totalCost);

    if((*fronteira) == NULL){ // lista vazia: insere no inicio
        node->next = *fronteira;
        *fronteira = node;    
    }else{
        Data *aux = *fronteira;
        if(node->totalCost < aux->totalCost){
            dbg printf("hmhm: %d %d\n", node->totalCost, aux->totalCost);
            node->next = *fronteira;
            *fronteira = node; 
            return 1;
        }
        while(aux->next != NULL && node->totalCost > aux->next->totalCost) // procurando o ultimo elemento ou onde inserir
            aux = aux->next;
        
        node->next = aux->next;
        aux->next = node;
    }
    return 1;
}

Data* dequeue(Queue* fronteira){
    if(fronteira == NULL)
        return NULL;
        
    if(*fronteira == NULL)
        return NULL;
    
    Data *node = *fronteira;
    *fronteira = node->next;
    return node;
}

void printQueue(Queue* fronteira, int destino){
    Data *node = *fronteira;
    if(fronteira == NULL) return;
    if(*fronteira == NULL) return;

    printf("\n--------queue:---------------\n\n");
    while(node != NULL){
        printf("%d -> ", node->station);
        node = node->next;
    }
    printf("\n\n--------end of queue.---------------\n\n");
}