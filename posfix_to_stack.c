#include "Dstr/stack_ll.h"

int char_to_int(char c)
{
	return (int) c - 48;
}

int solve_equation_posfix(struct node *head, char *s)
{
	char *stmp;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] == '+')
			sll_push(head, sll_pop(head) + sll_pop(head));
		if(s[i] == '*')
			sll_push(head, sll_pop(head) * sll_pop(head));
		while(s[i] >= '0' && s[i] <= '9'){
			sll_push(head, s[i]);
		}
	}
	return sll_pop(head);
}
