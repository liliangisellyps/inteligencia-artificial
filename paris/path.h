typedef struct node Data;
typedef struct grafo Grafo;
typedef struct node* Queue;

void createNewPath(Grafo *gr, Queue *fronteira, Data *node, int origem, int destino);

int terminalPath(int currentNode, int destino);

void printPath(Data* node);