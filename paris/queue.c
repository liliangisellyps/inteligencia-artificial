#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "queue.h"
#define DEBUG if(1)

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
    node->cost = custoTotal(gr, origem, destino, atual, prevState);
    node->prev = prevState;
    node->next = NULL;

    Data *aux = *fronteira;
    if((*fronteira) == NULL || node->cost < aux->cost){ // lista vazia: insere no inicio
        node->next = *fronteira;
        *fronteira = node;    
    }else{
        while(aux->next != NULL && aux->cost > aux->next->cost) // procurando o ultimo elemento ou onde inserir
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