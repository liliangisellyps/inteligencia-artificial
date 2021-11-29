#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define dbg if(0)

typedef struct grafo Grafo;

// Grafo *gr 

Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(Grafo));
    if(gr != NULL){
        int i;
        gr->num_vertices = num_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = eh_ponderado;
        //vetor de graus
        gr->grau = (int*)calloc(num_vertices, sizeof(int)); // calloc inicializa todos com valor 0
        
        // matriz arestas
        gr->arestas = (int**)malloc(num_vertices*sizeof(int*));
        
        //cria matriz de visitados
        gr->visited = (int**)malloc(num_vertices*sizeof(int*));

        for(i=1; i<num_vertices; i++)
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));

        for(i=1; i<num_vertices; i++)
            gr->visited[i] = (int*)malloc(grau_max*sizeof(int));

        // matriz de distancias
        if(gr->eh_ponderado){
            gr->distances=(float**)calloc(num_vertices, sizeof(float*));

            for(i=1; i<num_vertices; i++)
                gr->distances[i] = (float*)calloc(grau_max, sizeof(float));
        }
    }
    return gr;
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float distance){
    if(gr == NULL)
        return 0;
    // verifica se o vertice existe
    if(orig < 1 || orig >= gr->num_vertices)
        return 0;
    if(dest < 1 || dest >= gr->num_vertices)
        return 0;
    
    //insere no final da lista
    // printf("grau: %d\n", gr->grau[orig]);
    gr->arestas[orig][gr->grau[orig]] = dest;

    if(gr->eh_ponderado)
        gr->distances[orig][gr->grau[orig]] = distance;

    // insere outra aresta se nao for digrafo
    gr->grau[orig]++;
    if(eh_digrafo == 0 && orig != dest){
        insereAresta(gr, dest, orig, 1, distance);
    }
    return 1;
}

void printGraph(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    printf("\n\n! ");
    for(i=1; i < gr->num_vertices; i++){
        printf("| %d ", i);
    }
    printf("\n\n");
    for(i=1; i < gr->num_vertices; i++){
        printf("%d ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado){                
                if(gr->distances[i][j] == 54) printf("| - ");
                else printf("| %.0f ", gr->distances[i][j]);
            }
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n\n");
    }
}

int printPath(int *path){
    int i;
    for(i=0; i<11; i++){
        printf("%d ", path[i]);
    }
    printf("\n\n");
}

int validPath(int *path, Grafo *gr){
    int i, current, next;
    for(i=0; i < 10; i++){
        current = path[i];
        next = path[i+1];
        if(gr->distances[current][next-1] != 54) {
            printf("%d and %d is connected by %.0f kms", current, next, gr->distances[current][next-1]);
        }
        else {
            printf("%d and %d isnt connected", current, next);
            return 0;
        }
        printf("\n\n");
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
