#include "dfs-i.h"

/*int main() {
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
}*/

//add wrapper method
int * dfsIterative(graph *g, int s, int *res, int *vis, int *counting, int* comp) {
  nodeDoub *root = &((g->root->root)[s]);
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
    if (!vis[curr->key]){
      result[seen] = curr->key;
      res[*counting] = curr->key;
      comp[*counting] = s;
      printf("%d\n", comp[*counting]);
      visited[curr->key] = 1;
      vis[curr->key] = 1;
      seen++;
      (*counting)++;
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

//add wrapper method
int * dfsIterativePost(graph *g, int s, int *res, int *vis, int *counting) {
  nodeDoub *root = &(g->root->root[s]);

  int *result = malloc(sizeof(int) * g->v);

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

    if (!vis[curr->key]) {
      prevs[prevCount] = curr;
      prevCount++;

      vis[curr->key] = 1;
      nodeDoub *neighbor = curr->adjacents->next;

      while (neighbor != NULL) {
        stk[count] = neighbor;
        count++;

        if (!vis[neighbor->key]) {
          counts[curr->key]++;
        }

        neighbor = neighbor->next;
      }

      if (counts[curr->key] == 0) {
        nodeDoub *prev = prevs[prevCount-1];

        while (prevCount > 1 && neighborsVisited(prev, vis)) {
          prevs[prevCount-1] = NULL;
          prevCount--;

          result[seen] = prev->key;
          seen++;
          res[*counting] = prev->key;
          (*counting)++;

          prev = prevs[prevCount-1];

        }
        if(neighborsVisited(prev, vis)) {
          result[seen] = prev->key;
          seen++;
          res[*counting] = prev->key;

          (*counting)++;
        }

      }

    }

  }

  return result;
}
