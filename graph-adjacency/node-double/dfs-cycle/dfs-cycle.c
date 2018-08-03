#include "dfs-cycle.h"

int main() {
  graph *g = testGraph();
  graph *h = acyclicGraph();
  graph *i = undirectedSmallGraphAcyclic();
  graph *j = undirectedSmallGraphCyclic();

  printGraph(g);
  printGraph(h);
  printGraph(i);
  printGraph(j);

  printf("%d\n", hasCycleDirected(g));
  printf("%d\n", hasCycleDirected(h));
  printf("%d\n", hasCycleUndirected(i));
  printf("%d\n", hasCycleUndirected(j));
}

int hasCycleDirected(graph *g) {
  nodeDoub *root = g->root->root;

  nodeDoub **stk = malloc(g->v * sizeof(nodeDoub *));
  int *visited = calloc(g->v, sizeof(int));

  int seen = 0;
  int count = 0;
  if (g->v == 0) {
    return 0;
  }
  stk[count] = root;
  count++;
  nodeDoub *prev = NULL;
  while (seen < g->v) {
    while (count > 0) {
      nodeDoub *curr = stk[count-1];
      count--;
      if(!visited[curr->key]) {
        nodeDoub *neighbor = curr->adjacents->next;
        visited[curr->key] = 1;
        seen++;

        while (neighbor != NULL) {
          stk[count] = neighbor;
          count++;
          neighbor = neighbor->next;
        }
      } else {
        return 1;
      }

    }
    for (int i = 0; i < g->v; i++) {
      if (!visited[i]) {
        stk[count] = &((g->root->root)[i]);
        count++;
        break;
      }
    }
  }

  return 0;

}

int hasCycleUndirected(graph *g) {
  nodeDoub *root = g->root->root;

  nodeDoub **stk = malloc(g->v * sizeof(nodeDoub *));
  int *visited = calloc(g->v, sizeof(int));
  int *prevs = malloc(g->v * sizeof(int));

  int seen = 0;
  int count = 0;

  if (g->v == 0) {
    return 0;
  }

  stk[count] = root;
  count++;
  nodeDoub *prev = NULL;

  while (seen < g->v) {

    while (count > 0) {
      nodeDoub *curr = stk[count-1];
      count--;

      if(!visited[curr->key]) {
        nodeDoub *neighbor = curr->adjacents->next;
        visited[curr->key] = 1;
        seen++;

        while (neighbor != NULL) {
          if (prevs[curr->key] == neighbor->key) {
            neighbor = neighbor->next;
            continue;
          }
          prevs[neighbor->key] = curr->key;
          stk[count] = neighbor;
          count++;
          neighbor = neighbor->next;
        }

      } else {
        return 1;
      }

    }
    for (int i = 0; i < g->v; i++) {
      if (!visited[i]) {
        stk[count] = &((g->root->root)[i]);
        count++;
        break;
      }
    }
  }

  return 0;

}
