#include "../lib_unittest/myunittest.h"
#include "../Dstr/linked_list.h"
#include "../Dstr/ll_node.h"
#include "../Dstr/stack_array.h"
#include "../Dstr/stack_ll.h"
#include "../Dstr/queue.h"
#include "../Dstr/circ_link_list.h"
#include "../Dstr/binary_tree.h"
#include "../Dstr/hash_table.h"
#include "../Dstr/hash_table_oaddr.h"
#include "../Algorithms/hash_function.h"
#include "../Dstr/graph.h"
#include "../Dstr/heap.h"
#include "../Dstr/priority_queue.h"
#include "../Dstr/red_black_trees.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>

void test_rbt()
{
	int exp_inorder[11] = {1,2,4,5,7,8,11,14,15};
	int act_inorder[11];
	rb_tree *t = rb_init();
	rb_insert(t,11); 
	rb_insert(t,2); 
	rb_insert(t,14); 
	rb_insert(t,1); 
	rb_insert(t,15); 
	rb_insert(t,7);
	rb_insert(t,5);
	rb_insert(t,8);
	rb_insert(t,4);
	assert_int_eq(rb_size(t, t->root), 9, "rb size");
	rb_inorder_traversal(t, act_inorder);
	assert_int_array_eq(act_inorder, exp_inorder, 10, "red-black tree inorder trav");

	exp_inorder[2] = 3;
	exp_inorder[3] = 4;
	exp_inorder[4] = 5;
	exp_inorder[5] = 7;
	exp_inorder[6] = 8;
	exp_inorder[7] = 11;
	exp_inorder[8] = 14;
	exp_inorder[9] = 15;

	act_inorder[10] = 0;
	rb_insert(t,3);
	assert_int_eq(rb_size(t, t->root), 10, "rb size");
	rb_inorder_traversal(t, act_inorder);
	assert_int_array_eq(act_inorder, exp_inorder, 11, "red-black tree inorder trav");

	rb_free(t, t->root);
}

void test_priority_queue()
{
	int corr[10] = {16,14,10,8,7,3,9,1,4,2};
	struct heap *h = NULL;
	h = pq_init(10);
	pq_insert(h, 4);
	pq_insert(h, 1);
	pq_insert(h, 3);
	pq_insert(h, 2);
	pq_insert(h, 16);
	pq_insert(h, 9);
	pq_insert(h, 10);;
	pq_insert(h, 14);
	pq_insert(h, 8);
	pq_insert(h, 7);
	assert_int_eq(h->size, 10, "max-heap size");
	assert_int_eq(pd_peek_min(h), 1, "priority_queue peek");
	assert_int_eq(pd_extract_min(h), 1, "priority_queue peek");
	pq_free(h);
}

void test_max_heap_build()
{
	struct heap *h = NULL;
	int corr[10] = {16,14,10,8,7,9,3,2,4,1};
	h = heap_init(10);
	h->size = 10;
	h->a[0] = 4;
	h->a[1] = 1;
	h->a[2] = 3;
	h->a[3] = 2;
	h->a[4] = 16;
	h->a[5] = 9;
	h->a[6] = 10;
	h->a[7] = 14;
	h->a[8] = 8;
	h->a[9] = 7;
	heap_max_build(h);

	assert_int_array_eq(h->a, corr, 10, "max-heap build");

	heap_free(h);
}

void test_max_heap()
{
	struct heap *h = NULL;
	int corr[10] = {16,14,10,8,7,3,9,1,4,2};
	h = heap_init(10);

	heap_max_insert(h, 4);
	heap_max_insert(h, 1);
	heap_max_insert(h, 3);
	heap_max_insert(h, 2);
	heap_max_insert(h, 16);
	heap_max_insert(h, 9);
	heap_max_insert(h, 10);
	heap_max_insert(h, 14);
	heap_max_insert(h, 8);
	heap_max_insert(h, 7);
	assert_int_eq(h->size, 10, "max-heap size");

	assert_int_array_eq(h->a, corr, 10, "max-heap build");

	heap_free(h);
}

