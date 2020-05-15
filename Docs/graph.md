tags: graph, backtracking algorithm
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

Depth-first search of a graph represented with an adjacency matrix requires time proportional to V^2.

#### Detecting Cycles in a undirected graph
A graph has a cycle if and only if a nonzero val entry is discovered in visit. That is, if we encounter an edge pointing to a vertex that we've already visited, then we have a cycle.
* https://stackoverflow.com/questions/31532887/detecting-cycle-in-an-undirected-graph-using-iterative-dfs

Depth-First Search and Game Simulations
Depth-first searches are often used in simulations of games (and game-like situations in the real world). In a typical game you can choose one of several possible actions. Each choice leads to further choices, each of which leads to further choices, and so on into an ever-expanding tree-shaped graph of possibilities. A choice point corresponds to a vertex, and the specific choice taken corresponds to an edge, which leads to another choice-point vertex.

* https://en.wikipedia.org/wiki/Depth-first_search
* https://www.youtube.com/watch?v=zaBhtODEL0w
#### Applications of DFS
Depth-first searches are often used as subroutines in other more complex algorithms. For example, the matching algorithm, Hopcroft–Karp, uses a DFS as part of its algorithm to help to find a matching in a graph. DFS is also used in tree-traversal algorithms, also known as tree searches, which have applications in the traveling-salesman problem and the Ford-Fulkerson algorithm.
* Depth-first search is used in topological sorting, scheduling problems, cycle detection in graphs, and solving puzzles with only one solution, such as a maze or a sudoku puzzle.
* Other applications involve analyzing networks, for example, testing if a graph is bipartite. Depth-first search is often used as a subroutine in network flow algorithms such as the Ford-Fulkerson algorithm.
* DFS is also used as a subroutine in matching algorithms in graph theory such as the Hopcroft–Karp algorithm.
* Depth-first searches are used in mapping routes, scheduling, and finding spanning trees.
* https://brilliant.org/wiki/depth-first-search-dfs/


[src](#b_dstr_alg_java_r_lafore) page 615
* <a name="b_dstr_alg_java_r_lafore"></a> Data structures and algorithms in java by Robert Lafore. (Second edition)
