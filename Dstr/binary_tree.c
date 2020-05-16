#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"
#include "stack_ll.h"
#include "queue.h"

static struct tree_node *insert(struct tree_node *node, int v);
static int search(struct tree_node *node, int v);
static struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del);
static struct tree_node *delete(struct tree_node *node, int key);
static void preoder_traversal(struct tree_node *node, struct queue *st);
static void inorder_traversal(struct tree_node *node, struct queue *st);
static void postorder_traversal(struct tree_node *node, struct queue *st);


struct tree_node *bt_init(int v)
{
	struct tree_node *root;
	root = (struct tree_node *) malloc(sizeof(*root));
	root->right = NULL;
	root->left = NULL;
	root->value = v;
	return root;
}

struct tree_node *insert(struct tree_node *node, int v)
{
    if (v > node->value) {
        if (node->right == NULL) {
            node->right = bt_init(v);
            return node;
        }
        else
            insert(node->right, v);
    } else {
        if (node->left == NULL) {
	    node->left = bt_init(v);
            return node;
        }
        else
            insert(node->left, v);
    }
}

// v:success. 0:failure
void bt_insert(struct tree_node *root, int v)
{
    insert(root, v);
}

// 0:failure, not found. 1:success, found
int search(struct tree_node *node, int v)
{
	if (node->value == v)
		return 1;
	else if (v > node->value) {
		if (node->right == NULL) {
			//fprintf(stderr, "Error: bt value not found\n");
			return 0;
		}
		return search(node->right, v);
	} else if (v < node->value) {
		if (node->left == NULL) {
			//fprintf(stderr, "Error: bt value not found\n");
			return 0;
		}
		return search(node->left, v);
	}
}

// 0:failure, not found. 1:success, found
int bt_search(struct tree_node *root, int v)
{
	return search(root, v);
}

struct tree_node *delete(struct tree_node *node, int key)
{
	if (node == NULL)
		return NULL;
	else if (key < node->value) {
		node->left = delete(node->left, key);
		return node;
	}
	else if (key > node->value) {
		node->right = delete(node->right, key);
		return node;
	}
	else if (node->value == key) {
		// If left or both children don't exist
		if (node->left == NULL) {
			free(node);
			return node->right;
		}
		else if (node->right == NULL) {
			free(node);
			return node->left;
		}
		else { 
			// Both right and left children are not NULL
			node->right = lift(node->right, node);
			return node;
		}
	}
}

static struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del)
{
	if (node->left != NULL) {
		node->left = lift(node->left, node_to_del);
		return node;
	}
	else {
		node_to_del->value = node->value;
		free(node_to_del);
		return node->right;
	}
}

void bt_delete_node(struct tree_node *root, int key)
{
    delete(root, key);
}

void bt_delete_tree(struct tree_node *node)
{
	if (node == NULL)
		return;
	bt_delete_tree(node->left);
	bt_delete_tree(node->right);
	free(node);
}

static void preoder_traversal(struct tree_node *node, struct queue *st)
{
	if (node != NULL) {
		q_enqueue(st, node->value);
		preoder_traversal(node->left, st);
		preoder_traversal(node->right, st);
	}
}

static void inorder_traversal(struct tree_node *node, struct queue *st)
{
    if (node != NULL) {
        inorder_traversal(node->left, st);
	q_enqueue(st, node->value);
        inorder_traversal(node->right, st);
    }
}

static void postorder_traversal(struct tree_node *node, struct queue *st)
{
	if (node != NULL) {
		postorder_traversal(node->left, st);
		postorder_traversal(node->right, st);
		q_enqueue(st, node->value);
	}
}

// parameters: 1-Pre 2-In 3-Post 
void bt_traverse(struct tree_node *root, int trav_type, int *trav_a, int a_size)
{
	int i = 0, tmp = 0;
	// Use a queue because if I use stack I'll need to reverse the data
	struct queue *q;
	q = q_init();

	if (trav_type == 1)
		preoder_traversal(root, q);
	else if (trav_type == 2)
		inorder_traversal(root, q);
	else if (trav_type == 3)
		postorder_traversal(root, q);
	else
		return;

	while (i < a_size) {
		tmp = q_dequeue(q);
		if (tmp == -1)
			break;
		else
			trav_a[i++] = tmp;
	}
	q_free(q);
}

int bt_min(struct tree_node *root)
{
	if (root->left != NULL)
		return bt_min(root->left);
	else 
		return root->value;
}

int bt_max(struct tree_node *root)
{
	if (root->right != NULL)
		return bt_max(root->right);
	else
		return root->value;	
}
