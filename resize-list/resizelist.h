#ifndef RESIZELIST_H
#define RESIZELIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../linkedlist/linked-list.h"

typedef struct {
  node *root;
  int capacity;
  int current;
} list;

list * makeList();
void resize(list *l, int factor);
void add(list *l, node *i);
void deleteList(list *l);
void printList(list *l);
#endif
