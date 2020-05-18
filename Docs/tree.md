Tags: tree, binary tree, recursion
Contents:
* [Representing tree as an Array](#asanarray)

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

Deletion:
1. If the node being deleted has no children, simply delete it.
2. If the node being deleted has one child, delete it and plug the child into the spot where the deleted node was
3. When deleting a node with two children, replace the deleted node with the successor node. The successor node is the child node whose value is the least of all values that are greater than the deleted node.
  * If the successor node has a right child, after plugging the successor node into the spot of the deleted node, take the right child of the successor node and turn it into the left child of the parent of the successor node.

```
    def delete(self, value_to_delete, node):
        # The base case is when we've hit the bottom of the tree,
        # and the parent node has no children:
        if node is None:
            return None

        # If the value we're deleting is less or greater than the current node,
        # we set the left or right child respectively to be
        # the return value of a recursive call of this very method on the
        current
        # node's left or right subtree.
        elif value_to_delete < node.value:
            node.left_child = self.delete(value_to_delete, node.left_child)
            # We return the current node (and its subtree if existent) to
            # be used as the new value of its parent's left or right child:
            return node
        elif value_to_delete > node.value:
            node.right_child = self.delete(value_to_delete, node.right_child)
            return node

        # If the current node is the one we want to delete:
        elif value_to_delete == node.value:

            # If the current node has no left child, we delete it by
            # returning its right child (and its subtree if existent)
            # to be its parent's new subtree:
            if node.left_child is None:
                return node.right_child

            # (If the current node has no left OR right child, this ends up
            # being None as per the first line of code in this function.) 
            # or as I have noticed, being covered by the obove if statement
            elif node.right_child is None:
                return node.left_child

            # If the current node has two children, we delete the current node
            # by calling the lift function (below), which changes the current
            node's
            # value to the value of its successor node:
            else:
                node.right_child = self.lift(node.right_child, node)
                return node

    def lift(self, node, node_to_delete):
        # If the current node of this function has a left child,
        # we recursively call this function to continue down
        # the left subtree to find the successor node.
        if node.left_child:
            node.left_child = self.lift(node.left_child, node_to_delete)
            return node
        # If the current node has no left child, that means the current node
        # of this function is the successor node, and we take its value
        # and make it the new value of the node that we're deleting:
        else:
            node_to_delete.value = node.value
            # We return the successor node's right child to be now used
            # as its parent's left child:
            return node.right_child
```
[src](#dstr_a_wengrow_j) page 247

[src](#link1)
During traversal use stack to record each element. After convert it to array.

### Application / Real World Examples
* a

### Problems / Exercises
* a

## Representing tree as an Array <a name="asanarray"></a>

## Red Black Trees
Defining red and black is done with boolean values.

Rules:
* Every node is red or black 
* Root is always black
* New insertions are always red
* Every path from root to leaf has the same number of **Black** nodes
* No path can have two censecutive RED nodes (but can have consecutive black nodes)
* Nulls are black

Rebalance:
* Black aunt - rotate
* Red aunt - colorflip

After rotation:
	Black
      /        \
    Red		Red

After colorflip:
	Red
      /      \
    Black    Black

In the rotation and colorfliping participate 3 nodes: child, parent and aunt.

Balancing:

* z's uncle y is black and z is a right child - left rotation
* z's uncle y is black and z is a left child - colorflip, then right rotation

* If the imbalance is in the right child, right subtree, then we do a left rotation.
* If the imbalance is in the right child, left subtree, then we do a right-left rotation.
* If the imbalance is in the left childs, right subtree, then we do a left-right rotation.
* If the imbalance is in the left childs, 

The red black tree is a mechanism for balancing a tree by using the labels to tell us when to rebalance. Rather than using difference in height like the AVL tree does.
The red black tree relies on having a boolean that we've set as either red or black and if there's a violation in the properties (there are six rules we have to look at) then we rebalance the tree.

* https://www.youtube.com/watch?v=nMExd4DthdA
* https://www.youtube.com/watch?v=v6eDztNiJwo

## Sources
* <a name="dstr_a_wengrow_j"></a>[book] A Common-Sense Guide to Data Structures and Algorithms - Jay Wengrow (2017)
* <a name="link1" href="https://www.studytonight.com/data-structures/binary-search-tree">link1</a>
* 
