#include <stdlib.h>
#include <stdio.h>
struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *root;
struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del);
void traverse_to_a(struct tree_node *node, int *a, int index);
int traversal[5];
int tr_index;

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

void insert_btree(int key){
    insert(key, root);
}

struct tree_node *delete(int key, struct tree_node *node){
    if(node == NULL)
        return NULL;
    else if(node->value = key){
        if(node->left == NULL && node->right == NULL){
            // remove reference to current node from parents nodes
            free(node);
            node = NULL;
        }
        else if(node->left != NULL){
            node->value = node->left->value;
            free(node);
            node->left = NULL;
        }
        else if(node->right != NULL){
            node->value = node->right->value;
            free(node);
            node->right = NULL;
        }
        else // both right and left children are not NULL
        {
            node = lift(node, node);
        }
    }
    else if(node->value > key)
        return delete(key, node->left);
    else
        return delete(key, node->right);
}

struct tree_node *lift(struct tree_node *node, struct tree_node *node_to_del){
    if(node->left != NULL){
        node = lift(node, node_to_del);
    }else{
        if(node->right != NULL){
            node_to_del->value = node->right->value;
            node->right = NULL;
        }
        return node;
    }
}

void delete_btree(int key){
    delete(key, root);
}

void traverse(struct tree_node *node){
    if(node != NULL){
        traverse(node->left);
        /*printf("%d,",node->value);*/
        traversal[tr_index++] = node->value;
        traverse(node->right);
    }
}

int *traverse_btree(){
    tr_index = 0;
    traverse(root);
    int *ptrav = traversal;
    return ptrav;
}

/*void traverse_to_a(struct tree_node *node, int *a, int index){*/
    /*if(node != NULL){*/
        /*traverse_to_a(node->left, a, index);*/
        /*//a[index++] = node->value;*/
        /*//*a++ = node->value;*/
        /*traverse_to_a(node->right, a, index);*/
    /*}*/
/*}*/

/*void traverse_btree_to_a(int *a){*/
    /*traverse_to_a(root, a, 0);*/
/*}*/
