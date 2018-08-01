#ifndef RESIZELIST_H
#define RESIZELIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../../linkedlist/double/linked-list.h"

typedef struct {
  nodeDoub *root;
  int capacity;
  int current;
} list;

list * makeNodeDoubList();
void resizeNodeDoub(list *l, int factor);
void addNodeDoub(list *l, nodeDoub *i);
void deleteNodeDoubList(list *l);
void printNodeDoubList(list *l);
#endif
