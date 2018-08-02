#ifndef LINKED_LIST_NODE_DOUBLE_H
#define LINKED_LIST_NODE_DOUBLE_H
#include "../double/linked-list.h"

typedef struct nodeNodeDoub {
  nodeDoub *data;
  struct nodeNodeDoub *next;
  int key;
} nodeNodeDoub;

nodeNodeDoub * createNodeNodeDoubList();
nodeNodeDoub * appendNodeNodeDoub(nodeNodeDoub *head, nodeDoub *data, nodeDoub *adj, int k);
void printNodeNodeDoubs(nodeNodeDoub *head);
void deleteNodeNodeDoubKey(nodeNodeDoub *head, int k);
void deleteNodeNodeDoubs(nodeNodeDoub *head);
nodeNodeDoub * searchNodeNodeDoubKey(nodeNodeDoub *head, int k);

#endif
