#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "queue.h"
#define dbg if(0)

void createNewPath(Grafo *gr, Queue *fronteira, Data *node, int origem, int destino){
    Data *currentNode =  (Data*) malloc(sizeof(Data));
    currentNode = node;
    if(gr == NULL){
        printf("opa deu ruim");
        return;
    }
    int i = origem, j;
    for(j=0; j < gr->grau[i]; j++){
        int atual = gr->arestas[i][j];
        if(gr->linhas[i][atual] != '-'){
            dbg printf("enqueue: %d %c %.0f i: %d j: %d, ", atual, gr->linhas[i][atual], gr->pesos[i][j], i, j);
            enqueue(gr, origem, atual, destino, fronteira, node);
            dbg printQueue(fronteira, destino);
            // gr->pesos[i][j] -> custo da origem até o nó atual
        }
    }
    dbg printf("\n");
}

int terminalPath(int currentNode, int destino){
    int currentStation = currentNode;
    if(currentStation == destino){
        printf("[...] Rota encontrada. \n\nPara viajar pelo trajeto mais rapido, siga as instrucoes a seguir:\n\n");
        return 1;
    }
    else
        return 0;
}

void printPath(Data* node){
    // Data* aux = (Data*) malloc(sizeof(Data));
    Data* aux = node;
    aux->next = NULL;
    while(aux->prev != NULL){
        aux->prev->next = aux;
        aux = aux->prev;
    }
    Data* temp = aux;
    printf("A partir da estacao %d, va para as seguintes estacoes:\n", temp->station);        
    while(temp->next != NULL){
        temp = temp->next;
        printf("Estacao %d", temp->station);
        if(temp->next != NULL) printf(" -> ");
    }
    printf("\n\nA estimativa para a sua viagem eh de %d km e %d min, com o trem a uma velocidade media de 30km/h.\n", temp->cost, 2*temp->cost);
    printf("\nTenha uma boa viagem!");
}