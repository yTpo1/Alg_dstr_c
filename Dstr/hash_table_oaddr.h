// Hash Table Open Addressing
struct htoa_item {
	char *key;
	char *value;
};

struct htoa {
	struct htoa_item **ht;
	int size;
	int count;
};

//struct htoa_item **htoa_init();
struct htoa *htoa_init();
//void htoa_insert(struct htoa_item **ht_items, char *key, int klen, char *value, int vlen);
void htoa_insert(struct htoa *ht, char *key, int klen, char *value, int vlen);
//char *htoa_search(struct htoa_item **ht_items, char *key, int klen);
char *htoa_search(struct htoa *ht, char *key, int klen);
//int htoa_delete_item(struct htoa_item **ht, char *key, int klen);
int htoa_delete_item(struct htoa *ht, char *key, int klen);
//void htoa_delete(struct htoa_item **ht);
void htoa_delete(struct htoa *ht);
//void htoa_traverse_tmp(struct htoa_item **ht);
