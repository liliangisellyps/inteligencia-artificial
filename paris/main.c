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

    // imprimeGrafo(gr);
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

    // if(terminalPath(currentNode->station, dest)) printf("eh estado final\n");
    // else {
    //     printf("%d nn eh estado final\n", currentNode->station);
    //     createNewPath(gr, fronteira, currentNode, orig, dest);
    //     currentNode = dequeue(fronteira);
    // }
    // if(terminalPath(currentNode->station, dest)) printf("eh estado final\n");
    // else {
    //     printf("%d nn eh estado final\n\n", currentNode->station);
    //     createNewPath(gr, fronteira, currentNode, currentNode->station, dest);
    //     currentNode = dequeue(fronteira);
    // }
    // printQueue(fronteira, dest);

    // if(terminalPath(currentNode->station, dest)) printf("eh estado final\n");


    while(!terminalPath(currentNode->station, dest)){
        createNewPath(gr, fronteira, currentNode, currentNode->station, dest);
        currentNode = dequeue(fronteira);
    }
}