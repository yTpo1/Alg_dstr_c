#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue *q_init()
{
	struct queue *new;
	new = (struct queue *) malloc(sizeof(*new));
	//new->a = (int *)malloc(QUEUESIZE * sizeof(int));
	new->i_head = 0;
	new->i_tail = 0;
	return new;
}

void q_free(struct queue *q)
{
	//free(q->a);
	free(q);
}

void q_enqueue(struct queue *q, int v)
{
	if (q_size(q) == QUEUESIZE){
		fprintf(stderr, "Error: Queue is full\n");
		return;
	}
	q->a[(q->i_tail)++] = v;
	if (q->i_tail == QUEUESIZE)
		q->i_tail = 0;
}

int q_dequeue(struct queue *q)
{
	if (q_isempty(q)){
		//fprintf(stderr, "Error: Queue is empty\n");
		return -1;
	}
	int v;
	v = q->a[(q->i_head)++];
	if (q->i_head == QUEUESIZE)
		q->i_head = 0;
	return v;
}

int q_first(struct queue *q)
{
	return q->a[q->i_tail - 1];
}

int q_size(struct queue *q)
{
	if (q->i_tail >= q->i_head)
		return (q->i_tail - q->i_head);
	else
		return (QUEUESIZE + q->i_tail + 1 - q->i_head);
}

int q_isempty(struct queue *q)
{
	return q->i_tail == q->i_head;
}
