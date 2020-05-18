#ifndef RED_BLACK_TREES_H
#define RED_BLACK_TREES_H

typedef struct rbt_node rbt_node;

struct rbt_node {
	rbt_node *parent;
	rbt_node *left;
	rbt_node *right;
	int v;
	int color;
};


typedef struct {
	rbt_node *root;
	rbt_node *nullnode;
} rb_tree;

rb_tree *rbt_init(void);
void rbt_insert(rb_tree *t, int v);
int rb_size(rb_tree *t, rbt_node *root);
void rb_inorder_traversal(rb_tree *t, int *a);

#endif
