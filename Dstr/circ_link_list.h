#include "ll_node.h"

struct ll_node *init_cl(void);
void cll_free(struct ll_node* head);
void insert_cl(struct ll_node* head, int val);
void traverse_list(struct ll_node* head);
void clist_to_array(struct ll_node* head, int *a, int size);
