#ifndef HASH_TABLE_OADDR_H
#define HASH_TABLE_OADDR_H

#include "ht_item.h"

/* Hash Table Open Addressing
 * Linear probing
 * Drawback: clustering
 */

struct htoa {
	ht_item **ht;
	int size;
	int count;
};

struct htoa *htoa_init(int size);
void htoa_insert(struct htoa *ht, char *key, int klen, char *value, int vlen);
char *htoa_search(struct htoa *ht, char *key, int klen);
int htoa_delete_item(struct htoa *ht, char *key, int klen);
void htoa_delete(struct htoa *ht);


static ht_item **new_ht_array(int size);
static void check_size(struct htoa *ht);
static void resize(struct htoa *ht, int new_aprox_size);
static void rehash(struct htoa *ht, struct htoa *nht);
static int find_closest_prime(int n);
static void insert(struct htoa *ht, char *key, int klen, char *value, int vlen);

#endif
