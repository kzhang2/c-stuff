#include "../../../linkedlist/node-double/ll-nd.h"
#include "../graph-adjacency.h"

int * dfsIterative(graph *g, int s, int *res, int *vis, int *counting, int *comp);
int * dfsIterativePost(graph *g, int s, int *v, int *vis, int *counting);
int neighborsVisited(nodeDoub * n, int *visited);
