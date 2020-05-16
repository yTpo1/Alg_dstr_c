#ifndef HEAP_H
#define HEAP_H
struct heap {
	int *a;
	int size;
	int len;
};

struct heap *heap_init(int size);
void heap_min_insert(struct heap *h, int v);
void heap_max_insert(struct heap *h, int n);
void heap_max_build(struct heap *h);
void heap_min_delete_item(struct heap *h, int n);
int heap_min_delete_indx(struct heap *h, int indx);
void heap_free(struct heap *h);
#endif
