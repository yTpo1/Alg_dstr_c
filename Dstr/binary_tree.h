#ifndef BINARY_TREE_H
#define BINARY_TREE_H
struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *bt_init(int v);
void bt_insert(struct tree_node *root, int key);
int bt_search(struct tree_node *root, int v);
void bt_traverse(struct tree_node *root, int trav_type, int *trav_a, int a_size);
void bt_delete_tree(struct tree_node *node);
void bt_delete_node(struct tree_node *root, int key);
int bt_min(struct tree_node *root);
int bt_max(struct tree_node *root);
int bt_size(struct tree_node *root);
#endif
