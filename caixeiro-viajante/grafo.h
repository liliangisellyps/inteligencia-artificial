struct grafo{
    int eh_ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    int** visited;
    float** distances;
    int* grau;
};

typedef struct grafo Grafo;


Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float distance);

void printGraph(Grafo *gr);

int printPath(int *path);

int validPath(int *path, Grafo *gr);

float calculateTotalDistance(int *path, Grafo *gr);