#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeDoub{
  int key;
  double data;
  struct nodeDoub *next;
  struct nodeDoub *adjacents;
} nodeDoub;

nodeDoub * createNodeDoubList();
nodeDoub * appendNodeDoub(nodeDoub *head, double data, int k);
void printNodeDoubs(nodeDoub *head);
void deleteNodeDoubKey(nodeDoub *head, int k);
void deleteNodeDoubs(nodeDoub *head);
nodeDoub * searchNodeDoubKey(nodeDoub *head, int k);
nodeDoub * popNodeDoub(nodeDoub *head);
nodeDoub * pushNodeDoub(nodeDoub *head, double d, int k, nodeDoub *adj);
nodeDoub *createNodeDoub(double d, int k, nodeDoub *adj);

#endif
