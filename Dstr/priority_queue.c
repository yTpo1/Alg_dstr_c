#include <stdlib.h>
#include "heap.h"

struct heap *pq_init(int len)
{
	//struct heap *h = NULL;
	//h = (struct heap *) malloc(sizeof(struct heap));
	return heap_init(len);
}

void pq_insert(struct heap *h, int n)
{
	heap_min_insert(h, n);
}

int pd_extract_min(struct heap *h)
{
	return heap_min_delete_indx(h, 0);
}

int pd_peek_min(struct heap *h)
{
	if (h->size >= 1)
		return h->a[0];
	return 0;
}

void pq_free(struct heap* h)
{
	heap_free(h);
}
