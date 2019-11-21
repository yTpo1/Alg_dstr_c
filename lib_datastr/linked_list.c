#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *head, *trailer;

void init_ll(int x){
    head = (struct node *) malloc(sizeof *head);
    trailer = (struct node *) malloc (sizeof *trailer);
    head->key = x;
    head->next = trailer;
    trailer->next = trailer;
}


void deletenext(struct node *n){
    n->next = n->next->next;
}

struct node *insert_after(int value, struct node *n){
    struct node *new;
    new = (struct node *) malloc (sizeof *new); 
    new->next = n;
    head = new;
    new->key = value;
    return new;
}

void insert_front(int x){
    insert_after(x, head);
}

int gethead_val(){
    return head->key;
}

// traverse list
void print_list(){
    struct node *tmp;
    tmp = head;
    while(tmp != trailer){
        printf("%d,", tmp->key);
        tmp = tmp->next;
    }
}

void list_to_array(int *a, int size){
    struct node *tmp;
    tmp = head;
    int i = 0;
    while(tmp != trailer && i < size){
        a[i++] = tmp->key;
        tmp = tmp->next;
    }
}
