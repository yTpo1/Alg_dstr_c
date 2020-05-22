#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

unsigned hash_simple(char *value, int len, int prime, int htsize);
unsigned hash_horner(char *value, int len, int prime, int htsize);

#endif
