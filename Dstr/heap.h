struct heap {
	int *a;
	int size;
	int len;
};

struct heap *heap_init(int size);
void heap_insert(struct heap *h, int v);
void heap_max_insert(struct heap *h, int n);
void build_max_heap(struct heap *h);
void heap_delete_item(struct heap *h, int n);
void heap_delete_item_v2(struct heap *h, int n);
void heap_free(struct heap *h);
void max_heapify(struct heap *h, int i);
