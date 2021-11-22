struct grafo{
    int eh_ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    char** linhas;
    float** pesos;
    int* grau;
};

typedef struct grafo Grafo;
typedef struct node Data;


Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado);

void liberaGrafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso, char linha);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

void imprimeGrafo(Grafo *gr);

void imprimeDistancias(Grafo *gr);

int calculaHeuristica(Grafo *gr, int origem, int destino);

int calculaCusto(Grafo *gr, int origem, int atual, Data* prevState);

int custoTotal(Grafo *gr, int origem, int destino, int atual, Data* prevState);
