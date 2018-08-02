#include "dfs-i.h"

int main() {
  graph *test = testGraph();
  printGraph(test);

  int *res = dfsIterative(test, 0);
  int *res1 = dfsIterativePost(test, 0);

  for (int i = 0; i < test->v; i++){
    printf("%d ", res[i]);
  }
  printf("\n");
  for (int i = 0; i < test->v; i++){
    printf("%d ", res1[i]);
  }
  printf("\n");
}

int * dfsIterative(graph *g, int s) {
  nodeDoub *root = g->root->root;
  nodeDoub *stk = createNodeDoubList();
  int count = 1;
  int seen = 0;
  pushNodeDoub(stk, root->data, root->key, root->adjacents);
  int *result = malloc(sizeof(int) * g->v);
  int *visited = calloc(g->v, sizeof(int));
  for (int i = 0; i < g->v; i++) {
    result[i] = -1;
  }
  while (count > 0) {
    nodeDoub *curr = popNodeDoub(stk);
    count--;
    if (!visited[curr->key]){
      result[seen] = curr->key;
      visited[curr->key] = 1;
      seen++;
      nodeDoub *neighbor = curr->adjacents->next;
      while (neighbor != NULL) {
        pushNodeDoub(stk, neighbor->data, neighbor->key, neighbor->adjacents);
        count++;
        neighbor = neighbor->next;
      }
    }
  }
  return result;
}

int * dfsIterativePost(graph *g, int s) {
  nodeDoub *root = g->root->root;
  nodeDoub *stk = createNodeDoubList();
  pushNodeDoub(stk, root->data, root->key, root->adjacents);
  int *result = malloc(sizeof(int) * g->v);
  int *visited = calloc(g->v, sizeof(int));

  for (int i = 0; i < g->v; i++) {
    result[i] = -1;
  }

  int *counts = calloc(g->v, sizeof(int));
  nodeDoub **prevs = malloc(sizeof(nodeDoub *) * g->v);
  prevs[s] = NULL;
  int count = 1;
  int seen = 0;

  while (count > 0) {
    nodeDoub *curr = popNodeDoub(stk);
    count--;
    if (!visited[curr->key]) {
      visited[curr->key] = 1;
      nodeDoub *neighbor = curr->adjacents->next;
      while (neighbor != NULL) {
        pushNodeDoub(stk, neighbor->data, neighbor->key, neighbor->adjacents);
        count++;
        counts[curr->key]++;
        prevs[neighbor->key] = curr;
        neighbor = neighbor->next;
      }
      if (counts[curr->key] == 0) {
        result[seen] = curr->key;
        seen++;
        nodeDoub *prev = prevs[curr->key];
        while(prev != NULL && --counts[prev->key] == 0) {
          result[seen] = prev->key;
          seen++;
          prev = prevs[prev->key];
        }
      }
    }
  }

  return result;
}
