#include "node.h"

struct node *init_cl(void);
void cll_free(struct node* head);
void insert_cl(struct node* head, int val);
void traverse_list(struct node* head);
void clist_to_array(struct node* head, int *a, int size);
