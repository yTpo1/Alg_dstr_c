#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

static int parent(int i);
static int left(int i);
static int right(int i);
static void swap(struct heap *h, int i, int j);
static void min_heapify_iter(struct heap *h);
static void max_heapify_rec(struct heap *h, int i);
static int get_value_index(struct heap *h, int n);

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

static void swap(struct heap *h, int i, int j)
{
	int tmp = 0;
	tmp = h->a[i];
	h->a[i] = h->a[j];
	h->a[j] = tmp;
}

struct heap *heap_init(int len)
{
	struct heap *h = (struct heap *) malloc(sizeof(struct heap));	
	h->a = (int *) malloc(len * sizeof(int));
	h->len = len;
	h->size = 0;
	return h;
}

static void min_heapify_iter(struct heap *h)
{
	int i = h->size;
	while (i > 0 && h->a[i] < h->a[parent(i)]) {
		swap(h, i, parent(i));
		i = parent(i);
	}
}

static void max_heapify_rec(struct heap *h, int i)
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
		max_heapify_rec(h, largest);
	}
}

void heap_max_build(struct heap *h)
{
	for (int i = (h->size / 2) - 1; i >= 0; i--)
		max_heapify_rec(h, i);
}

void heap_max_insert(struct heap *h, int n)
{
	if (h->size < h->len) {
		h->a[h->size] = n;
		h->size++;
		heap_max_build(h);
	}
}

void heap_min_insert(struct heap *h, int v)
{
	if (h->size < h->len) {
		h->a[h->size] = v;	
		min_heapify_iter(h);
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

// This works, but I'm guessing its not very efficient
/*
void heap_delete_item(struct heap *h, int n)
{
	int indx = get_value_index(h, n);
	if (indx != -1) {
		swap(h, indx, h->size-1);
		h->size--;
		h->a[h->size] = 0;
		h->size--;
		min_heapify_iter(h);
		h->size++;
	}
}
*/

int heap_min_delete_indx(struct heap *h, int indx)
{
	int todel = 0;
	if (indx >= 0) {
		todel = h->a[indx];
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
	return todel;
}

void heap_min_delete_item(struct heap *h, int n)
{
	int indx = get_value_index(h, n);
	heap_min_delete_indx(h, indx);
}

void heap_free(struct heap *h)
{
	free(h->a);
	free(h);
}
