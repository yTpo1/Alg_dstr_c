// Hash Table Open Addressing
struct htoa_item {
	char *key;
	char *value;
};

struct htoa_item **htoa_init();
void htoa_insert(struct htoa_item **ht_items, char *key, int klen, char *value, int vlen);
char *htoa_search(struct htoa_item **ht_items, char *key, int klen);
