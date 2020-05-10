#include <math.h>

// modular hashing
unsigned hash_simple(char *value, int len, int prime, int htsize)
{
	unsigned key = 0;
	for (int i = 0; i < len; i++)
		key = value[i] + prime * key;
	return key % htsize;
}

// modular hashing
unsigned hash_horner(char *value, int len, int prime, int htsize)
{
	unsigned key = 0;
	for (int i = 0; i < len; i++) {
		key += (pow(prime, (len - (i+1))) * value[i]);
		key = key % htsize;
	}
	return key % htsize;
}
