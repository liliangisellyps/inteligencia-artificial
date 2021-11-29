#include <stdio.h>
#include "grafo.h"
#define dbg if(0)

void main () {
    Grafo *gr;
    gr = criaGrafo(11, 11, 1);

    int orig, dest;
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
    printGraph(gr);

    printf("Qual a sua cidade de origem? Digite no formato 'Cidade 1', 'Cidade 2', etc.\n");
    scanf("%d", &orig);
    
    int path[] = {3, 8, 4, 5, 9, 6, 7, 10, 2, 1, 3};

    printf("Voce saira da cidade %d, visitara mais 9 cidades do interior de Pernambuco e, por fim, voltara para casa.\n\n", orig, dest);

    if(validPath(path, gr)) {
        int dist = calculateTotalDistance(path, gr);
        printf("Distance: %d km\n", dist);
    }
    else printf("\nThe following path is invalid: ");
    printPath(path);   
}