/* max_heapify is static
void test_max_heap()
{
	struct heap *h = NULL;
	int corr[10] = {16,14,10,8,7,9,3,2,4,1};
	h = heap_init(10);
	h->size = 10; h->a[0] = 16; h->a[1] = 4; h->a[2] = 10;
	h->a[3] = 14; h->a[4] = 7; h->a[5] = 9; h->a[6] = 3;
	h->a[7] = 2; h->a[8] = 8; h->a[9] = 1;
	max_heapify(h, 1);
	assert_int_array_eq(h->a, corr, 10, "maxheap");
	heap_free(h);
}
*/

void test_heap()
{
	struct heap *h = NULL;
	int corr[11] = {1,3,12,9,7};
	int corr2[11] = {1,7,12,9,7};
	int cormax[11] = {12, 9, 1, 3, 7};
	h = heap_init(11);
	heap_min_insert(h, 3);
	heap_min_insert(h, 9);
	heap_min_insert(h, 12);
	heap_min_insert(h, 7);
	heap_min_insert(h, 1);
	assert_int_eq(h->size, 5, "heap");
	assert_int_array_eq(h->a, corr, 11, "heap");

	heap_min_delete_item(h, 3);
	assert_int_eq(h->size, 4, "heap");
	assert_int_array_eq(h->a, corr2, 11, "heap");

	heap_min_insert(h, 3);
	assert_int_eq(h->size, 5, "heap");
	assert_int_array_eq(h->a, corr, 11, "heap");

	heap_max_build(h);
	assert_int_eq(h->size, 5, "heap");
	assert_int_array_eq(h->a, cormax, 11, "max-heap");

	heap_free(h);
}

void test_graph_notcyclic()
{
	int gr_size = 5;
	struct graph *gr = gr_init(gr_size);
	for (int i = 0; i < gr_size; i++)
		gr_insert_vertex(gr, 'A'+i);

	gr_connect_vertices(gr, 0,1);
	gr_connect_vertices(gr, 1,2);
	gr_connect_vertices(gr, 1,4);
	gr_connect_vertices(gr, 2,3);

	char trav[6] = "";
	char correct[6] = "ABCED\0";

	gr_dfs(gr, 'A', trav);
	assert_str_eq(trav, correct, "graph");

	gr_delete(gr);
}

void test_graph()
{
	struct graph *gr = gr_init(4);
	for (int i = 0; i < 4; i++)
		gr_insert_vertex(gr, 'A'+i);

	gr_connect_vertices(gr, 0,1);
	gr_connect_vertices(gr, 0,3);
	gr_connect_vertices(gr, 1,2);
	gr_connect_vertices(gr, 2,3);

	char trav[5] = "";
	char correct[5] = "ABDC\0";
	//correct[0] = 'A'; correct[0] = 'B'; correct[0] = 'D'; correct[0] = 'C';
	gr_dfs(gr, 'A', trav);
	assert_str_eq(trav, correct, "graph");

	gr_dfs(gr, 'C', trav);
	correct[0] = 'C'; correct[3] = 'A';
	assert_str_eq(trav, correct, "graph");

	correct[0] = 'D'; correct[1] = 'A'; correct[2] = 'C'; correct[3] = 'B';
	gr_dfs(gr, 'D', trav);
	assert_str_eq(trav, correct, "graph");

	gr_delete(gr);
}

void test_hashing()
{
//unsigned hash_simple(char *value, int len, int prime, int htsize);
//unsigned hash_horner(char *value, int len, int prime, int htsize);
	//unsigned hash(char *value, int len, int prime, int htsize);
	assert_int_eq(hash_simple("moon", 4, 31, 11), 10, "hashing");
	assert_int_eq(hash_simple("tree", 4, 31, 11), 10, "hashing");
}

