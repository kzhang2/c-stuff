#include "../graph-adjacency.h"

typedef struct {
  int pre;
  int post;
} clk;

int * dfsRecursive(graph *g, int s, int opt);
void helperPre(node *curr, int *result, int *visited, int *c);
void helperPost(node *curr, int *result, int *visited, int *c);
clk * dfsRecursiveClock(graph *g, int s);
void helperClock(node *curr, clk *result, int *visited, int *c, int *t);
