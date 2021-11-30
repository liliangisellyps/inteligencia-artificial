typedef struct grafo Grafo;

int printPath(int *path);

int createNewPath(int* path, int orig);

int randnum(int min, int max);

int createAleatoryPath(int* path, int orig);

int createNextPath(int* path, int origem);

int validPath(int *path, Grafo *gr);

float calculateTotalDistance(int *path, Grafo *gr);

void printValidPath(int distance, int *path);

int copyPath(int *path, int *finalPath);