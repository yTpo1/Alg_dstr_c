#ifndef STACK_LL_H
#define STACK_LL_H
struct ll_node *sll_init();
void sll_push(struct ll_node *head, int v);
int sll_pop(struct ll_node *head);
void sll_free(struct ll_node *head);
#endif
