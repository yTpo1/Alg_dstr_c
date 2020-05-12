//#define HTSIZE  11 // maxbuckets, also should be prime?


struct htll_item {
	struct htll_item *next;
	char *key;
	char *value;
};

//struct htll_item *hash_table[HTSIZE];

struct hash_table {
	//struct htll_item **ht;
	//struct htll_item *ht[HTSIZE];
	struct htll_item **ht;
	int size;
};
//int *ht_table;

struct hash_table *ht_init();
void ht_delete(struct hash_table *ht);
//void ht_insert(struct hash_table *ht, char *value, int len);
void ht_insert(struct hash_table *ht, char *key, int klen, char *value, int vlen);
char *ht_search(struct hash_table *ht, char *value, int len);

// Hasing functions
//unsigned hash(char *value, int len);
//unsigned hash(char *value, int len, int prime, int htsize);
