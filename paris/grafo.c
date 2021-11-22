#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "queue.h"
#define dbg if(0)
#define debg if(0)

typedef struct grafo Grafo;
typedef struct node Data;

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
        //cria matriz de linhas
        gr->linhas = (char**)malloc(num_vertices*sizeof(char*));

        for(i=1; i<num_vertices; i++)
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));

        for(i=1; i<num_vertices; i++)
            gr->linhas[i] = (char*)malloc(grau_max*sizeof(char));
        // matriz de pesos
        if(gr->eh_ponderado){
            gr->pesos=(float**)calloc(num_vertices, sizeof(float*));

            for(i=1; i<num_vertices; i++)
                gr->pesos[i] = (float*)calloc(grau_max, sizeof(float));
        }
    }
    return gr;
}
//gr = criaGrafo(10, 7, 0); por ex

void liberaGrafo(Grafo* gr){
    if(gr != NULL){
        int i;
        // libera matriz arestas
        for(i=1; i<gr->num_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas[i]);

        //libera matriz de pesos
        if(gr->eh_ponderado){
            for(i=1; i<gr->num_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        //libera vetor de graus
        free(gr->grau);
        //libera a primeira alocação da estrutura do grafo
        free(gr);
    }
}
//liberaGrafo(gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso, char linha){
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
    gr->linhas[orig][dest] = linha;

    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;


    // insere outra aresta se nao for digrafo
    gr->grau[orig]++;
    if(eh_digrafo == 0 && orig != dest){
        insereAresta(gr, dest, orig, 1, peso, linha);
    }
    return 1;
}
// insereAresta(gr, 0, 1, 0, 0);
// insereAresta(gr, 1, 3, 0, 0);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;

    //verifica se o vertice existe
    if(orig < 1 || orig >= gr->num_vertices)
        return 0;
    if(dest < 1 || dest >= gr->num_vertices)
        return 0;

    // procura aresta
    int i = 1;
    while(i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig]) // elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]]; // coloca o ultimo na posição q foi removida
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    
    // remove outra aresta se nao for digrafo
    if(eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
    return 1;
}

void imprimeGrafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=1; i < gr->num_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->linhas[i][gr->arestas[i][j]] != '-'){
                if(gr->eh_ponderado)
                    // printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
                    printf("%d %c %.0f, ", gr->arestas[i][j], gr->linhas[i][gr->arestas[i][j]], gr->pesos[i][j]);
                else
                    printf("%d, ", gr->arestas[i][j]);
            }
        }
        dbg printf("\n");
    }
}

void imprimeDistancias(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    printf("\n\n");
    for(i=1; i < gr->num_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d %c %.0f, ", gr->arestas[i][j], gr->linhas[i][gr->arestas[i][j]], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n\n");
    }
}

int calculaHeuristica(Grafo *gr, int atual, int destino){
    int i, pos;
    for(i=0; i < gr->grau[atual]; i++){
        if(gr->arestas[atual][i] == destino) pos = i;
    }
    int heuristica = gr->pesos[atual][pos];
    dbg printf("atual: %d destino: %d heuristica: %d\n", atual, destino, heuristica);
    return heuristica;
    //heuristica eh a estimativa de onde eu estou para o nó de destino
}

int calculaCusto(Grafo *gr, int origem, int atual, Data* prevState){
    if(gr == NULL)
        return 0;
    if(prevState != NULL){
        // printf("%d custo acumulado da estacao %d\n", prevState->cost, prevState->station);
        int i = prevState->station, j, custoTotal = 0, custoAtual;
        for(j=0; j < gr->grau[i]; j++){
            if(gr->arestas[i][j] == atual){
                if(gr->linhas[i][gr->arestas[i][j]] != '-'){
                    debg printf("custo: %.0f i: %d j: %d, ", gr->pesos[i][j], i, j);
                    custoAtual = gr->pesos[i][j];
                    // gr->pesos[i][j] -> custo da origem até o nó atual
                } else {
                    debg printf("Não tem custo");
                }
            }
        }
        debg printf("\n");
        custoTotal = prevState->cost + custoAtual;
        dbg printf("pai: %d, custo pai: %d, custo atual: %d, custo total: %d \n",  prevState->station, prevState->cost, custoAtual, custoTotal);
        return custoTotal;
    } else {
        return 0;
    }
}

int custoTotal(Grafo *gr, int origem, int destino, int atual,  Data* prevState){
    return calculaHeuristica(gr, atual, destino) + calculaCusto(gr, origem, atual, prevState);;
}