#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table_oaddr.h"
#include "../Algorithms/hash_function.h"
#include "../Algorithms/prime_numbers.h"

#define HTPRIME 129 // prime larger than total ascii characters

static void rehash(struct htoa *ht, struct htoa *nht)
{
	for (int i = 0; i < ht->size; i++) {
		if (ht->ht[i] != NULL)
			insert(nht, ht->ht[i]->key,
				strlen(ht->ht[i]->key),
				ht->ht[i]->value,
				strlen(ht->ht[i]->value));
	}
}

static void resize(struct htoa *ht, int new_aprox_size)
{
	struct htoa *new_ht = htoa_init(new_aprox_size);
	rehash(ht, new_ht);
	
	ht_item **tmp = NULL;
	int tmpsize = ht->size;
	tmp = ht->ht;

	ht->ht = new_ht->ht;
	ht->count = new_ht->count;
	ht->size = new_ht->size;

	new_ht->ht = tmp;
	new_ht->size = tmpsize;
	htoa_delete(new_ht);
	//ht = new_ht;
	//printf("changing size to new_aprox_size:%d ht->size:%d newht->size:%d\n", new_aprox_size, ht->size, new_ht->size);
}

static ht_item **new_ht_array(int size)
{
	ht_item **ht = (ht_item **) malloc(size * sizeof(ht_item *));
	for (int i = 0; i < size; i++) {
		ht[i] = NULL;
	}
	return ht;
}


static void check_size(struct htoa *ht)
{
	if (ht->size < 11)
		return;
	float load = (float) ht->count / (float) ht->size;

	if (load > 0.7) 
		resize(ht, ht->size * 2);
	else if (load < 0.1)
		resize(ht, ht->size / 2);
}

struct htoa *htoa_init(int size)
{
	struct htoa *ht = (struct htoa *) malloc(sizeof(struct htoa));
	if (size < 11)
		ht->size = 11;
	else
		ht->size = find_closest_prime(size); // initial prime number size
	ht->ht = (ht_item **) malloc(ht->size * sizeof(ht_item *));
	ht->count = 0;
	for (int i = 0; i < ht->size; i++) {
		//ht_items[i]->key = NULL;
		//ht_items[i]->value = NULL;
		ht->ht[i] = NULL;
	}
	return ht;
}

static void insert(struct htoa *ht, char *key, int klen, char *value, int vlen)
{
	int index = hash_simple(key, klen, HTPRIME, ht->size);
	if (ht->ht[index] == NULL) {
		ht->ht[index] = (ht_item *) malloc(sizeof(ht_item));
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
	}
	else {
		while (ht->ht[index] != NULL)
			index++;
		ht->ht[index] = (ht_item *) malloc(sizeof(ht_item));
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
	}
	ht->count = ht->count + 1;
}

void htoa_insert(struct htoa *ht, char *key, int klen, char *value, int vlen)
{
	check_size(ht);
	insert(ht, key, klen, value, vlen);
}

char *htoa_search(struct htoa *ht, char *key, int klen)
{
	int index = hash_simple(key, klen, HTPRIME, ht->size);
	if (ht->ht[index] == NULL)
		return NULL;
	while (ht->ht[index] != NULL && 
			strncmp(ht->ht[index]->key, key, klen) != 0)
		index++;
	if (ht->ht[index]->value != NULL)
		return ht->ht[index]->value;
	else
		return NULL;
}

int htoa_delete_item(struct htoa *ht, char *key, int klen)
{
	check_size(ht);
	int index = hash_simple(key, klen, HTPRIME, ht->size);
	if (ht->ht[index] == NULL)
		return 0;
	while (ht->ht[index] != NULL && 
			strncmp(ht->ht[index]->key, key, klen) != 0)
		index++;
	if (ht->ht[index]->value != NULL) {
		free(ht->ht[index]->key);
		ht->ht[index]->key = NULL;
		free(ht->ht[index]->value);
		ht->ht[index]->value = NULL;

		free(ht->ht[index]);
		ht->ht[index] = NULL;

		ht->count = ht->count - 1;
		return 1;
	}
	else
		return 0;
}

void htoa_delete(struct htoa *ht)
{
	for (int i = 0; i < ht->size; i++) {
		if (ht->ht[i] != NULL) {
			free(ht->ht[i]->key);
			ht->ht[i]->key = NULL;
			free(ht->ht[i]->value);
			ht->ht[i]->value = NULL;
			free(ht->ht[i]);
			ht->ht[i] = NULL;
		}
	}
	free(ht->ht);
	ht->ht = NULL;
	free(ht);
	ht = NULL;
}
