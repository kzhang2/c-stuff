#include "../graph-adjacency.h"

typedef struct {
  int pre;
  int post;
} clk;

clk * dfsRecursiveClock(graph *g, int s);
void helperClock(nodeDoub *curr, clk *result, int *visited, int *c, int *t);
