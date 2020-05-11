#include <stdlib.h>
#include <string.h>

#include "hash_table_oaddr.h"
#include "../Algorithms/hash_function.h"

#define HTSIZE  11 // maxbuckets, also should be prime?
#define HTPRIME 129

//struct ht_oaddr {
//	struct ht_item *hti[HTSIZE];
//};

// init ht_delete ht_insert ht_search

struct htoa_item **htoa_init()
{
	struct htoa_item **ht_items;
	ht_items = (struct htoa_item **) malloc(HTSIZE * sizeof(struct htoa_item *));
	for (int i = 0; i < HTSIZE; i++) {
		//ht_items[i]->key = NULL;
		//ht_items[i]->value = NULL;
		ht_items[i] = NULL;
	}
	return ht_items;
}

void htoa_insert(struct htoa_item **ht_items, char *key, int klen, char *value, int vlen)
{
	int index = hash_simple(key, klen, HTPRIME, HTSIZE);
	if (ht_items[index] == NULL) {
		ht_items[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
		ht_items[index]->key = strndup(key, klen);
		ht_items[index]->value = strndup(value, vlen);
	}
	else {
		while (ht_items[index] != NULL)
			index++;
		ht_items[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
		ht_items[index]->key = strndup(key, klen);
		ht_items[index]->value = strndup(value, vlen);
	}
}

char *htoa_search(struct htoa_item **ht_items, char *key, int klen)
{
	int index = 0;
	index = hash_simple(key, klen, HTPRIME, HTSIZE);
	if (ht_items[index] == NULL)
		return NULL;
	while (ht_items[index] != NULL && 
			strncmp(ht_items[index]->key, key, klen) != 0)
		index++;
	if (ht_items[index]->value != NULL)
		return ht_items[index]->value;
	else
		return NULL;
}

int htoa_delete_item(struct htoa_item **ht, char *key, int klen)
{
	int index = 0;
	index = hash_simple(key, klen, HTPRIME, HTSIZE);
	if (ht[index] == NULL)
		return 0;
	while (ht[index] != NULL && 
			strncmp(ht[index]->key, key, klen) != 0)
		index++;
	if (ht[index]->value != NULL) {
		free(ht[index]->key);
		free(ht[index]->value);
		ht[index]->key = NULL;
		ht[index]->value = NULL;
		free(ht[index]);
		return 1;
	}
	else
		return 0;
}
void htoa_traverse_tmp(struct htoa_item **ht)
{
	for (int i = 0; i < HTSIZE; i++) {
	}
}

void htoa_delete(struct htoa_item **ht)
{
	for (int i = 0; i < HTSIZE; i++) {
		if (ht[i] != NULL) {
			free(ht[i]->key);
			free(ht[i]->value);
			free(ht[i]);
		}
	}
	free(ht);
}
