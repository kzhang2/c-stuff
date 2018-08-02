#include "linked-list.h"

/*int main() {
  nodeDoub *head = createNodeDoubList();
  appendNodeDoub(head, 5.0, 1);
  appendNodeDoub(head, 3.0, 2);
  appendNodeDoub(head, 2.0, 3);
  printNodeDoubs(head);
  deleteNodeDoubKey(head, 3);
  printNodeDoubs(head);
  printf("%d\n", searchNodeDoubKey(head, 1) == NULL);
  printf("%d\n", searchNodeDoubKey(head, 3) == NULL);
  deleteNodeDoubs(head);
  printf("debug\n");
  printf("%d\n", searchNodeDoubKey(head, 1) == NULL);
  printf("%d\n", searchNodeDoubKey(head, 3) == NULL);
}*/

nodeDoub * createNodeDoubList() {
  nodeDoub *result = malloc(sizeof(nodeDoub));
  result->data = -1.0;
  result->key = -1;
  result->next = NULL;
  result->adjacents = NULL;
  return result;
}

nodeDoub *createNodeDoub(double d, int k, nodeDoub *adj) {
  nodeDoub *res = malloc(sizeof(nodeDoub));
  res->data = d;
  res->key = k;
  res->adjacents = adj;
  res->next = NULL;
  return res;
}

nodeDoub * appendNodeDoub(nodeDoub *head, double d, int k) {
  nodeDoub *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  nodeDoub *item = createNodeDoub(d, k, NULL);
  curr->next = item;
  return item;
}


void deleteNodeDoubKey(nodeDoub *head, int k) {
  nodeDoub *curr = head;
  while (curr->next != NULL && curr->next->key != k) {
    curr = curr->next;
  }
  if (curr->next != NULL) {
    nodeDoub *temp = curr->next->next;
    nodeDoub *rem = curr->next;
    curr->next = temp;
    free(rem);
  }
}

nodeDoub * popNodeDoub(nodeDoub *head) {
  if (head->next != NULL) {
    nodeDoub *first = head->next;
    head->next = first->next;
    return first;
  }
  return NULL;
}

nodeDoub * pushNodeDoub(nodeDoub *head, double d, int k, nodeDoub *adj) {
  nodeDoub *newNode = createNodeDoub(d, k, adj);
  newNode->next = head->next;
  head->next = newNode;
  return newNode;
}

void deleteNodeDoubs(nodeDoub *head) {
  nodeDoub *curr, *tmp;
  if (head != NULL) {
    curr = head->next;
    head->next = NULL;
    while (curr != NULL) {
      tmp = curr->next;
      deleteNodeDoubs(curr->adjacents);
      free(curr);
      curr = tmp;
    }
  }
}

nodeDoub * searchNodeDoubKey(nodeDoub *head, int k) {
  nodeDoub *curr = head->next;
  while (curr != NULL) {
    if (k == curr->key) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

void printNodeDoubs(nodeDoub *head) {
  nodeDoub *curr = head->next;
  while (curr != NULL) {
    printf("%f ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
