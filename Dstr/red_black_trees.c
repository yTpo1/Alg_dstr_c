#include <stdio.h>
#include <stdlib.h>
#include "red_black_trees.h"
#include "queue.h"

#define BLACK 0
#define RED 1

rb_tree *rb_init(void)
{
	rb_tree *tree = (rb_tree *) malloc(sizeof(rb_tree));
	tree->root = NULL;

	tree->nullnode = (rb_node *) malloc(sizeof(rb_node));
	tree->nullnode->right = NULL;
	tree->nullnode->left = NULL;
	tree->nullnode->parent = NULL;
	tree->nullnode->v = 0;
	tree->nullnode->color = BLACK;

	return tree;
}

static rb_node *create_node(rb_tree *t, int v)
{
	rb_node *node = (rb_node *) malloc(sizeof(rb_node));
	node->parent = t->nullnode;
	node->left = t->nullnode;
	node->right = t->nullnode;
	node->v = v;
	node->color = RED;
	return node;
}

/* Left rotation ->
 * Right rotation <-
 *     D                  D
 *     |                  |
 *    (x)                (y)
 *    / \                / \
 *   A   (y)           (x)  C
 *       /  \          / \
 *      B    C        A   B
 */
static void left_rotate(rb_tree *t, rb_node *x)
{
	rb_node *y = x->right;		
	x->right = y->left;		// x->r = B
	if (y->left != t->nullnode)		// if (B != NULL)
		y->left->parent = x;    // B->p = x
	y->parent = x->parent;		// y->p = D
	if (x->parent == t->nullnode) 		// if (x is root)
		t->root = y;
	else if (x == x->parent->left)  // if (x is a left child of D)
		x->parent->left = y;	// D->l = y
	else
		x->parent->right = y;   // D->r = y
	y->left = x;
	x->parent = y;
}

static void right_rotate(rb_tree *t, rb_node *y)
{
	rb_node *x = y->left;		
	y->left = x->right;		// y->l = B
	if (x->right != t->nullnode)		// if (B != NULL)
		x->right->parent = y;    // B->p = y
	x->parent = y->parent;		// x->p = D
	if (y->parent == t->nullnode) 		// if (y is root)
		t->root = x;
	else if (y == y->parent->left)  // if (y is a left child of D)
		y->parent->left = x;	// D->l = x
	else
		y->parent->right = x;   // D->r = x
	x->right = y;
	y->parent = x;
}

static void colorflip(rb_node *z, rb_node *y)
{
	//colour-flip
	z->parent->color = BLACK;
	y->color = BLACK;
	z->parent->parent->color = RED; // B
	z = z->parent->parent; // z = B
}

/* () - red [] - black
 * Case 1: colorflip
 * 	 [B]
 *      /   \
 *    (A)    (y)
 *   /
 * (z)
 *
 * Case 2: rotate-left (A and B)
 * 	  [C]
 * 	 /   \
 *     (A)   H-y
 *    /   \
 *   E     (B-z)
 *         / \
 *        F   G
 *
 * Case 3: rotate-right (B and C) -> solution
 * 	  [C]			[B]
 * 	 /   \			/  \
 *     (B)   H-y 	     (A-z) (C)
 *    /   \		    /  \   /  \
 *  (A-z) G		   E   F   G   H
 *   / \
 *  E   F
 *
 */
static void rb_insert_fixup(rb_tree *t, rb_node *z)
{
	rb_node *y = NULL;
	while (z->parent->color == 1) {
		if (z->parent == z->parent->parent->left) { //if (A == B->left)
			y = z->parent->parent->right; // y
			// Case 1
			if (y->color == RED)
				colorflip(z, y);
			else {
				// Case 2 + Case 3
				if (z == z->parent->right) {
					z = z->parent; // z = A
					left_rotate(t, z); // (A as x) and (B-z as y)
				}
				// Case 3
				z->parent->color = BLACK; // B->color = Black
				z->parent->parent->color = RED; // C->color = RED
				right_rotate(t, z->parent->parent); // (C as y) and (B as x)
			}
		} 
		else { // A == B->right
			y = z->parent->parent->left;
			if (y->color == RED)
				colorflip(z, y);
			else {
				if (z == z->parent->left) {
					z = z->parent; 
					right_rotate(t, z); 
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(t, z->parent->parent);
			}
		}
	}
	t->root->color = BLACK;
}

void rb_insert(rb_tree *t, int v)
{
	rb_node *new = create_node(t, v);
	rb_node *next = t->root;
	rb_node *n = NULL;

	while (next != NULL && next != t->nullnode) {
		n = next;
		if (v >= next->v)
			next = next->right;
		else
			next = next->left;
	}
	new->parent = n;
	if (t->root == NULL) {
		t->root = new;
		t->root->parent = t->nullnode;
		t->root->color = BLACK;
		return;
	}
	else if (v >= n->v) 
		n->right = new;
	else
		n->left = new;

	rb_insert_fixup(t, new);
}

int rb_size(rb_tree *t, rb_node *root)
{
	if (root == NULL || root == t->nullnode)
		return 0;
	return 1 + rb_size(t, root->left) + rb_size(t, root->right);
	
}

static void inorder_traversal(rb_tree *t, rb_node *root, struct queue *q)
{
	if (root == NULL || root == t->nullnode) 
		return;
	inorder_traversal(t, root->left, q);
	q_enqueue(q, root->v);
	inorder_traversal(t, root->right, q);
}


void rb_inorder_traversal(rb_tree *t, int *a)
{
	int i = 0;
	struct queue *q = q_init(rb_size(t, t->root));
	inorder_traversal(t, t->root, q);
	while (!q_isempty(q))
		a[i++] = q_dequeue(q);
	q_free(q);
}

void rb_free(rb_tree *t, rb_node *r)
{
	int last = 0;
	if (r == NULL || r == t->nullnode)
		return;
	rb_free(t, r->left);
	rb_free(t, r->right);
	if (r == t->root) {
		free(t->nullnode);
		t->nullnode = NULL;
		last = 1;
	}
	free(r);
	r = NULL;
	if (last)
		free(t);
}
