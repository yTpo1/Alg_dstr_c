// Circular Queue
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue *q_init(int len)
{
	struct queue *new = (struct queue *) malloc(sizeof(*new));
	new->a = (int *) malloc(len * sizeof(int));
	new->i_head = -1;
	new->i_tail = -1;
	new->len = len;
	return new;
}

void q_free(struct queue *q)
{
	free(q->a);
	free(q);
}

void q_enqueue(struct queue *q, int v)
{
	if (q_size(q) == q->len){
		//fprintf(stderr, "Error: Queue is full\n");
		return;
	}
	if (q->i_tail == -1)
		q->i_head = 0;

	q->i_tail =( q->i_tail + 1) % q->len;
	q->a[q->i_tail] = v;
	//if (q->i_tail % q->len == 0)
	//q->i_tail = (q->i_tail + 1) % q->len;
}

int q_dequeue(struct queue *q)
{
	if (q_isempty(q)){
		//fprintf(stderr, "Error: Queue is empty\n");
		return -1;
	}
	int v = q->a[q->i_head];
	//if (q->i_head == q->len)
	//	q->i_head = 0;
	if (q->i_head == q->i_tail) {
		q->i_head = -1;
		q->i_tail = -1;
	}
	else
		q->i_head = (q->i_head + 1) % q->len;
	return v;
}

int q_first(struct queue *q)
{
	return q->a[q->i_tail];
}

int q_size(struct queue *q)
{
	//printf("tail %d head %d \n", q->i_tail, q->i_head);
	if (q->i_tail == -1 || q->i_head == -1)
		return 0;
	else if (q->i_tail == q->i_head)
		return 1;
	else if (q->i_tail > q->i_head) {
		//printf("tail %d head %d sum:%d\n", q->i_tail, q->i_head, (q->i_tail - q->i_head + 1));
		return (q->i_tail - q->i_head + 1);
	}
	else
		return (q->len + q->i_tail - q->i_head + 1);
}

int q_isempty(struct queue *q)
{
	//return q->i_tail == q->i_head;
	return q->i_head == -1;
}
