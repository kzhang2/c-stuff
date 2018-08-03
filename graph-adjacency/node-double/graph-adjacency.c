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
  result->root = makeNodeDoubList();
  return result;
}

void addVertex(graph *g, double d) {
  list *root = g->root;
  nodeDoub * newNode = createNodeDoubList();
  newNode->key = g->v;
  newNode->data = d;
  newNode->adjacents = createNodeDoubList();
  addNodeDoub(root, newNode);
  (g->v)++;
}

void addEdgeUndirected(graph *g, int a, int b) {
  nodeDoub *root = g->root->root;
  nodeDoub *v1, *v2;
  if (a >= 0 && b >= 0 && a <= g->v && b <= g->v) {
    v1 = &root[a];
    v2 = &root[b];
    nodeDoub *v1Rt = v1->adjacents;
    nodeDoub *v2Rt = v2->adjacents;
    if (searchNodeDoubKey(v1Rt, v2->key) == NULL && searchNodeDoubKey(v2Rt, v1->key) == NULL) {
      nodeDoub *v2New = appendNodeDoub(v1Rt, v2->data, v2->key);
      nodeDoub *v1New = appendNodeDoub(v2Rt, v1->data, v1->key);
      v1New->adjacents = v1->adjacents;
      v2New->adjacents = v2->adjacents;
    }
  }
  (g->e)++;
}

void addEdgeDirected(graph *g, int a, int b) {
  nodeDoub *root = g->root->root;
  nodeDoub *v1, *v2;
  if (a >= 0 && b >= 0 && a <= g->v && b <= g->v) {
    v1 = &root[a];
    v2 = &root[b];
    nodeDoub *v1Rt = v1->adjacents;
    if (searchNodeDoubKey(v1Rt, v2->key) == NULL) {
      nodeDoub *v2New = appendNodeDoub(v1Rt, v2->data, v2->key);
      v2New->adjacents = v2->adjacents;
    }
  }
  (g->e)++;
}

void printGraph(graph *g) {
  nodeDoub *l = g->root->root;
  for (int i = 0; i < g->v; i++) {
    nodeDoub *curr = &l[i];
    printf("(%d, %.2lf): ", curr->key, curr->data);
    printNodeDoubs(curr->adjacents);
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
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addVertex(test, 2.0);
  addVertex(test, 3.0);
  addVertex(test, 4.0);
  addEdgeDirected(test, 0, 1);
  addEdgeDirected(test, 1, 2);
  addEdgeDirected(test, 1, 3);
  addEdgeDirected(test, 1, 4);
  addEdgeDirected(test, 4, 1);
  addEdgeDirected(test, 2, 5);
  addEdgeDirected(test, 5, 2);
  addEdgeDirected(test, 4, 5);
  addEdgeDirected(test, 4, 6);
  addEdgeDirected(test, 5, 7);
  addEdgeDirected(test, 6, 7);
  addEdgeDirected(test, 7, 10);
  addEdgeDirected(test, 10, 11);
  addEdgeDirected(test, 11, 9);
  addEdgeDirected(test, 9, 8);
  addEdgeDirected(test, 8, 6);
  addEdgeDirected(test, 6, 9);
  return test;
}

graph * acyclicGraph() {
  graph *test = makeGraph();
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addVertex(test, 2.0);
  addVertex(test, 3.0);
  addVertex(test, 4.0);
  addVertex(test, 5.0);
  addEdgeDirected(test, 0, 1);
  addEdgeDirected(test, 0, 2);
  addEdgeDirected(test, 2, 3);
  addEdgeDirected(test, 1, 4);
  return test;
}

graph * undirectedSmallGraphAcyclic() {
  graph *test = makeGraph();
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addEdgeUndirected(test, 0, 1);
  return test;
}

graph * undirectedSmallGraphCyclic() {
  graph *test = makeGraph();
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addVertex(test, 2.0);
  addEdgeUndirected(test, 0, 1);
  addEdgeUndirected(test, 0, 2);
  addEdgeUndirected(test, 2, 1);
  return test;
}
