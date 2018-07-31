#include "dfs-r.h"

int main() {
  graph *test = testGraph();
  printGraph(test);

  int *res = dfsRecursive(test, 0, 0);
  int *res1 = dfsRecursive(test, 0, 1);
  clk *res2 = dfsRecursiveClock(test, 0);

  for (int i = 0; i < test->v; i++){
    printf("%d ", res[i]);
  }
  printf("\n");
  for (int i = 0; i < test->v; i++){
    printf("%d ", res1[i]);
  }
  printf("\n");
  for (int i = 0; i < test->v; i++){
    printf("(%d, %d)", res2[i].pre, res2[i].post);
  }
  printf("\n");
}

clk * dfsRecursiveClock(graph *g, int s) {
  node *root = g->root->root;
  node *curr = &root[s];
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

void helperClock(node *curr, clk *result, int *visited, int *c, int *t) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    int tmp = *c;
    result[tmp].pre = *t;
    (*t)++;
    (*c)++;
    node *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperClock(neighbor, result, visited, c, t);
      neighbor = neighbor->next;
    }
    result[tmp].post = *t;
    (*t)++;
  }
}

//0 for pre, 1 for post
int * dfsRecursive(graph *g, int s, int opt) {
  node *root = g->root->root;
  node *curr = &root[s];
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

void helperPre(node *curr, int *result, int *visited, int *c) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    result[*c] = curr->key;
    (*c)++;
    node *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperPre(neighbor, result, visited, c);
      neighbor = neighbor->next;
    }
  }
}

void helperPost(node *curr, int *result, int *visited, int *c) {
  if (!visited[curr->key]) {
    visited[curr->key] = 1;
    node *neighbor = curr->adjacents->next;
    while(neighbor != NULL) {
      helperPost(neighbor, result, visited, c);
      neighbor = neighbor->next;
    }
    result[*c] = curr->key;
    (*c)++;
  }
}
