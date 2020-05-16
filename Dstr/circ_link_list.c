#include <stdio.h>
#include <stdlib.h>
#include "circ_link_list.h"

/* first element will always be 0 */
struct ll_node *init_cl(void)
{
	struct ll_node *first;
	first = (struct ll_node *) malloc (sizeof *first);
	first->key = 0;
	first->next = first;
	return first;
}

void cll_free(struct ll_node* head)
{
	struct ll_node *tx;
	struct ll_node *ty;
	tx = head->next;
	while(tx != head){
		ty = tx;
		free(ty);
		tx = tx->next;
	}
	free(head);
}

void insert_cl(struct ll_node *head, int val)
{
	struct ll_node *new;
	new = (struct ll_node *) malloc (sizeof *new);
	new->next = head->next;
	head->next = new;
	new->key = val;
}

void traverse_list(struct ll_node *first)
{
	struct ll_node *tmp;
	tmp = first;
	printf("%d, ", tmp->key);
	tmp=tmp->next;
	while(tmp != first){
		printf("%d, ", tmp->key);
		tmp = tmp->next;
	}
}

void clist_to_array(struct ll_node *first, int *a, int size)
{
	struct ll_node *tmp;
	tmp = first->next;
	int i = 0;
	/*a[i++] = tmp->key;*/
	/*tmp = tmp->next*/
	while(tmp != first && i < size){
		a[i++] = tmp->key;
		tmp = tmp->next;
	}
}
