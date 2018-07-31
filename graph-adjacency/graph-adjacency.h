#include "../linkedlist/linked-list.h"

typedef struct {
  int v;
  int e;
  node *root;
} graph;

graph * makeGraph();
void addVertex(graph *g, double d);
void addEdge(graph *g, int a, int b);
void printGraph(graph *g);