void test_hash_table()
{
	struct hash_table *ht;
	ht = ht_init();
	ht_insert(ht, "moon", 4, "sun", 3);
	assert_str_eq(ht_search(ht, "moon", 4), "sun", "ht1");
	assert_str_eq(ht_search(ht, "hello", 5), NULL, "ht2");
	ht_insert(ht, "tree", 4, "bush", 4);
	assert_str_eq(ht_search(ht, "tree", 4), "bush", "ht3");
	assert_str_eq(ht_search(ht, "hello", 5), NULL, "ht4");

	ht_insert(ht, "qwer", 4, "aaaa", 4);
	ht_insert(ht, "asdf", 4, "bbbb", 4);
	ht_insert(ht, "zxcv", 4, "cccc", 4);
	ht_insert(ht, "fdas", 4, "dddd", 4);
	ht_insert(ht, "fghj", 4, "eeee", 4);
	assert_str_eq(ht_search(ht, "fdas", 4), "dddd", "ht5");
	ht_delete(ht);
}

void test_hash_table_open_addressing()
{
	struct htoa *ht;
	ht = htoa_init(11);
	htoa_insert(ht, "moon", 4, "sun", 3); //size=11 i=0
	assert_str_eq(htoa_search(ht, "moon", 4), "sun", "ht1");
	assert_str_eq(htoa_search(ht, "hello", 5), NULL, "ht2");
	htoa_insert(ht, "tree", 4, "bush", 4);
	assert_str_eq(htoa_search(ht, "tree", 4), "bush", "ht3"); //s=11 i=3
	assert_str_eq(htoa_search(ht, "hello", 5), NULL, "ht4");

	htoa_insert(ht, "qwer", 4, "aaaa", 4); //i=1 i=10
	htoa_insert(ht, "asdf", 4, "bbbb", 4); //size=11 i=1, i=5
	htoa_insert(ht, "zxcv", 4, "cccc", 4); //i=6 i=9
	htoa_insert(ht, "fdas", 4, "dddd", 4); //i=7
	htoa_insert(ht, "fghj", 4, "eeee", 4); //i=4
	//htoa_traverse_tmp(ht);
	assert_str_eq(htoa_search(ht, "fdas", 4), "dddd", "ht5");
	assert_int_eq(htoa_delete_item(ht, "zxcv", 4), 1, "ht6");
	//ht_delete(ht);
	
	//char word[4];
	//char value[4];
	//srand(time(NULL));
	//for (int i = 0; i < 150; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		word[j] = (rand() % 26) + 97;
	//		value[j] = (rand() % 26) + 97;
	//	}
	//	htoa_insert(ht, word, 4, value, 4);
	//}

	// 6
	htoa_delete(ht);
}

void test_hashtable_openaddr_resizing()
{
	struct htoa *ht;
	ht = htoa_init(11);
	char word[4];
	char value[4];
	srand(time(NULL));
	for (int i = 0; i < 150; i++) {
		for (int j = 0; j < 4; j++) {
			word[j] = (rand() % 26) + 97;
			value[j] = (rand() % 26) + 97;
		}
		htoa_insert(ht, word, 4, value, 4);
		//if (ht->count == 9) {
		if (i == 8) 
			assert_int_eq(ht->size, 23, "htoa resize");
		if (i == 17) 
			assert_int_eq(ht->size, 47, "htoa resize");
		if (i == 33) 
			assert_int_eq(ht->size, 97, "htoa resize");
		if (i == 68) 
			assert_int_eq(ht->size, 197, "htoa resize");
	}

	htoa_delete(ht);
}

void test_linked_list()
{
	int answ[4];
	int expected[4] = {28,9,14,31};
	struct ll_node *head;
	head = ll_init();

	ll_insert_front(head, 3);
	ll_insert_front(head, 9);
	ll_insert_end(head, 14);

	assert_int_eq(ll_search(head, 9), 1, "Linked list");
	assert_int_eq(ll_delete(head, 3), 3, "linked list");

	ll_insert_front(head, 28);
	ll_insert_end(head, 31);

	ll_to_a(head, answ, 4);
	assert_int_array_eq(expected, answ, 4, "linked list");

	ll_free(head);
}

