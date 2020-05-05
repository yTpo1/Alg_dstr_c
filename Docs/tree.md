Tags: tree, binary tree, recursion
# Tree
### Terminology
tree - nonempty collection of vertices and edges
vertex - node
edge - connection between two vertices
root - the top of the tree
parent - is the node directly above
children - are nodes directly below
external (leaves, terminal nodes) - nodes with no children 
internal (nonterminal nodes) - nodes with at least one child.
[src](#b-alg-c-segw) page 36
[src](#dstr_a_wengrow_j) page 230

### Properties
1. There is exactly one path between any two nodes in a tree. 
2. A tree with N nodes has N - 1 edges.
3. A binary tree with N internal nodes has N + 1 external node.
4. The external path length of any binary tree with N internal nodes is 2N greater than the internal path length.
5. The height of a full binary tree with N internal nodes is about log2N
[src](#b-alg-c-segw) page 38

## Binary Tree. 
Binary trees boast efficiencies of O(log N) for search, insertion, and deletion, making it an efficient choice for scenarios in which we need to store and manipulate ordered data. This is particularly true if we will be modifying the data often, because while ordered arrays are just as fast as binary trees when searching data, binary trees are significantly faster when it comes to inserting and deleting data.
[src](#dstr_a_wengrow_j) page 249


### Properties
1. Each node has either zero, one, or two children.
2. If a node has two children, it must have one child that has a lesser value than the parent, and one child that has a greater value than the parent.
[src](#dstr_a_wengrow_j) page 230

### Implementation

Search:  
1. Inspect the value at the node.
2. If we've found the value we're looking for, great!
3. if the value we're looking for is less that the current node, search for it in its left subtree.
4. If the value we're looking for is grater that the current node, search for it in its right subtree
[src](#dstr_a_wengrow_j) page 234

Traversal:
1. Pre-order Traversal:
  * Process data of root node.
  * First, traverse left subtree completely.
  * Then, traverse right subtree.
2. In-order Traversal
  * First process left subtree.
  * Then, process current root node.
  * Then, process right subtree.
3. Post-order Traversal
  * First traverse left subtree completely.
  * Then, traverse right subtree completely.
  * Then, process data of node.

[src](#link1)
During traversal use stack to record each element. After convert it to array.

### Application / Real World Examples
* a

### Problems / Exercises
* a

## Sources
* <a name="dstr_a_wengrow_j"></a>[book] A Common-Sense Guide to Data Structures and Algorithms - Jay Wengrow (2017)
* <a name="link1" href="https://www.studytonight.com/data-structures/binary-search-tree">link1</a>
* 
