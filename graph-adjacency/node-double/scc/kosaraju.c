#include "kosaraju.h"

int main() {
  graph *test = testGraph();
  printGraph(test);
  graph *rev = reverseGraph(test);
  printGraph(rev);
//  graph *l = reverseGraph(rev);
//  printGraph(l);

//  kosaraju(test);
  kosaraju(rev);

}

//fix by implementing actually dfsing in reverse postorder instead of this
//jank solution, make visited arr. and skip vertices already visited
//in stack
void kosaraju(graph *g) {
  graph *rev = reverseGraph(g);
  int *revPost = totalReversePost(rev);
  int *visited = calloc(g->v, sizeof(int));
  int *comp = malloc(g->v * sizeof(int));

  int *stk = malloc(sizeof(int) * g->v);
  int c = 0;

  for (int i = 0; i < g->v; i++) {
    printf("%d ", revPost[i]);
    if (!visited[revPost[i]]) {
      dfsIterative(g, revPost[i], stk, visited, &c, comp);
    }
  }
  printf("\n");
  for (int i = 0; i < g->v; i++) {
    printf("(%d, %d) ", comp[i], stk[i]);
  }

  printf("\n\n");
}

graph* reverseGraph(graph *g) {
  graph *result = makeGraph();
  nodeDoub *root = g->root->root;
  for (int i = 0; i < g->v; i++) {
    addVertex(result, root[i].data);
  }
  for (int i = 0; i < g->v; i++) {
    nodeDoub *curr = (root[i].adjacents)->next;
    while (curr != NULL) {
      addEdgeDirected(result, curr->key, root[i].key);
      curr = curr->next;
    }
  }
  return result;
}

int* totalReversePost(graph *g) {

  int *visited = calloc(g->v, sizeof(int));

  int *result = malloc(sizeof(int) * g->v);


  int c = 0;
  while (c < g->v) {
    int s;
    //could replace this loop with a hashset
    for (int i = 0; i < g->v; i++) {
      if (!visited[i]) {
        s = i;
        break;
      }
    }
    dfsIterativePost(g, s, result, visited, &c);
  }
  for (int i = 0; i < g->v / 2; i++) {
    int tmp = result[i];
    result[i] = result[g->v - 1 - i];
    result[g->v - 1 - i] = tmp;

  }

  printf("\n");
  return result;
}
