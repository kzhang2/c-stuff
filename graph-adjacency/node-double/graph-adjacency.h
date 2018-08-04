#ifndef GRAPH_ADJACENCY_H
#define GRAPH_ADJACENCY_H
#include "../../linkedlist/double/linked-list.h"
#include "../../resize-list/node-double/resizelist.h"

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
graph * acyclicGraph();
graph * undirectedSmallGraphAcyclic();
graph * undirectedSmallGraphCyclic();
void removeEdge(graph *g, int a, int b);
void deleteVertex(graph *g, int k);
#endif
