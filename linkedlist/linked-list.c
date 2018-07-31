#include "linked-list.h"

/*int main() {
  node *head = createList();
  appendNode(head, 5.0, 1);
  appendNode(head, 3.0, 2);
  appendNode(head, 2.0, 3);
  printNodes(head);
  deleteNodeKey(head, 3);
  printNodes(head);
  deleteNodes(head);
  printf("debug");
  printf("%d\n", searchKey(head, 1));
  printf("%d\n", searchKey(head, 3));
}*/

node * createList() {
  node *result = malloc(sizeof(node));
  result->next = NULL;
  result->adjacents = NULL;
  return result;
}

node * appendNode(node *head, double d, int k) {
  node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  node *item = createList();
  item->data = d;
  item->key = k;
  curr->next = item;
  return item;
}

void deleteNodeKey(node *head, int k) {
  node *curr = head;
  while (curr->next != NULL && curr->next->key != k) {
    curr = curr->next;
  }
  if (curr->next != NULL) {
    node *temp = curr->next->next;
    node *rem = curr->next;
    curr->next = temp;
    free(rem);
  }
}

void deleteNodes(node *head) {
  node *curr, *tmp;
  if (head != NULL) {
    curr = head->next;
    head->next = NULL;
    while (curr != NULL) {
      tmp = curr->next;
      deleteNodes(curr->adjacents);
      free(curr);
      curr = tmp;
    }
  }
}

node * searchKey(node *head, int k) {
  node *curr = head->next;
  while (curr != NULL) {
    if (k == curr->key) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

void printNodes(node *head) {
  node *curr = head->next;
  while (curr != NULL) {
    printf("%f ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
