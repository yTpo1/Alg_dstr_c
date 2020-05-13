# Graph
Graphs can be:
* weighted and unweighted
* connected and not connected
* directed and non-directed

Definition:
vertex(mult. vertices): node
edges: lines
weight: number, i.e. the distance, time or cost between two vertices

Methods of connecting graphs:
* adjacency matrix
* adjacency list

## Adjacency Matrix
Note: when adding an edge to the graph, two entries must be made in the adjacency matrix. This is because of the triangular-shaped matrix, in example:
||A|B|C|D|
|--|--|--|--|--|
|A|0|1|1|1|
|B|1|0|0|1|
|C|1|0|0|0|
|D|1|1|0|0|

## Adjacency List
Using linked list, in example:

|Vertex|List containing adjacent vertices|
|--|--|
|A|B->C->D|
|B|A->D|
|C|A|
|D|A->B|

Note: Not to be confused with path. All it shows is what node is one edge away.

## Searching a Graph
* depth-first search (DFS) implemented with a stack
* breadth-first search (BFS) implemented with a queue

### DFS
1. if possible, visin an adjacent unvisited vertex, mark it, and push it on the stack
2. if you can't follow Rule 1, then, if possible, pop a vertex off the stack
3. if you can't follow Rule 1 or Rule 2, you're done.

[src](#b_dstr_alg_java_r_lafore) page 615
* <a name="b_dstr_alg_java_r_lafore"></a> Data structures and algorithms in java by Robert Lafore. (Second edition)
