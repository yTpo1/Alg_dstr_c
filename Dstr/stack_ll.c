#include <stdlib.h>
#include "linked_list.h"
#include "ll_node.h"

struct ll_node *sll_init(void)
{
	struct ll_node *head = ll_init();
	return head;
}

void sll_push(struct ll_node *head, int v)
{
	ll_insert_front(head, v);
}

// key:success, -1:failure, key not found
int sll_pop(struct ll_node *head)
{
	if (head == NULL)
		return -1;
	if (head->next == NULL)
		return -1;
	return ll_delete(head, head->next->key);
}

void sll_free(struct ll_node *head)
{
	ll_free(head);
}
