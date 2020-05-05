#define QUEUESIZE 10

struct queue {
	//int *a;
	int a[QUEUESIZE];
	int i_head;
	int i_tail;
};

struct queue *q_init();
void q_free(struct queue *q);
void q_enqueue(struct queue *q, int v);
int q_dequeue(struct queue *q);
int q_first(struct queue *q);
int q_size(struct queue *q);
int q_isempty(struct queue *q);
