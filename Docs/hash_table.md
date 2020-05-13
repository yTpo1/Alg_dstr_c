Contents:
* Hash Table (Associative Array Abstract Data Type)
  - Hashing
  - Collisions
    * Open Addressing
      - Linear probing
    * Separate chaining
  - Resizing
  - Hash Search

# Hash Table (Associative Array Abstract Data Type)
An associative array, map, symbol table, or dictionary is an abstract data type composed of a collection of (key, value) pairs, such that each possible key appears at most once in the collection. 
* https://en.wikipedia.org/wiki/Associative_array

A hash table is a data structure that offers very fast insertion and searching. 
Hash tables are faster than trees, but can't visit items in order.
[src](#b_dstr_alg_java_r_lafore) page 544

Rules:
1) Array size should always me a prime number

## Hashing
[Hash function](./hash_function.md)

## Collisions
### Open Addressing
When a collision occures, another location in the array is sought. Search the array is some systematic wayfor an empty cell and isert the new item there.

Methods of open addressing:
* linear probing
* quadratic probing
* double hashing

#### Linear probing
In linear probing we search sequentially for vacant cells. i.e. if 200 is occupied then we try 201, 202 and so on until an empty cell is found.

Pitfall/drawback: clusters can occur, and keep growing larger and larger. The bigger the cluster gets, the faster it grows.

#### Quadratic probing
#### Double hashing

### Separate chaining
When a collision occurs, the new item is inserted in the linked list at that index.

## Resizing / Rehashing
* New array size should be at least twice the size, and must also be a prime number.
* items from old array can't be just copied over and must be rehashed according to new size 

Load: ratio of filled bucket to total buckets

[Prime numbers](../Docs/prime_numbers.md)

## Hash Search
[src](#b_kr)


Sources:
* <a name="b_kr"></a>[Book] The C Programming Language 2nd Edition by Brian Kernighan and Dennis Ritchie
* <a name="b_dstr_alg_java_r_lafore"></a> Data structures and algorithms in java by Robert Lafore. (Second edition)
* https://github.com/jamesroutley/write-a-hash-table
