#include "graph-adjacency.h"

//need to compile with linkedlist source files

int main() {
  graph *test = makeGraph();
  addVertex(test, 0.0);
  addVertex(test, 1.0);
  addVertex(test, 2.0);
  addVertex(test, 3.0);
  addVertex(test, 4.0);
  addVertex(test, 5.0);
  addVertex(test, 6.0);
  addEdge(test, 1, 0);
  addEdge(test, 1, 2);
  addEdge(test, 1, 3);
  addEdge(test, 0, 2);
  addEdge(test, 3, 4);
  addEdge(test, 2, 4);
  addEdge(test, 4, 5);
  addEdge(test, 5, 6);
  printGraph(test);
  printf("%d\n", test->v);
  printf("%d\n", test->e);
}


graph * makeGraph() {
  graph *result = malloc(sizeof(graph));
  result->v = 0;
  result->e = 0;
  result->root = createList();
  return result;
}

void addVertex(graph *g, double d) {
  node *root = g->root;
  if (searchKey(root, k) == NULL) {
    node * newNode = appendNode(root, d, g->v);
    newNode->adjacents = createList();
  }
  (g->v)++;
}

void addEdge(graph *g, int a, int b) {
  node *root = g->root;
  node *v1, *v2;
  if ((v1 = searchKey(root, a)) != NULL && (v2 = searchKey(root, b)) != NULL) {
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

void printGraph(graph *g) {
  node * curr = g->root->next;
  while (curr != NULL) {
    printf("(%d, %lf): ", curr->key, curr->data);
    printNodes(curr->adjacents);
    curr = curr->next;
  }
}
