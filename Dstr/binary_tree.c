#include "binary_tree.h"
#include "stack_ll.h"
#include "queue.h"

static struct tree_node *insert(struct tree_node *node, int v);
static int search(struct tree_node *node, int v);
static struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del);
static struct tree_node *delete(int key, struct tree_node *node);
//static void traverse_to_a(struct tree_node *node, int *a, int index);

// to rename to bt_node_init
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
            //node->right = (struct tree_node *) malloc(sizeof(*node));
            //node->right->value = v;
            node->right = bt_init(v);
            return node;
        }
        else
            insert(node->right, v);
    } else {
        if (node->left == NULL) {
            //node->left = (struct tree_node *) malloc(sizeof(*node));
            //node->left->value = v;
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

struct tree_node *delete(int key, struct tree_node *node)
{
	if (node == NULL)
		return NULL;
	else if (key < node->value) {
		node->left = delete(key, node->left);
		return node;
	}
	else if (key > node->value) {
		node->right = delete(key, node->right);
		return node;
	}
	else if (node->value == key) {
		//if (node->left == NULL && node->right == NULL)
		//	free(node);
		if (node->left != NULL) {
			//struct tree_node *nl;
			//nl = node->left;
			//node->value = nl->value;
			//// check if the left node has children of its own
			//if (nl->right != NULL)
			//	node->right = nl->right;
			//if (nl->left != NULL)
			//	node->left = nl->left;
			//free(nl);
			//node->left = NULL;
			return node->right;
		} else if (node->right != NULL) {
			//struct tree_node *nr;
			//node->value = nr->value;
			//// check if the right node has children of its own
			//if (nr->left != NULL)
			//	node->left = nr->left;
			//if (nr->right != NULL)
			//	node->right = nr->right;
			//free(nr);
			return node->left;
		} else { // both right and left children are not NULL
			node->right = lift(node->right, node);
			return node;
		}
	}
}

struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del)
{
	if (node->left != NULL) {
		node->left = lift(node->left, node_to_del);
		return node;
	}
	else {
	//if (node->right != NULL) {
	//node_to_del->value = node->right->value;
	//node->right = NULL;
	//}
		node_to_del->value = node->value;
		return node->right;
	}
}

void bt_delete_node(struct tree_node *root, int key)
{
    delete(key, root);
}

void bt_delete_tree(struct tree_node *node)
{
	if (node == NULL)
		return;
	bt_delete_tree(node->left);
	bt_delete_tree(node->right);
	free(node);
}

void preoder_traversal(struct tree_node *node, struct queue *st)
{
	if (node != NULL) {
		q_enqueue(st, node->value);
		preoder_traversal(node->left, st);
		preoder_traversal(node->right, st);
	}
}

void inorder_traversal(struct tree_node *node, struct queue *st)
{
    if (node != NULL) {
        inorder_traversal(node->left, st);
	q_enqueue(st, node->value);
        inorder_traversal(node->right, st);
    }
}

void postorder_traversal(struct tree_node *node, struct queue *st)
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
