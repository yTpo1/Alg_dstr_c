#include <stdlib.h>
#include <stdio.h>
struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *root;

void init_btree(int x){
    root = (struct tree_node *) malloc(sizeof *root);
    root->value = x;
}

struct tree_node *insert(int x, struct tree_node *node){
    if(node->value < x){
        if(node->right == NULL){
            node->right = (struct tree_node *) malloc (sizeof *root);
            node->right->value = x;
            return node;
        }
        else
            insert(x, node->right);
    }
    else{
        if(node->left == NULL){
            node->left = (struct tree_node *) malloc (sizeof *root);
            node->left->value = x;
            return node;
        }
        else
            insert(x, node->left);
    }
}

void insert_btree(int x){
    insert(x, root);
}

void traverse(struct tree_node *node){
    if(node != NULL){
        traverse(node->left);
        printf("%d,",node->value);
        traverse(node->right);
    }
}

void traverse_btree(){
    traverse(root);
}
