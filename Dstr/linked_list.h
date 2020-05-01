#include "node.h"

struct node *ll_init();
void ll_insert_front(struct node *head, int v);
void ll_insert_end(struct node *head, int v);
int ll_search(struct node *head, int v);
int ll_delete(struct node *head, int n);
void ll_to_a(struct node *head, int *a, int size);
