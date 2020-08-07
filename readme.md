# Algorithms and Data Structures in C
Note: 
* learning for different books and online resources made me realize that allot of these learning reasources either don't provide complete and correct implementation. So best choice is to be reading through a couple of them at the same time.

* Read/watch a couple of sources at the same time for the same topic
* Read the chapter first and try to implement it with out looking, and look only when stuck.

MEMORY: ALWAYS MAKE SURE ALL VARIABLES ARE INITIALIZED TO 0 OR NULL!!!! ALWAYS!!!! Use calloc where applicable. memset to 0 and so on

# Array:
Array also correspond directly to vectors, the mathematical term for indexed list of objects. 
Two-dimentsional arrays correspond to matrices. [src](#b-alg-c-segw)
* Find Median
* Find Max Min "find_max_min("
Search:
* Binary Search
* Max sub array

## Sorting Algorithms:
[Sorting](Docs/sorting.md)

## Searching
* backtracking
* sorting
* depth-first search & breadth-first search (graphs)

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

Operations:
* Initialize the data structure
* Search for a record (or records) having a given key.
* Insert a new record
* Delete a specified record
* Join two dictionaries to make a large one
* Sort the dictionary; output all records in sorted order
* Modify

Implemented:
* [Linked List](Docs/linked_list.md) 
* [Stack](Docs/stack.md) 
* [Queue](Docs/queue.md)
* [Tree](Docs/tree.md)
* Doubly Linked List
* Priority Queue -> look in "Stacks and queues" in Lafore
* [Heap](Docs/heap.md)
* Set/Disjoint-Set/Hash-Set
* [Graphs](Docs/graph.md)

* https://www.studytonight.com/data-structures/

#### Practical Aplications:
* https://stackoverflow.com/questions/1539069/practical-uses-of-different-data-structures

# Dynamic Programming
* Basic
* Advanced

# Cryptography
* Caesar
* Polyalphabetic
* https://www.youtube.com/watch?v=mbtI3w5qxnI&list=PL6qqFPx9xQ1hLOoYAiQ-Me0xa2nlDTjys
* https://www.khanacademy.org/computing/computer-science/cryptography

# Math and Numbers
* [numbers](Docs/numbers_math.md)
* Number Theory
* Counting
* Geometry

## Reusability
* How to build reusable data types and algorithms in C?
[tree.h in freebsd.](https://github.com/freebsd/freebsd/blob/master/sys/sys/tree.h) It implements functions inside some long macros. Before calling these functions, you need to instantiate them with proper types. This style is closer to C++ template and incurs little overhead in the sense that it can achieve the same performance as a type-specific implementation. This is my preference.

[list.h in Linux kernel.](https://github.com/torvalds/linux/blob/master/include/linux/list.h) It embeds a predefined struct to the struct holding the actual data. Here is an example program. uthash follows a somewhat similar route, though it uses much more macros.

[avl.c from libavl and Glib.](https://github.com/sam0x17/libavl_fork/blob/master/avl.c) It uses void\* pointers to represent generic data types. I don't like this approach personally because it often hurts performance. However, many others hold different opinions.

* Check out the book "C Interfaces and Implementations". It has a lot of good ideas and practices.


## Sources:
1. <a name="b_kr"></a>[Book] The C Programming Language 2nd Edition by Brian Kernighan and Dennis Ritchie
2. [Book] Wengrow Jay - A Common Sense Guide to Data Structures and Algorithms
3. <a name="b-alg-c-segw"></a>[Book] Algorithms in C by Robert Sedgewik
4. <a name="b_alg_fed_r_sedgw"></a>[Book] Algorithms by Robert Sedgewik, Kevin Wayne. Fourth edition.
459
5. <a name="alg_java_gtg"></a> [Book] "Data Structures and Algorithms in Java" by Goodrich M., Tamassia R., Goldwasser M.
6. https://github.com/jamesroutley/write-a-hash-table

# Todo:
* swap variables on memory, not array
* redo Max Min
* redo Stack
* recursion stuff
# todo:
* free the used memory
* c unit testing with assert
* c unit testing make cmake
* https://github.com/bats-core/bats-core
* https://cmocka.org/
