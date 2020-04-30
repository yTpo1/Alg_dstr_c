# Algorithms and Data Structures in C
Number:
* gcd - Euclid' algorithm.  
Classsic: if u > v, then gcd of u and v, is same as gcd of v and u-v.  
If using classic: count of spets for _ _ is 11, and for _ _ is 58.  
Modulo: gcd of u and v is same as gcd of v and u % v.  
If using modulo: count of steps for _ _ is 4. And for _ _ is 7.  
[src](#b-acrs)  

Array:
* Find Median
* Find Max Min
Search:
* Binary Search

### Sorting Algorithms:
||Reading|Searching|Insertion|Deletion|
|--|--|--|--|--|
|Array|O(1)|O(N)|O(N) or O(1) at the end|O(N) or O(1) at the end|
|Hash Table|-|O(1)|O(1)|O(1)|
|Array Ordered|-|O(log N)|O(N)|O(N)|
|Linked List|O(N)|O(N)|O(N) or O(1) at the begining|O(N) or O(1) at the begining|
|Doubly Linked List|O(N)|O(N)|O(1)|O(1)|
|Binary Tree|O(N)|O(log N)|O(log N)|O(log N)|
|Graph|-|O(1)|-|-|

Implemented:
* Bubble sort
* Heap sort
* Insertion sort
* Merge sort
* Quick sort - [src](#b-kr) - page:87,110,120
* Shell sort - [src](#b-kr) - page:62
* Straight selection sort

String:
* remove char from string
* check anagram
* find duplicate characters
* string size
* check palindrome
* reverse array

Data Structures:
* Stack (push, pop)
* Linked List (init, insert, delete, traverse)
* Circular Linked List (init, insert, traverse)
* Binary Tree (init, insert, delete, traverse

# todo:
* swap variables on memory, not array
* redo Max Min
* redo Stack
* implement queue
* recursion stuff
* doubly linked list
* graphs

Sources:
1. <a name="b-kr"></a>[Book] The C Programming Language 2nd Edition by Brian Kernighan and Dennis Ritchie
2. [Book] Wengrow Jay - A Common Sense Guide to Data Structures and Algorithms
3. <a name="b-acrs"></a>[Book] Algorithms in C by Robert Sedgewik
4. https://github.com/jamesroutley/write-a-hash-table

