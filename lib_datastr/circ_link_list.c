#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *first;

void init_cl(int val){
    first = (struct node *) malloc (sizeof *first);
    first->key = val;
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
