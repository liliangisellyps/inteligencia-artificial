typedef struct tictactoe Tictactoe;
typedef struct node* Stack;


struct tictactoe {
    char board[3][3];
    Tictactoe* next;
};

Tictactoe* createBoard(Tictactoe *tictactoe);
void printBoard(Tictactoe* tictactoe);
int isValidSpot(Tictactoe* tictactoe, int i, int j);
void insertEntry(Tictactoe* tictactoe, char op, int i, int j);
void createNewStates(Stack* st, Tictactoe* tictactoe, char op);
int isFinalGame(Tictactoe* tictactoe, char player);

