# todo:
* free the used memory
* c unit testing with assert
* c unit testing make cmake
* https://github.com/bats-core/bats-core
* https://cmocka.org/

# Algorithms and Data Structures in C
Note: learning for different books and online resources made me realize that allot of these learning reasources either don't provide complete and correct implementation. So best choice is to be reading through a couple of them at the same time.

## Number:
* Greatest Common Divisor "gcd(" 
  - Solution 1. "Euclid' algorithm Classsic. Origin 300BC": if u > v, then gcd of u and v, is same as gcd of v and u-v.  
If using classic: count of spets for _ _ is 11, and for _ _ is 58.  
  - Modulo: gcd of u and v is same as gcd of v and u % v.  
If using modulo: count of steps for _ _ is 4. And for _ _ is 7.  
[src](#b-alg-c-segw)  
* Reduce a given fraction to its lowest terms "fr_low_terms("
Is based on gcd.
* Convert a decimal to binary "d_to_b"
  - Algorithm:
    1. Store the remainder when the number is divided by 2 in an array.
    2. Divide the number by 2
    3. Repeat the above two steps until the number is greater than zero.
    4. Print the array in reverse order now.
    [src](https://www.geeksforgeeks.org/program-decimal-binary-conversion/)

## Array:
Array also correspond directly to vectors, the mathematical term for indexed list of objects. 
Two-dimentsional arrays correspond to matrices. [src](#b-alg-c-segw)
* Prime Numbers. Print all prime numbers less than 1000. "" Category: number, array   
  - Solution 1. "Sieve of Eratosthenes. Origin 300BC" [src](#b-alg-c-segw) TODO: implement with constraints of input array size, other wize a stack smash and buffer overflow is guaranteed.
* Find Median
* Find Max Min "find_max_min("
Search:
* Binary Search

## Sorting Algorithms:
Implemented:
* Bubble sort
* Heap sort
* Insertion sort
* Merge sort
* Quick sort - [src](#b-kr) - page:87,110,120
* Shell sort - [src](#b-kr) - page:62
* Straight selection sort

## String:
* String with Reverse Polish notation/postfix to stack
* remove char from string
* check anagram
* find duplicate characters
* string size
* check palindrome
* reverse array

## Data Structures / Abstract Data Types
||Reading|Searching|Insertion|Deletion|
|--|--|--|--|--|
|Array|O(1)|O(N)|O(N) or O(1) at the end|O(N) or O(1) at the end|
|Array Ordered|O(1)|O(log N)|O(N)|O(N)|
|Hash Table|O(1)|O(1)|O(1)|O(1)|
|Linked List|O(N)|O(N)|O(N) or O(1) at the begining|O(N) or O(1) at the begining|
|Doubly Linked List|O(N)|O(N)|O(1)|O(1)|
|Binary Tree|O(N)|O(log N)|O(log N)|O(log N)|
|Graph|-|O(1)|-|-|

* [Linked List](Docs/linked_list.md) 
* [Stack](Docs/stack.md) 
* [Queue](Docs/queue.md)
* [Tree](Docs/tree.md)

* https://www.studytonight.com/data-structures/

#### Practical Aplications:
* https://stackoverflow.com/questions/1539069/practical-uses-of-different-data-structures

# Todo:
* swap variables on memory, not array
* redo Max Min
* redo Stack
* recursion stuff
Data structures
---
* Doubly Linked List
* Graphs

Sources:
1. <a name="b-kr"></a>[Book] The C Programming Language 2nd Edition by Brian Kernighan and Dennis Ritchie
2. [Book] Wengrow Jay - A Common Sense Guide to Data Structures and Algorithms
3. <a name="b-alg-c-segw"></a>[Book] Algorithms in C by Robert Sedgewik
4. <a name="alg_java_gtg"></a> [Book] "Data Structures and Algorithms in Java" by Goodrich M., Tamassia R., Goldwasser M.
5. https://github.com/jamesroutley/write-a-hash-table

