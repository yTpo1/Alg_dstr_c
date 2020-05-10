#include "../Algorithms/hash_function.h"
#define HTSIZE  11 // maxbuckets, also should be prime?
#define HTPRIME 129

struct ht_item {
	struct ht_item *next;
	char *key;
	char *value;
};

//struct ht_item *hash_table[HTSIZE];

struct hash_table {
	//struct ht_item **ht;
	struct ht_item *ht[HTSIZE];
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
