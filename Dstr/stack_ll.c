#include <stdio.h>
#include "linked_list.h"
#include "node.h"

struct node *sll_init()
{
	struct node *head = ll_init();
	return head;
}

void sll_push(struct node *head, int v)
{
	ll_insert_front(head, v);
}

int sll_pop(struct node *head)
{
	return ll_delete(head, head->next->key);
}
