struct grafo{
    int eh_ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** distances;
    int* grau;
};

typedef struct grafo Grafo;


Grafo *criaGrafo(int num_vertices, int grau_max, int eh_ponderado);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float distance);

void printGraph(Grafo *gr);

int printPath(int *path);

int copyPath(int *path, int *finalPath);

int validPath(int *path, Grafo *gr);

float calculateTotalDistance(int *path, Grafo *gr);

int createNewPath(int* path, int orig);

int randnum(int min, int max);

int createNextPath(int* path, int origem);

void printValidPath(int distance, int *path);