#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

static int parent(int i)
{
	return (i - 1) / 2;
}

static int left(int i)
{
	return 2 * i + 1;
}

static int right(int i)
{
	return 2 * i + 2;
}

struct heap *heap_init(int len)
{
	struct heap *h = (struct heap *) malloc(sizeof(struct heap));	
	h->a = (int *) malloc(len * sizeof(int));
	h->len = len;
	h->size = 0;
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
	int i = h->size;
	while (i > 0 && h->a[i] < h->a[parent(i)]) {
		swap(h, i, parent(i));
		i = parent(i);
	}
}

// recursive
void max_heapify(struct heap *h, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < h->size && h->a[l] > h->a[i])
		largest = l;
	if (r < h->size && h->a[r] > h->a[largest])
		largest = r;
	if (largest != i) {
		swap(h, i, largest);
		max_heapify(h, largest);
	}
}

void build_max_heap(struct heap *h)
{
	//h->size = h->len;
	//printf("size %d len %d\n", h->size, h->len);
	//for (int i = 0; i < h->size; i++)
	//for (int i = h->size; i > 0; i--)
	//for (int i = (h->len / 2) - 1; i > 0; i--)
	for (int i = (h->size / 2) - 1; i >= 0; i--)
		max_heapify(h, i);
}

void heap_max_insert(struct heap *h, int n)
{
	if (h->size < h->len) {
		h->a[h->size] = n;
		build_max_heap(h);
		h->size++;
	}
}

void heap_insert(struct heap *h, int v)
{
	if (h->size < h->len) {
		h->a[h->size] = v;	
		min_heapify(h);
		h->size++;
	}
}

static int get_value_index(struct heap *h, int n)
{
	for (int i = 0; i < h->size; i++)
		if (h->a[i] == n)
			return i;
	return -1;
}

void heap_delete_item(struct heap *h, int n)
{
	int indx = get_value_index(h, n);
	if (indx != -1) {
		swap(h, indx, h->size-1);
		h->size--;
		h->a[h->size] = 0;
		h->size--;
		min_heapify(h);
		h->size++;
	}
}

void heap_delete_item_v2(struct heap *h, int n)
{
	int indx = get_value_index(h, n);
	if (indx != -1) {
		h->size--;
		h->a[indx] = h->a[h->size];
		// verify head ordering for each subtree which used to include the value
		while (left(indx) < h->size &&
			(h->a[indx] > h->a[left(indx)] ||
			h->a[indx] > h->a[right(indx)])) {
			if (h->a[left(indx)] < h->a[right(indx)]) {
				swap(h, left(indx), indx);
				indx = left(indx);
			}
			else {
				swap(h, right(indx), indx);
				indx = right(indx);
			}
		}
	}
}

void heap_free(struct heap *h)
{
	free(h->a);
	free(h);
}
