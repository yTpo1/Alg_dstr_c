#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table_oaddr.h"
#include "../Algorithms/hash_function.h"
#include "../Algorithms/numbers.h"

#define HTPRIME 129 // prime larger than total ascii characters

static int find_closest_prime(int n)
{
	while (isprime_trial_division(n) == 0)
		n++;
	return n;
}

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
	
	struct htoa_item **tmp = NULL;
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

static struct htoa_item **new_ht_array(int size)
{
	struct htoa_item **ht = (struct htoa_item **) malloc(size * sizeof(struct htoa_item *));
	for (int i = 0; i < size; i++) {
		ht[i] = NULL;
	}
	return ht;
}


static void check_size(struct htoa *ht)
{
	if (ht->size < 11)
		return;
	float load = (float)ht->count / (float)ht->size;
	printf("count:%d size:%d load: %f\n", ht->count, ht->size, load);

	if (load > 0.7) 
		resize(ht, ht->size * 2);
	else if (load < 0.1)
		resize(ht, ht->size / 2);
//	printf("check_size ht->size:%d\n", (*ht)->size);
}

// init ht_delete ht_insert ht_search
struct htoa *htoa_init(int size)
{
	struct htoa *ht;
	ht = (struct htoa *) malloc(sizeof(struct htoa));
	if (size < 11)
		size = 11;
	ht->size = find_closest_prime(size); // initial prime number size
	//printf("init ht->size: %d\n", ht->size);
	ht->ht = (struct htoa_item **) malloc(ht->size * sizeof(struct htoa_item *));
	ht->count = 0;
	for (int i = 0; i < ht->size; i++) {
		//ht_items[i]->key = NULL;
		//ht_items[i]->value = NULL;
		ht->ht[i] = NULL;
	}
	return ht;
}

//struct htoa_item **htoa_init()
//{
//	struct htoa_item **ht_items;
//	ht_items = (struct htoa_item **) malloc(HTSIZE * sizeof(struct htoa_item *));
//	for (int i = 0; i < HTSIZE; i++) {
//		//ht_items[i]->key = NULL;
//		//ht_items[i]->value = NULL;
//		ht_items[i] = NULL;
//	}
//	return ht_items;
//}

static void insert(struct htoa *ht, char *key, int klen, char *value, int vlen)
{
	int index = hash_simple(key, klen, HTPRIME, ht->size);
	if (ht->ht[index] == NULL) {
		ht->ht[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
	}
	else {
		while (ht->ht[index] != NULL)
			index++;
		ht->ht[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
		ht->ht[index]->key = strndup(key, klen);
		ht->ht[index]->value = strndup(value, vlen);
	}
	ht->count = ht->count + 1;
}


//void htoa_insert(struct htoa *ht, char *key, char *value)
void htoa_insert(struct htoa *ht, char *key, int klen, char *value, int vlen)
{
	check_size(ht);
	insert(ht, key, klen, value, vlen);
}

//void htoa_insert(struct htoa_item **ht_items, char *key, int klen, char *value, int vlen)
//{
//	int index = hash_simple(key, klen, HTPRIME, HTSIZE);
//	if (ht_items[index] == NULL) {
//		ht_items[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
//		ht_items[index]->key = strndup(key, klen);
//		ht_items[index]->value = strndup(value, vlen);
//	}
//	else {
//		while (ht_items[index] != NULL)
//			index++;
//		ht_items[index] = (struct htoa_item *) malloc(sizeof(struct htoa_item));
//		ht_items[index]->key = strndup(key, klen);
//		ht_items[index]->value = strndup(value, vlen);
//	}
//}

//char *htoa_search(struct htoa_item **ht_items, char *key, int klen)
//{
//	int index = 0;
//	index = hash_simple(key, klen, HTPRIME, HTSIZE);
//	if (ht_items[index] == NULL)
//		return NULL;
//	while (ht_items[index] != NULL && 
//			strncmp(ht_items[index]->key, key, klen) != 0)
//		index++;
//	if (ht_items[index]->value != NULL)
//		return ht_items[index]->value;
//	else
//		return NULL;
//}

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

//int htoa_delete_item(struct htoa_item **ht, char *key, int klen)
//{
//	int index = hash_simple(key, klen, HTPRIME, HTSIZE);
//	if (ht[index] == NULL)
//		return 0;
//	while (ht[index] != NULL && 
//			strncmp(ht[index]->key, key, klen) != 0)
//		index++;
//	if (ht[index]->value != NULL) {
//		free(ht[index]->key);
//		free(ht[index]->value);
//		ht[index]->key = NULL;
//		ht[index]->value = NULL;
//		free(ht[index]);
//		return 1;
//	}
//	else
//		return 0;
//}

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

//void htoa_traverse_tmp(struct htoa_item **ht)
//{
//	for (int i = 0; i < HTSIZE; i++) {
//	}
//}

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
