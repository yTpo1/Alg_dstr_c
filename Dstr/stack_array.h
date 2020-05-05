#define STACKSIZE 100

struct sa_stack{
	int *buffer;
	int index_buff;
};

struct sa_stack *sa_init();
int sa_push(struct sa_stack *st, int n);
int sa_pop(struct sa_stack *st);
void sa_free(struct sa_stack *st);
int sa_top(struct sa_stack *st);
int sa_size(struct sa_stack *st);
int sa_isempty(struct sa_stack *st);
