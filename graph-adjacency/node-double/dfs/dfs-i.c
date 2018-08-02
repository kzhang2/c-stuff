#include "dfs-i.h"

int main() {
  graph *test = testGraph();
  printGraph(test);

  int* res = calloc(test->v, sizeof(int));
  int* res1 = calloc(test->v, sizeof(int));

  res = dfsIterative(test, 0);
  res1 = dfsIterativePost(test, 0);

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
  nodeDoub **stk = calloc(g->v, sizeof(nodeDoub *));
  int count = 1;
  int seen = 0;
  stk[count-1] = root;
  int *result = malloc(sizeof(int) * g->v);
  int *visited = calloc(g->v, sizeof(int));
  for (int i = 0; i < g->v; i++) {
    result[i] = -1;
  }

  while (count > 0) {
    nodeDoub *curr = stk[count-1];
    count--;
    if (!visited[curr->key]){
      result[seen] = curr->key;
      visited[curr->key] = 1;
      seen++;
      nodeDoub *neighbor = curr->adjacents->next;
      while (neighbor != NULL) {
        stk[count] = neighbor;
        count++;
        neighbor = neighbor->next;
      }
    }
  }
  return result;
}

int neighborsVisited(nodeDoub * n, int *visited) {
  nodeDoub *curr = n->adjacents->next;
  while (curr != NULL) {
    if (!visited[curr->key]) {
      return 0;
    }
    curr = curr->next;
  }
  return 1;
}

int * dfsIterativePost(graph *g, int s) {
  nodeDoub *root = g->root->root;

  int *result = malloc(sizeof(int) * g->v);
  int *visited = calloc(g->v, sizeof(int));
  int *counts = calloc(g->v, sizeof(int));

  nodeDoub **prevs = malloc(sizeof(nodeDoub *) * g->v);
  nodeDoub **stk = malloc(sizeof(nodeDoub *) * g->v);


  for (int i = 0; i < g->v; i++) {
    result[i] = -1;
    prevs[i] = NULL;
  }

  int count = 1;
  int prevCount = 0;
  int seen = 0;
  stk[count-1] = root;

  while (count > 0) {
    nodeDoub *curr = stk[count-1];
    count--;

    if (!visited[curr->key]) {
      prevs[prevCount] = curr;
      prevCount++;

      visited[curr->key] = 1;
      nodeDoub *neighbor = curr->adjacents->next;

      while (neighbor != NULL) {
        stk[count] = neighbor;
        count++;

        if (!visited[neighbor->key]) {
          counts[curr->key]++;
        }

        neighbor = neighbor->next;
      }

      if (counts[curr->key] == 0) {
        nodeDoub *prev = prevs[prevCount-1];

        while (prevCount > 1 && neighborsVisited(prev, visited)) {
          prevs[prevCount-1] = NULL;
          prevCount--;
          result[seen] = prev->key;
          seen++;
          prev = prevs[prevCount-1];

        }
        if(neighborsVisited(prev, visited)) {
          result[seen] = prev->key;
          seen++;
        }

      }

    }

  }

  return result;
}
