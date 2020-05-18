#ifndef QUEUE_H
#define QUEUE_H
// Circular Queue

struct queue {
	int *a;
	int i_head;
	int i_tail;
	int len;
};

struct queue *q_init(int len);
void q_free(struct queue *q);
void q_enqueue(struct queue *q, int v);
int q_dequeue(struct queue *q);
int q_first(struct queue *q);
int q_size(struct queue *q);
int q_isempty(struct queue *q);

#endif
