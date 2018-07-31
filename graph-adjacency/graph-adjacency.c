#include "graph-adjacency.h"

//need to compile with linkedlist source files

/*int main() {
  graph *test = testGraph();
  printGraph(test);
  printf("%d\n", test->v);
  printf("%d\n", test->e);
}*/


graph * makeGraph() {
  graph *result = malloc(sizeof(graph));
  result->v = 0;
  result->e = 0;
  result->root = makeList();
  return result;
}

void addVertex(graph *g, double d) {
  list *root = g->root;
  node * newNode = createList();
  newNode->key = g->v;
  newNode->data = d;
  newNode->adjacents = createList();
  add(root, newNode);
  (g->v)++;
}

void addEdgeUndirected(graph *g, int a, int b) {
  node *root = g->root->root;
  node *v1, *v2;
  if (a >= 0 && b >= 0 && a <= g->v && b <= g->v) {
    v1 = &root[a];
    v2 = &root[b];
    node *v1Rt = v1->adjacents;
    node *v2Rt = v2->adjacents;
    if (searchKey(v1Rt, v2->key) == NULL && searchKey(v2Rt, v1->key) == NULL) {
      node *v2New = appendNode(v1Rt, v2->data, v2->key);
      node *v1New = appendNode(v2Rt, v1->data, v1->key);
      v1New->adjacents = v1->adjacents;
      v2New->adjacents = v2->adjacents;
    }
  }
  (g->e)++;
}

void addEdgeDirected(graph *g, int a, int b) {
  node *root = g->root->root;
  node *v1, *v2;
  if (a >= 0 && b >= 0 && a <= g->v && b <= g->v) {
    v1 = &root[a];
    v2 = &root[b];
    node *v1Rt = v1->adjacents;
    if (searchKey(v1Rt, v2->key) == NULL) {
      node *v2New = appendNode(v1Rt, v2->data, v2->key);
      v2New->adjacents = v2->adjacents;
    }
  }
  (g->e)++;
}

void printGraph(graph *g) {
  node *l = g->root->root;
  for (int i = 0; i < g->v; i++) {
    node *curr = &l[i];
    printf("(%d, %lf): ", curr->key, curr->data);
    printNodes(curr->adjacents);
  }
}

graph * testGraph() {
  graph *test = makeGraph();
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addVertex(test, 2.0);
  addVertex(test, 3.0);
  addVertex(test, 4.0);
  addVertex(test, 5.0);
  addVertex(test, 6.0);
  addEdgeDirected(test, 1, 0);
  addEdgeDirected(test, 1, 2);
  addEdgeDirected(test, 1, 3);
  addEdgeDirected(test, 0, 2);
  addEdgeDirected(test, 3, 4);
  addEdgeDirected(test, 2, 4);
  addEdgeDirected(test, 4, 5);
  addEdgeDirected(test, 5, 6);
  return test;
}
