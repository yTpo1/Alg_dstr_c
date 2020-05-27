#ifndef HASH_TABLE_SEP_CHAIN_H
#define HASH_TABLE_SEP_CHAIN_H

/* Hash Table with separate chaining.
 * All elements that hash to the same slot are placed in the same linked list.
 */

struct htll_item {
	struct htll_item *next;
	char *key;
	char *value;
};

typedef struct {
	struct htll_item **ht;
	int size;
} htsc;

htsc *htsc_init(void);
void htsc_delete(htsc *ht);
void htsc_insert(htsc *ht, char *key, int klen, char *value, int vlen);
char *htsc_search(htsc *ht, char *value, int len);

#endif
