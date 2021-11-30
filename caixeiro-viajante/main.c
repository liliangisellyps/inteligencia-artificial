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

    printf("Qual a sua cidade de origem? Digite no formato '1', '2', ..., '10'.\n");
    scanf("%d", &orig);
    
    srand(time(NULL));
    int path[11], finalPath[11], dist=0, finalDist=999999;
    *path = createAleatoryPath(path, orig);
    // printPath(path);
    
    for(i=0; i<500000; i++){
        if(i!=0) *path = createNextPath(path, orig);
        if(validPath(path, gr)) {
            dist = calculateTotalDistance(path, gr);
            if(dist < finalDist){
                *finalPath = copyPath(path, finalPath);
                finalDist = calculateTotalDistance(finalPath, gr);
            }
            // printf("Distance: %d and %d\n", dist, finalDist);
        }
        // else printf("\n\nThe following path is invalid: ");
        // printPath(path);       
        // printf("\n\n");
    }
    if(finalDist == 0) printf("Couldn't find any valid path!");
    else printValidPath(finalDist, finalPath);
}