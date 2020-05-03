#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//static struct node *head;

struct node *ll_init(void)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(*new));
	new->key = 0;
	new->next = NULL;
	return new;
}

void ll_free(struct node *head)
{
	struct node *tx, *ty;
	tx = head->next;
	ty = head;
	while (tx != NULL) {
		free(ty);
		ty = tx;
		tx=tx->next;
	}
	free(ty);
}
	

void ll_insert_front(struct node *head, int v)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(*new));
	new->key = v;

	if (head->next == NULL)
		new->next = NULL;
	else
		new->next = head->next;
	head->next = new;
}

static struct node *ll_get_preceding_node(struct node *head, struct node *x)
{
	struct node *nfirst = head->next;
	struct node *npreceding = head;

	while (nfirst->next != NULL) {
		if (x == nfirst)
			return npreceding;
		nfirst = nfirst->next;
		npreceding = npreceding->next;
	}
	if (x == NULL && x->key != 0)
		return nfirst;
	return NULL;
}

void ll_insert_end(struct node *head, int v)
{
	struct node *new;
	struct node *temp;
	new = (struct node *) malloc (sizeof *new);
	new->key = v;
	new->next = NULL;

	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new;
}
	
// index: if exists, -1: if doesn't exists
int ll_search(struct node *head, int v)
{
	struct node *tmp = head;
	int index = 0;
	while (tmp->next != NULL) {
		if (tmp->key == v)
			return index;
		tmp = tmp->next;
		index++;
	}
	return -1;
}

// key: success, -1: failure, key not found
int ll_delete(struct node *head, int n)
{
	// Check if linked list is empty
	if (head->next == NULL)
		return -1;

	int key = 0;
	struct node *tmp = head->next;
	struct node *tlag = head;

	while (tmp->next != NULL) {
		if (tmp->key == n) {
			tlag->next = tmp->next;
			key = tmp->key;

			free(tmp);
			return key;
		}
		tmp = tmp->next;
		tlag = tlag->next;
	}

	if (tmp->key == n) {
		tlag->next = tmp->next;
		key = tmp->key;

		free(tmp);
		return key;
	}
	return -1;
}

// Convert link list to array
void ll_to_a(struct node *head, int *a, int size)
{
    struct node *tmp;
    tmp = head->next;
    int i = 0;
    while (tmp->next != NULL && i < size) {
        a[i++] = tmp->key;
        tmp = tmp->next;
    }
}
