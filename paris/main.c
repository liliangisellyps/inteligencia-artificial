#include <stdio.h>
#include <locale.h>
#include "grafo.h"
#include "queue.h"
#include "path.h"

void main (){
    setlocale(LC_ALL, "Portuguese");

    Grafo *gr;
    gr = criaGrafo(15, 15, 1);

    int orig, dest;
    float peso;
    char linha;

    FILE *file = fopen("input.txt", "r");
    if(!file) printf("Erro");
    else {
        while(fscanf(file, "%d %d %c %f", &orig, &dest, &linha, &peso) != EOF){
            insereAresta(gr, orig, dest, 0, peso, linha);
        }   
    }

    imprimeGrafo(gr);
    // imprimeDistancias(gr);
    printf("Digite sua estacao de origem: ");
    scanf("%d", &orig);
    printf("Digite sua estacao de destino: ");
    scanf("%d", &dest);
    printf("Voce saira da estacao %d e ira para a estacao %d.\n\n", orig, dest);

    Queue *fronteira;
    fronteira = createQueue();
    enqueue(gr, orig, orig, dest, fronteira, NULL);
    Data* currentNode = dequeue(fronteira);

    // while(!terminalPath(currentNode->station, dest)){
    //     createNewPath(gr, fronteira, currentNode, orig, dest);
    //     currentNode = dequeue(fronteira);
    //     //what happens hereeeeee?
    // }
    if(terminalPath(currentNode->station, dest)) printf("eh estado final");
    else printf("nn eh estado final, %d", currentNode->station);{
        createNewPath(gr, fronteira, currentNode, orig, dest);
    }


    // while(!terminalState(currentState)){
    //     createNewStates(fronteira, node); 
    //     node = dequeue(fronteira); 
    //     *currentState = node->state;
    // }
    // astar(gr, orig, dest);
}