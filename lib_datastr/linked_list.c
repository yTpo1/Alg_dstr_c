#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"

struct node *head, *trailer;

void init(int x){
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
    new->next = n->next;
    n->next = new;
    new->key = value;
    return new;
}

void insert(int x){
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
