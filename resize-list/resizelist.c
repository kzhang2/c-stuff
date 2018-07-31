#include "resizelist.h"


int main() {
  list *test = makeList();
  add(test, 1);
  add(test, 1);
  add(test, 1);
  add(test, 1);
  add(test, 1);
}

list * makeList() {
  list *result = malloc(sizeof(list));
  result->capacity = 2;
  result->current = 0;
  result->root = malloc(sizeof(int) * capacity);
}

void resize(list *l, int factor) {
  result->capacity *= factor;
  result->root = realloc(sizeof(int) * capacity);
}

void add(list *l, int i) {
  if (result->current == result->capacity) {
    resize(l, 2);
  }
  int *root = l->root;
  root[l->current] = i;
  (l->current)++;
}

void deleteList(list *l) {
  free(l->root);
  free(l);
}

void printList(list *l) {
  for (int i = 0; i < l->current; i++) {
    printf("%d ", (l->root)[i]);
  }
  printf("\n");
}
