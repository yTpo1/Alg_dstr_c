# Heap
Is a binary tree data structure. Its complete (completely filled in, reading left to right) and is implemented with an array/array like data structure (to allow for easy resizing). [Representing tree an array](./tree.md#asanarray)
Can be one of two strategies.
1. min heap
2. max heap

Each affect the properties of the tree. 
With min heap, the parent node has a value <= than its children. I.E the node at the root is the smallest value in the tree.With the opposite rules for max heap.

Calculating the index of nodes:
* parent node: (index-1)/2
* left child: 2 * index + 1
* right child: 2 * index + 2

|Name|Run time|
|--|--|
|Max-Heapify|O(log n)|
|Heap Sort|O(n log n)|

* https://www.geeksforgeeks.org/building-heap-from-array/

# Priority Queue
Is implemented with a min-heap.
Is just an inerface with restriction on delete, to the head data structure.


Offers convenient access to the data Item with the smallest (or largest) key.

Priority queues may be used for task scheduling in computers, where some programs and activities should be executed sooner than others and are therefore given a higher priority.

Priority queues are also used internally in other computer algorithms. In Chapter 14, “Weighted Graphs,” we’ll see priority queues used in graph algorithms, such as Dijkstra’s algorithm.

# Heap Sort
Is implemented with a max-heap.

## Sources:
* [Book] Data Structure and Algorithms by Granville Barnett and Luce Del Tongo
* <a name="b_dstr_alg_java_r_lafore"></a> Data structures and algorithms in java by Robert Lafore. (Second edition)
