#include <stdlib.h>
#include "linked_list.h"

static struct node *head;
static struct node *trailer;

void llwt_init(void)
{
    head = (struct node *) malloc(sizeof *head);
    trailer = (struct node *) malloc (sizeof *trailer);
    head->next = trailer;
    trailer->next = trailer;
}

void llwt_free(void)
{
	struct node *tx;
	struct node *ty;
	tx = head->next;
	ty = head;
	while(tx != trailer){
		free(ty);
		ty = tx;
		tx = tx->next;
	}
	free(tx);
}

void llwt_insert_front(int v)
{
	struct node *new;
	new = (struct node *) malloc (sizeof *new);
	new->key = v;

	new->next = head->next;
	head->next = new;
}

static struct node *llwt_get_preceding_node(struct node *x)
{
	struct node *nfirst = head->next;
	struct node *npreceding = head;

	while(nfirst->next != trailer){
		if(x == nfirst)
			return npreceding;
		nfirst=nfirst->next;
		npreceding=npreceding->next;
	}
	if(x == trailer)
		return nfirst;
	return NULL;
}

void llwt_insert_end(int v)
{
	struct node *new;
	struct node *prec;
	new = (struct node *) malloc (sizeof *new);
	new->key = v;

	prec = llwt_get_preceding_node(trailer);
	new->next = trailer;
	prec->next = new;
}
	
// index: if exists, -1: if doesn't exists
int llwt_search(int v)
{
	struct node *tmp = head->next;
	int index = 0;
	while(tmp != trailer){
		if(tmp->key == v)
			return index;
		tmp = tmp->next;
		index++;
	}
	return -1;
}

// key: success, -1: failure, key not found
int llwt_delete(int n)
{
	// Check if linked list is empty
	if(head->next == trailer)
		return -1;

	int key = 0;
	struct node *tmp = head->next;
	struct node *tlag = head;

	while(tmp != trailer){
		if (tmp->key == n){
			tlag->next = tmp->next;
			key = tmp->key;

			free(tmp);
			return key;
		}
		tmp = tmp->next;
		tlag = tlag->next;
	}
	return -1;
}

 
int llwt_getfirstv(void)
{
    return head->next->key;
}

// Convert link list to array
void llwt_to_a(int *a, int size)
{
    struct node *tmp;
    tmp = head->next;
    int i = 0;
    while(tmp != trailer && i < size){
        a[i++] = tmp->key;
        tmp = tmp->next;
    }
}
