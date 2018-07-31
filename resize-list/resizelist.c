#include "resizelist.h"

/*int main() {
  list *test = makeList();
  node *t = createList();
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  add(test, t);
  printList(test);
}*/

list * makeList() {
  list *result = malloc(sizeof(list));
  result->capacity = 2;
  result->current = 0;
  result->root = malloc(sizeof(node) * result->capacity);
}

void resize(list *l, int factor) {
  l->capacity *= factor;
  l->root = realloc(l->root, sizeof(node) * l->capacity);
}

void add(list *l, node *i) {
  if (l->current == l->capacity) {
    resize(l, 2);
  }
  node *root = l->root;
  root[l->current] = *i;
  (l->current)++;
}

void deleteList(list *l) {
  free(l->root);
  free(l);
}

void printList(list *l) {
  for (int i = 0; i < l->current; i++) {
    printf("%lf ", (l->root)[i].data);
  }
  printf("\n");
}
