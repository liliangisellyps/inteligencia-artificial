typedef struct tictactoe Tictactoe;
typedef struct node Elem;
typedef struct node* Stack;

Stack* createStack();

void push(Stack* st, Tictactoe* newTurn);

Stack pop(Stack* st);

// void printStack(Stack* st);

int utility(Tictactoe *tictactoe, int player);

int max(int a, int b);

int min(int a, int b);

int maximize(Tictactoe* state, Tictactoe* savedState, int begin, int alpha, int beta, char player, char computer);

int minimize(Tictactoe* state, Tictactoe* savedState, int begin, int alpha, int beta, char player, char computer);

Tictactoe* alphaBeta(Tictactoe* state, char player, char computer);