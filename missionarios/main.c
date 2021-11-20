#include <stdio.h>
#include "queue.h"
#include "state.h"

int main() {
    Queue *fronteira;
    fronteira = createQueue();
 
    State *currentState;
    currentState = createState(3, 3, 0, 0,'L');
    enqueue(fronteira, currentState, NULL);
    Data* node = dequeue(fronteira);
    while(!terminalState(currentState)){
        createNewStates(fronteira, node); 
        node = dequeue(fronteira); 
        *currentState = node->state;
    }
    printPath(node);
    return 0;
}


