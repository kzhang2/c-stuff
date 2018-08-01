#include "../graph-adjacency.h"


int * dfsRecursive(graph *g, int s, int opt);
void helperPre(nodeDoub *curr, int *result, int *visited, int *c);
void helperPost(nodeDoub *curr, int *result, int *visited, int *c);
