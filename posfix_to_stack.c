#include "Dstr/stack_ll.h"

int solve_equasion_posfix(struct node *head, char *s)
{
	int x;
	char *stmp;
	for(int i = 0; s[i] != '\0'; i++){
		x = 0;
		if(s[i] == '+')
			x = sll_pop(head) + sll_pop(head);
		if(s[i] == '*')
			x = sll_pop(head) * sll_pop(head);
		while(s[i] >= '0' && s[i] <= '9'){

		}

	}
	return x;

}
