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

// key:success, -1:failure, key not found
int sll_pop(struct node *head)
{
	if (head == NULL)
		return -1;
	if (head->next == NULL)
		return -1;
	return ll_delete(head, head->next->key);
}

void sll_free(struct node *head)
{
	ll_free(head);
}
