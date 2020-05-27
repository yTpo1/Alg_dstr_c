#include <stdlib.h>
#include <string.h>

#include "hashtbl_oaddr_dblh.h"
#include "../Algorithms/prime_numbers.h"
#include "../Algorithms/hash_function.h"

#define PRIME 129

static ht_item *ht_item_new(char *k, char *v);
static int double_hash(ht_dh *h, char *k, int attempt);
static void rehash(ht_dh *h, int newsize);
static void check_resize(ht_dh *h);

ht_dh *htd_init(int size)
{
	ht_dh *h = (ht_dh *) malloc(sizeof(ht_dh));
	if (size <= 11)
		h->size = 11;
	else
		h->size = find_closest_prime(size);
	//h->ht = (ht_item **) malloc(h->size * sizeof(ht_dh *));
	h->ht = (ht_item **) calloc(h->size, sizeof(ht_dh *));
	return h;
}

static int double_hash(ht_dh *h, char *k, int attempt)
{
	int klen = strlen(k);
	int hash1 = hash_simple(k, klen, PRIME, h->size);
	int hash2 = hash_simple(k, klen, PRIME, h->size);

	return hash1 + attempt * hash2;
}

static ht_item *ht_item_new(char *k, char *v)
{
	ht_item *new = (ht_item *) malloc(sizeof(ht_item));
	new->key = strdup(k);
	new->value = strdup(v);
	return new;
}

static void rehash(ht_dh *h, int newsize)
{
	ht_dh *n = htd_init(newsize); 

	int oldsize = h->size;
	int oldcount = h->count;
	ht_item **olditems = h->ht;
	
	for (int i = 0; i < h->size; i++)
		if (h->ht[i] != NULL)
			htd_insert(n, h->ht[i]->key, h->ht[i]->value);

	h->ht = n->ht;
	h->count = n->count;
	h->size = n->size;

	n->ht = olditems;
	n->count = oldcount;
	n->size = oldsize;
	htd_free(n);
}

static void check_resize(ht_dh *h)
{
	int newsize = 0;
	float load = (float) h->count / (float) h->size;
	
	if (load > 0.7) {
		newsize = find_closest_prime(h->size * 2);
		rehash(h, newsize);
	}
	else if (load < 0.3) {
		newsize = find_closest_prime(h->size / 2);
		rehash(h, newsize);
	}
}

void htd_insert(ht_dh *h, char *k, char *v)
{
	check_resize(h);
	// TODO: check if resize needed
	int indx = -1;
	int attempt = 0;
	do {
		indx = double_hash(h, k, attempt++);
	} while (h->ht[indx] != NULL);
	//for (int attempt = 0; attempt < h->size; attempt++) {
	//	indx = double_hash(h, k, attempt);

	h->ht[indx] = ht_item_new(k, v);
	h->count++;
}

char *htd_search(ht_dh *h, char *k)
{
	int indx = -1;
	int attempt = 0;
	do {
		indx = double_hash(h, k, attempt++);
		if (strcmp(h->ht[indx]->key, k) == 0)
			return h->ht[indx]->value;
	} while (h->ht[indx] != NULL);

	return NULL;
}

void htd_free(ht_dh *h)
{
	for (int i = 0; i < h->size; i++) {
		if (h->ht[i] != NULL) {
			free(h->ht[i]->key);
			free(h->ht[i]->value);
			free(h->ht[i]);
		}
	}
	free(h->ht);
	free(h);
}
