#include "heap.h"
#include <stdlib.h>

struct heap *heap_init(int size)
{
	struct heap *h = (struct heap *) malloc(sizeof(struct heap));	
	h->a = (int *) malloc(size * sizeof(int));
	h->size = size;
	h->count = 0;
	return h;
}

static void swap(struct heap *h, int i, int j)
{
	int tmp = 0;
	tmp = h->a[i];
	h->a[i] = h->a[j];
	h->a[j] = tmp;
}

static void min_heapify(struct heap *h)
{
	int i = h->count;
	while (i > 0 && h->a[i] < h->a[(i-1)/2]) {
		swap(h, i, (i-1)/2);
		i = (i-1)/2;
	}
}

void heap_insert(struct heap *h, int v)
{
	if (h->count < h->size) {
		h->a[h->count] = v;	
		min_heapify(h);
		h->count++;
	}
}
