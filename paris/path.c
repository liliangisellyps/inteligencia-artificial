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
            printQueue(fronteira, destino);
            // gr->pesos[i][j] -> custo da origem até o nó atual
        }
    }
    dbg printf("\n");
}

int terminalPath(int currentNode, int destino){
    int currentStation = currentNode;
    if(currentStation == destino)
        return 1;
    else
        return 0;
}