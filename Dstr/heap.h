struct heap {
	int *a;
	int size;
	int count;
};

struct heap *heap_init(int size);
void heap_insert(struct heap *h, int v);
