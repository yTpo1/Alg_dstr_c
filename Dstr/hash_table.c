#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash_table.h"

struct hash_table *ht_init()
{
	//struct hash_table *ht = (struct hash_table *) malloc(sizeof(ht));
	struct hash_table *ht = (struct hash_table *) calloc(HTSIZE, sizeof(ht));
	return ht;
}

void ht_delete(struct hash_table *ht)
{
	struct ht_item *tmp = NULL;
	struct ht_item *tmpnext = NULL;
	for (int i = 0; i < HTSIZE; i++)
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
			if (ht->ht[i] != NULL)
				free(ht->ht[i]);
			//free(ht->ht[i]->value);
			//free(ht->ht[i]->key);
			//free(ht->ht[i]);
		}
	free(ht);
}


void ht_insert(struct hash_table *ht, char *key, int klen, char *value, int vlen)
{
	struct ht_item *ht_i = NULL;
	unsigned index = hash_simple(key, klen, HTPRIME, HTSIZE);
	
	if (ht->ht[index] == NULL) {
		ht->ht[index] = (struct ht_item *) malloc(sizeof(struct ht_item));
		ht->ht[index]->next = NULL;
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
		return;
	}
	ht_i = ht->ht[index];
	while (ht_i->next != NULL)
		ht_i = ht_i->next;

	ht_i->next = (struct ht_item *) malloc(sizeof(struct ht_item));
	//ht_i->next = (struct ht_item *) calloc(1, sizeof(struct ht_item));
	ht_i->next->next = NULL;
	ht_i->next->key = strndup(key, klen);
	ht_i->next->value = strndup(value, vlen);
		//if (ht_i->next == NULL) {
		//	ht_i = (struct ht_item *) malloc(sizeof(struct ht_item));
		//	ht_i->key = strndup(key, klen);
		//	ht_i->value = strndup(value, vlen);
		//	break;
		//}
		//else if (ht_i->next == NULL) {
		//	ht_i->next = (struct ht_item *) malloc(sizeof(struct ht_item));
		//	ht_i->next->key = strndup(key, klen);
		//	ht_i->next->value = strndup(value, vlen);
		//	break;
		//}
		//ht_i = ht_i->next;
	//}

}

char *ht_search(struct hash_table *ht, char *key, int len)
{
	struct ht_item *ht_i;
	unsigned index = hash_simple(key, len, HTPRIME, HTSIZE);
	ht_i = ht->ht[index];
	while (ht_i != NULL) {
		if (!strcmp(ht_i->key, key))
			return ht_i->value;
		ht_i = ht_i->next;
	}
	return NULL;
}
