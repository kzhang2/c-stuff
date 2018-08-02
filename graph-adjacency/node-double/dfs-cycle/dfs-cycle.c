#include "dfs-cycle.h"

int main() {
  printf("asdf");
}

int checkCycle(graph *g) {
  nodeDoub *root = g->root->root;

  nodeDoub **stk = malloc(g->v * sizeof(nodeDoub *));
  int *visited = malloc(g->v * sizeof(int));


}
