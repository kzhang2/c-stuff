#include "../linkedlist/linked-list.h"
#include "../resize-list/resizelist.h"

typedef struct {
  int v;
  int e;
  list *root;
} graph;

graph * makeGraph();
void addVertex(graph *g, double d);
void addEdgeUndirected(graph *g, int a, int b);
void addEdgeDirected(graph *g, int a, int b);
void printGraph(graph *g);
graph * testGraph();
