#include "dfs-r.h"

int main() {
  graph *test = testGraph();
  printGraph(test);

  int *res = dfsRecursive(test, 0, 0);
  int *res1 = dfsRecursive(test, 0, 1);

  for (int i = 0; i < test->v; i++){
    printf("%d ", res[i]);
  }
  printf("\n");
  for (int i = 0; i < test->v; i++){
    printf("%d ", res1[i]);
  }
  printf("\n");

}

//0 for pre, 1 for post
int * dfsRecursive(graph *g, int s, int opt) {
  nodeDoub *root = g->root->root;
  nodeDoub *curr = &root[s];
  int *result = malloc(sizeof(int) * g->v);
  int *visited = calloc(g->v, sizeof(int));
  for (int i = 0; i < g->v; i++) {
    result[i] = -1;
  }
  int c = 0;
  if (opt) {
    helperPost(curr, result, visited, &c);
  } else {
    helperPre(curr, result, visited, &c);
  }
  return result;
}

void helperPre(nodeDoub *curr, int *result, int *visited, int *c) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    result[*c] = curr->key;
    (*c)++;
    nodeDoub *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperPre(neighbor, result, visited, c);
      neighbor = neighbor->next;
    }
  }
}

void helperPost(nodeDoub *curr, int *result, int *visited, int *c) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    nodeDoub *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperPost(neighbor, result, visited, c);
      neighbor = neighbor->next;
    }
    result[*c] = curr->key;
    (*c)++;
  }
}
