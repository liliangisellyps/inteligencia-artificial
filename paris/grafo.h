typedef struct grafo Grafo;

Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado);

void liberaGrafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso, char linha);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

void imprimeGrafo(Grafo *gr);

void imprimeDistancias(Grafo *gr);

int calculaDistancia(Grafo *gr, int origem, int destino);