#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
#define dbg if(0)

void main () {
    Grafo *gr;
    gr = criaGrafo(11, 11, 1);

    int orig, dest, i;
    float distance;


    FILE *file = fopen("input.txt", "r");
    if(!file) printf("Erro");
    else {
        while(fscanf(file, "%d %d %f", &orig, &dest, &distance) != EOF){
            dbg printf("distance is: %0.f\n", distance);
            // distance: 54  = '-' there's no conection between them
            insereAresta(gr, orig, dest, 0, distance);
        }   
    }
    dbg printGraph(gr);

    printf("Qual a sua cidade de origem? Digite no formato 'Cidade 1', 'Cidade 2', etc.\n");
    scanf("%d", &orig);
    
    // int path[] = {3, 2, 4, 5, 9, 6, 7, 10, 8, 1, 3};
    int path[11], finalPath[11], dist, finalDist=0;
    *path = createNewPath(path, orig);
    printPath(path);

    dbg printf("Voce saira da cidade %d, visitara mais 9 cidades do interior de Pernambuco e, por fim, voltara para casa.\n\n", orig, dest);
    srand(time(NULL));
    
    for(i=0; i<200000; i++){
        if(i!=0) *path = createNextPath(path, orig);
        if(validPath(path, gr)) {
            dist = calculateTotalDistance(path, gr);
            if(dist >= finalDist){
                finalDist = dist;
                *finalPath = copyPath(path, finalPath);
            }
            // printf("Distance: %d and %d\n", distAux, dist);
        }
        // else printf("\n\nThe following path is invalid: ");
        // printPath(path);       
        // printf("\n\n");
    }
    if(finalDist == 0) printf("Couldn't find any valid path!");
    else printValidPath(finalDist, finalPath);
}