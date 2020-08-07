#ifndef HASHTABLE_CHAR_INT_H
#define HASHTABLE_CHAR_INT_H

typedef struct {
	char k;
	int v;
} ht_item;

typedef struct {
	ht_item **ht;
	int size;
	int count;
} ht_int_char;

#endif
