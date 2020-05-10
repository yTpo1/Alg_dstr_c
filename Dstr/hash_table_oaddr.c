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
	while (strncmp(ht_items[index]->key, key, klen) != 0 && 
			ht_items[index] != NULL)
		index++;
	if (ht_items[index]->value != NULL)
		return ht_items[index]->value;
	else
		return NULL;
}
