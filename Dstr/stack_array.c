#include <stdlib.h>
#include "stack_array.h"

struct sa_stack *sa_init()
{
	struct sa_stack *new;
	new = (struct sa_stack *) malloc (sizeof *new);
	new->buffer = (int*)malloc(STACKSIZE * sizeof(int));
	new->index_buff = 0;
	return new;
}

void sa_free(struct sa_stack *st)
{
	free(st->buffer);
	free(st);
}

int sa_top(struct sa_stack *st)
{
	if (sa_isempty(st))
		return -1;
	return st->buffer[st->index_buff - 1];
}

int sa_size(struct sa_stack *st)
{
	return st->index_buff;
}

int sa_isempty(struct sa_stack *st)
{
	return st->index_buff == 0;
}

// index:success, -1: failure
int sa_push(struct sa_stack *st, int n)
{
	if(st->index_buff < STACKSIZE){
		st->buffer[st->index_buff] = n;
		return st->index_buff++;
	}
	return -1;
}

// v:success, 0: failure
int sa_pop(struct sa_stack *st)
{
	int v = 0;	
	if(st->index_buff > 0){
		v = st->buffer[--(st->index_buff)];
		return v;
	}
	return 0;
}
