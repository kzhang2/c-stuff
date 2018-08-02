#include "ll-nd.h"

int main() {
  nodeNodeDoub *head = createNodeNodeDoubList();
  nodeDoub *test = createNodeDoubList();
  appendNodeNodeDoub(head, test, 1);
  appendNodeNodeDoub(head, test, 2);
  appendNodeNodeDoub(head, test, 3);
  printNodeNodeDoubs(head);
  deleteNodeNodeDoubKey(head, 3);
  printNodeNodeDoubs(head);
  printf("%d\n", searchNodeNodeDoubKey(head, 1) == NULL);
  printf("%d\n", searchNodeNodeDoubKey(head, 3) == NULL);
  deleteNodeNodeDoubs(head);
  printf("debug\n");
  printf("%d\n", searchNodeNodeDoubKey(head, 1) == NULL);
  printf("%d\n", searchNodeNodeDoubKey(head, 3) == NULL);
}

nodeNodeDoub * createNodeNodeDoubList() {
  nodeNodeDoub *result = malloc(sizeof(nodeNodeDoub));
  result->data = NULL;
  result->key = -1;
  result->next = NULL;
  return result;
}

nodeNodeDoub * appendNodeNodeDoub(nodeNodeDoub *head, nodeDoub *d, nodeDoub *adj, int k) {
  nodeNodeDoub *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  nodeNodeDoub *item = createNodeNodeDoubList();
  item->data = d;
  item->key = k;
  item->adjacents = adj;
  curr->next = item;
  return item;
}

void deleteNodeNodeDoubKey(nodeNodeDoub *head, int k) {
  nodeNodeDoub *curr = head;
  while (curr->next != NULL && curr->next->key != k) {
    curr = curr->next;
  }
  if (curr->next != NULL) {
    nodeNodeDoub *temp = curr->next->next;
    nodeNodeDoub *rem = curr->next;
    curr->next = temp;
    free(rem);
  }
}

void deleteNodeNodeDoubs(nodeNodeDoub *head) {
  nodeNodeDoub *curr, *tmp;
  if (head != NULL) {
    curr = head->next;
    head->next = NULL;
    while (curr != NULL) {
      tmp = curr->next;
      deleteNodeDoubs(curr->data);
      free(curr);
      curr = tmp;
    }
  }
}

nodeNodeDoub * searchNodeNodeDoubKey(nodeNodeDoub *head, int k) {
  nodeNodeDoub *curr = head->next;
  while (curr != NULL) {
    if (k == curr->key) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

void printNodeNodeDoubs(nodeNodeDoub *head) {
  nodeNodeDoub *curr = head->next;
  while (curr != NULL) {
    printf("%f ", curr->data->data);
    curr = curr->next;
  }
  printf("\n");
}
