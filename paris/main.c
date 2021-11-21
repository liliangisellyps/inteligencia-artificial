#include <stdio.h>
#include <locale.h>
#include "grafo.h"

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
    // printf("Digite sua estacao de origem: ");
    // scanf("%d", &orig);
    // printf("Digite sua estacao de destino: ");
    // scanf("%d", &dest);
    // printf("Voce saira da estacao %d e ira para a estacao %d.\n", orig, dest);

    calculaDistancia(gr, 1, 2);
    calculaDistancia(gr, 2, 1);
    calculaDistancia(gr, 3, 4);
    calculaDistancia(gr, 4, 3);
    // astar(gr, orig, dest);
}