void test_stack_array()
{
	struct sa_stack *stack;
	stack = sa_init();

	assert_int_eq(sa_isempty(stack), 1, "stack isempty");
	assert_int_eq(sa_size(stack), 0, "stask size");
	assert_int_eq(sa_top(stack), -1, "stask top");

	assert_int_eq(sa_push(stack, 6), 0, "Stack push");
	assert_int_eq(sa_pop(stack), 6, "Stack pop");

	assert_int_eq(sa_push(stack, 2), 0, "Stack push");
	assert_int_eq(sa_push(stack, 51), 1, "Stack push");
	assert_int_eq(sa_push(stack, 7), 2, "Stack push");
	assert_int_eq(sa_pop(stack), 7, "Stack pop");

	assert_int_eq(sa_isempty(stack), 0, "stack isempty");
	assert_int_eq(sa_size(stack), 2,"stack size");
	assert_int_eq(sa_top(stack), 51, "stack top");
	
	assert_int_eq(sa_push(stack, 18), 2, "Stack push");
	assert_int_eq(sa_pop(stack), 18, "Stack pop");
	assert_int_eq(sa_pop(stack), 51, "Stack pop");
	assert_int_eq(sa_pop(stack), 2, "Stack pop");

	assert_int_eq(sa_isempty(stack), 1, "stack isempty");
	assert_int_eq(sa_size(stack), 0, "stack size");
	assert_int_eq(sa_top(stack), -1, "stask top");

	sa_free(stack);
}

void test_stack_ll()
{
	struct ll_node *head;
	head = sll_init();

	sll_push(head, 6);
	assert_int_eq(sll_pop(head), 6, "Stack pop");

	sll_push(head, 2);
	sll_push(head, 51);
	sll_push(head, 7);
	assert_int_eq(sll_pop(head), 7, "Stack pop");
	
	sll_push(head, 18);
	assert_int_eq(sll_pop(head), 18, "Stack pop");
	assert_int_eq(sll_pop(head), 51, "Stack pop");
	assert_int_eq(sll_pop(head), 2, "Stack pop");
	sll_free(head);
}

void test_circular_linked_list()
{
	struct ll_node *head;
	int answ2[5];
	int list_correct[5] = {6,7,8,9,3};

	head = init_cl(); 
	insert_cl(head, 3); 
	insert_cl(head, 9); 
	insert_cl(head, 8); 
	insert_cl(head, 7); 
	insert_cl(head, 6);
	clist_to_array(head, answ2, 5);
	assert_int_array_eq(list_correct, answ2, 5, "Circular Linked List");

	cll_free(head);
}

void test_queue_2()
{
	// test where head stays 0 but tail grows
	int q_len = 3;
	struct queue *q = q_init(q_len);
	q_enqueue(q, 1);
	q_enqueue(q, 2);
	q_enqueue(q, 3);
	q_enqueue(q, 4);
	assert_int_eq(q_size(q), 3, "q size");
	q_enqueue(q, 5);
	assert_int_eq(q_size(q), 3, "q size");
	
	q_free(q);
}

void test_queue_3()
{
	// test if indexes are going in a circle
	int q_len = 3;
	struct queue *q = q_init(q_len);
	q_enqueue(q, 1);
	q_enqueue(q, 2);
	q_enqueue(q, 3);
	assert_int_eq(q_first(q), 3, "q first");
	assert_int_eq(q_dequeue(q), 1, "q dequeue");
	q_enqueue(q, 4);
	assert_int_eq(q_first(q), 4, "q first");
	assert_int_eq(q_dequeue(q), 2, "q dequeue");
	q_enqueue(q, 5);
	assert_int_eq(q_first(q), 5, "q first");
	assert_int_eq(q_dequeue(q), 3, "q dequeue");
	q_enqueue(q, 6);
	assert_int_eq(q_first(q), 6, "q first");
	assert_int_eq(q_dequeue(q), 4, "q dequeue");
	q_enqueue(q, 7);
	assert_int_eq(q_first(q), 7, "q first");
	assert_int_eq(q_dequeue(q), 5, "q dequeue");
	q_free(q);
}

