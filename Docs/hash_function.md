tags: hash, hash function, hash table, prime, prime numbers
# Hash Function

### Usages
* finding an entry in a database by a key value
* can be used to determine if two objects are equal (possibly with a fixed average number of mistakes)
* checksums over a large amount of data (e.g., the cyclic redundancy check [CRC])

## Methods
### Horners method/rule - Modular hashing
Array size M should be prime.(Not using a prime will result in not an even distribution.)

[Math polynomial](#math_polynomial.md)
[src](#b_alg_fed_r_sedgw) page 460

## Sources
* https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing
* <a name="b_alg_fed_r_sedgw"></a>[Book] Algorithms by Robert Sedgewik, Kevin Wayne. Fourth edition.
* https://www.cs.cornell.edu/courses/cs312/2008sp/lectures/lec21.html
* https://mathworld.wolfram.com/HashFunction.html
* https://www.tutorialspoint.com/cryptography/cryptography_hash_functions.htm
