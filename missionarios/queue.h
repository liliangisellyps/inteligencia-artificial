typedef struct state State;
typedef struct data Data;
typedef struct data* Queue;

struct state{
    int missionaryL;
    int cannibalL;
    int missionaryR;
    int cannibalR;
    char side;
};

struct data{
    State state;

    struct data *next;
    struct data *prev;
};


Queue* createQueue();

int enqueue(Queue* fronteira, State* state, Data* prevState);

Data* dequeue(Queue* fronteira);

void printQueue(Queue* fronteira);