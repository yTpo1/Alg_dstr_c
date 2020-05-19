#ifndef RED_BLACK_TREES_H
#define RED_BLACK_TREES_H

typedef struct rb_node rb_node;

struct rb_node {
	rb_node *parent;
	rb_node *left;
	rb_node *right;
	int v;
	int color;
};


typedef struct {
	rb_node *root;
	rb_node *nullnode;
} rb_tree;

rb_tree *rb_init(void);
void rb_insert(rb_tree *t, int v);
int rb_size(rb_tree *t, rb_node *root);
void rb_inorder_traversal(rb_tree *t, int *a);
void rb_free(rb_tree *t, rb_node *r);

#endif