void test_queue()
{
	int q_len = 10;
	struct queue *q = q_init(q_len);
	assert_int_eq(q_size(q), 0, "q size");
	assert_int_eq(q_isempty(q), 1, "q isempty");

	q_enqueue(q, 6);
	assert_int_eq(q_size(q), 1, "q size");
	assert_int_eq(q_first(q), 6, "q first");
	assert_int_eq(q_isempty(q), 0, "q isempty");

	q_enqueue(q, 3);
	assert_int_eq(q_size(q), 2, "q size");
	assert_int_eq(q_first(q), 3, "q first");

	assert_int_eq(q_dequeue(q), 6, "q dequeue");
	assert_int_eq(q_size(q), 1, "q size");

	q_enqueue(q, 77);
	q_enqueue(q, 81);
	assert_int_eq(q_size(q), 3, "q size");
	
	q_enqueue(q, 77);
	q_enqueue(q, 81);
	q_enqueue(q, 77);
	q_enqueue(q, 81);
	q_enqueue(q, 77);
	q_enqueue(q, 81);
	q_enqueue(q, 77);
	assert_int_eq(q_size(q), 10, "q size");

	q_free(q);
}

void test_btree()
{
	int bt_preotrav[5] = {10,8,4,17,13};
	int bt_inotrav[5] = {4,8,10,13,17};
	int bt_postotrav[5] = {4,8,13,17,10};
	int bt_befdel[7] = {3,4,6,8,10,13,17};
	int bt_del[6] = {3,4,8,10,13,17};
	int a_size = 10;
	int bt_trav[10];

	struct tree_node *root;

	root = bt_init(10);
	assert_int_eq(bt_search(root, 10), 1, "bt insert-search");

	bt_insert(root, 8);
	assert_int_eq(bt_search(root, 8), 1, "bt insert-search");
	assert_int_eq(bt_search(root, 73), 0, "bt insert-search");
	bt_insert(root, 17);
	bt_insert(root, 4);
	bt_insert(root, 13);
	assert_int_eq(bt_search(root, 4), 1, "bt insert-search");
	assert_int_eq(bt_search(root, 13), 1, "bt insert-search");
	assert_int_eq(bt_search(root, 73), 0, "bt insert-search");

	assert_int_eq(bt_size(root), 5, "binary tree size");

	bt_traverse(root, 1, bt_trav, a_size);
	assert_int_array_eq(bt_preotrav, bt_trav, 5, "Binary Tree - preorder");

	bt_traverse(root, 2, bt_trav, a_size);
	assert_int_array_eq(bt_inotrav, bt_trav, 5, "Binary Tree - inorder");

	bt_traverse(root, 3, bt_trav, a_size);
	assert_int_array_eq(bt_postotrav, bt_trav, 5, "Binary Tree - postorder");

	bt_insert(root, 6);
	bt_insert(root, 3);
	bt_traverse(root, 2, bt_trav, a_size);

	assert_int_array_eq(bt_befdel, bt_trav, 7, "Binary Tree - 2 new elem");
	bt_delete_node(root, 6);

	bt_traverse(root, 2, bt_trav, a_size);
	assert_int_array_eq(bt_del, bt_trav, 6, "Binary Tree - after delete");

	assert_int_eq(bt_min(root), 3, "bt-min");
	assert_int_eq(bt_max(root), 17, "bt-min");

	bt_delete_tree(root);
}

void run_data_structure_tests()
{
	//test_linked_list();
	//test_circular_linked_list();
	//test_stack_array();
	//test_stack_ll();
	//test_queue();
	//test_queue_2();
	//test_queue_3();
	//test_btree();
	//test_hashing();
	test_hash_table();
	test_hash_table_open_addressing();
	test_hashtable_openaddr_resizing();
	//test_graph();
	//test_graph_notcyclic();
	//test_heap();
	//test_max_heap();
	//test_max_heap_build();
	//test_priority_queue();
	//test_rbt();
}
