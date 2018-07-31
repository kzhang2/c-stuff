#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int key;
  double data;
  struct node *next;
  struct node *adjacents;
} node;

node * createList();
node * appendNode(node *head, double data, int k);
void printNodes(node *head);
void deleteNodeKey(node *head, int k);
void deleteNodes(node *head);
node * searchKey(node *head, int k);

#endif 
