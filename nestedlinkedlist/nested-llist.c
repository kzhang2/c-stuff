#include "nested-llist.h"

/*int main() {
  node *head = createList();
  appendNode(head, 1.0, 1);
  appendNode(head, 2.0, 2);
  appendNode(head, 3.0, 3);
  node *head1 = createList();
  appendNode(head1, 4.0, 4);
  appendNode(head1, 5.0, 5);
  appendNode(head1, 6.0, 6);
  node *head2 = createList();
  appendNode(head2, 7.0, 7);
  appendNode(head2, 8.0, 8);
  appendNode(head2, 9.0, 9);

  listNode *lHead = createNestedList();
  appendListNode(lHead, head, 1);
  appendListNode(lHead, head1, 2);
  appendListNode(lHead, head2, 3);
  printListNodes(lHead);
}*/

listNode * createNestedList() {
  listNode *result = malloc(sizeof(listNode));
  result->next = NULL;
  return result;
}

void appendListNode(listNode *head, node *d, int k) {
  listNode *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  listNode *item = createNestedList();
  item->data = d;
  item->key = k;
  curr->next = item;
}

void deleteListNodeKey(listNode *head, int k) {
  listNode *curr = head;
  while (curr->next != NULL && curr->next->key != k) {
    curr = curr->next;
  }
  if (curr->next != NULL) {
    listNode *temp = curr->next->next;
    listNode *rem = curr->next;
    curr->next = temp;
    free(rem);
  }
}

void printListNodes(listNode *head) {
  listNode *curr = head->next;
  while (curr != NULL) {
    printNodes(curr->data);
    curr = curr->next;
  }
}
