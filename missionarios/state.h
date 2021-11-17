typedef struct state State;
typedef struct data Data;
typedef struct data* Queue;


State* createState(int missionaryL, int cannibalL, int missionaryR, int cannibalR, char side);

State* createNewStates(Queue* fronteira, Data* node);

int validState(State* state);

int terminalState(State* state);

void printState(State state);

void printPath(Data* node);