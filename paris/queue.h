typedef struct node Data;
typedef struct grafo Grafo;
typedef struct node* Queue;

struct node{
    int station;
    int cost;
    int totalCost;

    struct node *next;
    struct node *prev;
};


Queue* createQueue();

int enqueue(Grafo *gr, int origem, int atual, int destino, Queue* fronteira, Data* prevState);

Data* dequeue(Queue* fronteira);

void printQueue(Queue* fronteira, int destino);