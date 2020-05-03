#include <stdio.h>
#include <stdlib.h>
#include "circ_link_list.h"

/* first element will always be 0 */
struct node *init_cl(void)
{
	struct node *first;
	first = (struct node *) malloc (sizeof *first);
	first->key = 0;
	first->next = first;
	return first;
}

void cll_free(struct node* head)
{
	struct node *tx;
	struct node *ty;
	tx = head->next;
	while(tx != head){
		ty = tx;
		free(ty);
		tx = tx->next;
	}
	free(head);
}

void insert_cl(struct node *head, int val)
{
    struct node *new;
    new = (struct node *) malloc (sizeof *new);
    new->next = head->next;
    head->next = new;
    new->key = val;
}

void traverse_list(struct node *first){
    struct node *tmp;
    tmp = first;
    printf("%d, ", tmp->key);
    tmp=tmp->next;
    while(tmp != first){
        printf("%d, ", tmp->key);
        tmp = tmp->next;
    }
}

void clist_to_array(struct node *first, int *a, int size){
    struct node *tmp;
    tmp = first->next;
    int i = 0;
    /*a[i++] = tmp->key;*/
    /*tmp = tmp->next*/
    while(tmp != first && i < size){
        a[i++] = tmp->key;
        tmp = tmp->next;
    }
}
