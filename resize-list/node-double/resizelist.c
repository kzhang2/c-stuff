#include "resizelist.h"

/*int main() {
  list *test = makeNodeDoubList();
  nodeDoub *t = createNodeDoubList();
  printf("%d\n", t->data);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  addNodeDoub(test, t);
  printNodeDoubList(test);
}*/

list * makeNodeDoubList() {
  list *result = malloc(sizeof(list));
  result->capacity = 2;
  result->current = 0;
  result->root = malloc(sizeof(nodeDoub) * result->capacity);
}

void resizeNodeDoub(list *l, int factor) {
  l->capacity *= factor;
  l->root = realloc(l->root, sizeof(nodeDoub) * l->capacity);
}

void addNodeDoub(list *l, nodeDoub *i) {
  if (l->current == l->capacity) {
    resizeNodeDoub(l, 2);
  }
  nodeDoub *root = l->root;
  root[l->current] = *i;
  (l->current)++;
}

void deleteListNodeDoub(list *l) {
  free(l->root);
  free(l);
}

void printNodeDoubList(list *l) {
  for (int i = 0; i < l->current; i++) {
    printf("%lf ", (l->root)[i].data);
  }
  printf("\n");
}
