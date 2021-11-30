#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"

#define dbg if(0)

typedef struct grafo Grafo;

int printPath(int *path){
    int i;
    printf("\n\nCidade %d ", path[0]);
    for(i=1; i<11; i++){
        printf("-> Cidade %d ", path[i]);
    }
    printf("\n\n");
}

int createNewPath(int* path, int orig){
    path[0] = orig;
    path[10] = orig;
    int i, j=1;
    if(orig !=  1){
        for(i = 1; i <orig; i++){
            path[j] = i;
            j++;
        }
    }
    if(orig != 10){
        for(i = orig+1; i < 11; i++){
            path[j] = i;
            j++;
        }
    }
    return *path;
}

int randnum(int min, int max) {
    return ((rand() % (int)(((max) + 1) - (min))) + (min));
}

int createAleatoryPath(int* path, int orig){
    path[0] = orig;
    path[10] = orig;
    int visited[11] = {0};
    visited[orig] = 1;

    int i, x;
    for(i=1; i<10; i++){
        x = randnum(1, 10);
        while(visited[x] == 1) {
            x = randnum(1, 10);
        }
        path[i] = x;
        visited[x] = 1;
    }
    dbg printPath(path);
    return *path;
}
int createNextPath(int* path, int origem){
    int x = randnum(1, 9);
    int y = randnum(1, 9);
    int aux = path[x];
    path[x] = path[y];
    path[y] = aux;
    return *path;
}

int validPath(int *path, Grafo *gr){
    int i, current, next;
    for(i=0; i < 10; i++){
        current = path[i];
        next = path[i+1];
        if(gr->distances[current][next-1] == 54) {
            // printf("%d and %d isnt connected", current, next);
            return 0;
        }
        // else {
        //     printf("%d and %d is connected by %.0f kms", current, next, gr->distances[current][next-1]);
        // }
        // printf("\n\n");
    }
    return 1;
}

float calculateTotalDistance(int *path, Grafo *gr){
    int i, current, next;
    float totalDistance = 0;
    for(i=0; i < 10; i++){
        current = path[i];
        next = path[i+1];
        totalDistance += gr->distances[current][next-1];
    }
    return totalDistance;
}

void printValidPath(int distance, int *path){
    printf("--------------------------------------");
    printf("\nA melhor rota saindo da cidade %d e retornando para ela eh: ", path[0]);
    printPath(path);
    printf("Voce ira percorrer um total de %d km e viajara por 10 cidades do interior de Pernambuco, incluindo a sua de origem.\n\n", distance);

    printf("Tenha uma boa viagem!\n");
    printf("--------------------------------------");
}

int copyPath(int *path, int *finalPath){
    int i;
    for(i=0; i<11; i++){
        finalPath[i] = path[i];
    }
    return *finalPath;
}
