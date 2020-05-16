#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ll_node.h"

struct ll_node *ll_init(void);
void ll_free(struct ll_node *head);
void ll_insert_front(struct ll_node *head, int v);
void ll_insert_end(struct ll_node *head, int v);
int ll_search(struct ll_node *head, int v);
int ll_delete(struct ll_node *head, int n);
void ll_to_a(struct ll_node *head, int *a, int size);
#endif
