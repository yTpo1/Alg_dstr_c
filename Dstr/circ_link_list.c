#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *first;
/* first element will always be 0 */
void init_cl(){
    first = (struct node *) malloc (sizeof *first);
    first->key = 0;
    first->next = first;
}

void insert_cl(int val){
    struct node *new;
    new = (struct node *) malloc (sizeof *new);
    new->next = first->next;
    first->next = new;
    new->key = val;
}

void traverse_list(){
    struct node *tmp;
    tmp = first;
    printf("%d, ", tmp->key);
    tmp=tmp->next;
    while(tmp != first){
        printf("%d, ", tmp->key);
        tmp = tmp->next;
    }
}

void clist_to_array(int *a, int size){
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
