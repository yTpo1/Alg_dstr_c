#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"
#include "../Algorithms/hash_function.h"

#define HTPRIME 129

struct hash_table *ht_init()
{
	//struct hash_table *ht = (struct hash_table *) malloc(sizeof(ht));
	//struct hash_table *ht = (struct hash_table *) calloc(HTSIZE, sizeof(ht));
	//struct hash_table *ht = (struct hash_table *) calloc(1, sizeof(struct hash_table));
	struct hash_table *ht = (struct hash_table *) malloc(sizeof(struct hash_table));
	ht->size = 11;
	ht->ht = (struct htll_item **) malloc(ht->size * sizeof(struct htll_item *));
	for (int i = 0; i < ht->size; i++)
		ht->ht[i] = NULL;
	return ht;
}

//void ht_delete(struct hash_table *ht)
//{
//	for (int i = 0; i < ht->size; i++)
//		if (ht->ht[i] != NULL) {
//			free(ht->ht[i]->value);
//			free(ht->ht[i]->key);
//			free(ht->ht[i]);
//		}
//	free(ht->ht);
//	free(ht);
//}

void ht_delete(struct hash_table *ht)
{
	struct htll_item *tmp = NULL;
	struct htll_item *tmpnext = NULL;
	for (int i = 0; i < ht->size; i++) {
		if (ht->ht[i] != NULL) {
			tmp = ht->ht[i];
			while (tmp != NULL) {
				free(tmp->value);
				free(tmp->key);

				tmpnext = tmp->next;
				free(tmp);
				tmp = tmpnext;
				tmpnext = NULL;
			}
		}
	}
	free(ht->ht);
	free(ht);
}


void ht_insert(struct hash_table *ht, char *key, int klen, char *value, int vlen)
{
	struct htll_item *ht_i = NULL;
	unsigned index = hash_simple(key, klen, HTPRIME, ht->size);
	
	if (ht->ht[index] == NULL) {
		ht->ht[index] = (struct htll_item *) malloc(sizeof(struct htll_item));
		ht->ht[index]->next = NULL;
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
		return;
	}
	ht_i = ht->ht[index];
	while (ht_i->next != NULL)
		ht_i = ht_i->next;

	ht_i->next = (struct htll_item *) malloc(sizeof(struct htll_item));
	ht_i->next->next = NULL;
	ht_i->next->key = strndup(key, klen);
	ht_i->next->value = strndup(value, vlen);
}

char *ht_search(struct hash_table *ht, char *key, int len)
{
	struct htll_item *ht_i;
	unsigned index = hash_simple(key, len, HTPRIME, ht->size);
	ht_i = ht->ht[index];
	while (ht_i != NULL) {
		if (!strcmp(ht_i->key, key))
			return ht_i->value;
		ht_i = ht_i->next;
	}
	return NULL;
}
