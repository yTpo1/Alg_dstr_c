#ifndef HASH_TABLE_OADDR_DBLEHASH_H
#define HASH_TABLE_OADDR_DBLEHASH_H

/* Hash Table, implemented with double hasing */

#include "ht_item.h"

typedef struct {
	ht_item **ht;
	int size;
	int count;
} ht_dh;

ht_dh *htd_init(int size);
void htd_insert(ht_dh *h, char *k, char *v);
char *htd_search(ht_dh *h, char *k);
void htd_free(ht_dh *h);

#endif
