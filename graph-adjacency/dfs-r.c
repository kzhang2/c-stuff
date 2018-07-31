#include "dfs-r.h"

int main() {

}

//inefficiency in return array as before dfs unknown how many vertices are
//visitable, maybe make resizing array?
int * dfs-recursive(graph *g, int s) {
  node *root = g->root;
  node *curr = searchKey(root, s);
  int *result = malloc(sizeof(int) * g->v);
  int *visited = malloc(sizeof(int) * g->v);
  result[0] = s;
  visited[s] = 1;

}
