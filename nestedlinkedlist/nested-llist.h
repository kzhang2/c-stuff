#include <stdio.h>
#include <stdlib.h>
#include "../linkedlist/linked-list.h"

typedef struct listNode {
  int key;
  struct node *data;
  struct listNode *next;
} listNode;

listNode * createNestedList();
void appendListNode(listNode *head, node *d, int k);
void printListNodes(listNode *head);
void deleteListNodeKey(listNode *head, int k);
