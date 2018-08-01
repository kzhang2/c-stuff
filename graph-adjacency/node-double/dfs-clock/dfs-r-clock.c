#include "dfs-r-clock.h"

int main() {
  graph *test = testGraph();
  printGraph(test);

  clk *res2 = dfsRecursiveClock(test, 0);

  for (int i = 0; i < test->v; i++){
    printf("(%d, %d)", res2[i].pre, res2[i].post);
  }
  printf("\n");
}

clk * dfsRecursiveClock(graph *g, int s) {
  nodeDoub *root = g->root->root;
  nodeDoub *curr = &root[s];
  clk *result = malloc(sizeof(clk) * g->v);
  int *visited = calloc(g->v, sizeof(int));
  for (int i = 0; i < g->v; i++) {
    result[i].pre = -1;
    result[i].post = -1;
  }
  int c = 0;
  int t = 0;
  helperClock(curr, result, visited, &c, &t);
  return result;
}

void helperClock(nodeDoub *curr, clk *result, int *visited, int *c, int *t) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    int tmp = *c;
    result[tmp].pre = *t;
    (*t)++;
    (*c)++;
    nodeDoub *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperClock(neighbor, result, visited, c, t);
      neighbor = neighbor->next;
    }
    result[tmp].post = *t;
    (*t)++;
  }
}
