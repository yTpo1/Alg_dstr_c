#include "../lib_unittest/myunittest.h"
#include "../Dstr/linked_list.h"
#include "../Dstr/node.h"
#include "../Dstr/stack_array.h"
#include "../Dstr/stack_ll.h"
#include "../Dstr/queue.h"
#include "../Dstr/circ_link_list.h"
#include "../Dstr/binary_tree.h"
#include "../Dstr/hash_table.h"
#include "../Algorithms/hash_function.h"

// TODO: move to algorithms
void test_hashing()
{
//unsigned hash_simple(char *value, int len, int prime, int htsize);
//unsigned hash_horner(char *value, int len, int prime, int htsize);
	//unsigned hash(char *value, int len, int prime, int htsize);
	test_intequal(hash_simple("moon", 4, 31, 11), 10, "hashing");
	test_intequal(hash_simple("tree", 4, 31, 11), 10, "hashing");
}

void test_hash_table()
{
	struct hash_table *ht;
	ht = ht_init();
	ht_insert(ht, "moon", 4, "sun", 3);
	assert_str_equal(ht_search(ht, "moon", 4), "sun", "ht1");
	assert_str_equal(ht_search(ht, "hello", 5), NULL, "ht2");
	ht_insert(ht, "tree", 4, "bush", 4);
	assert_str_equal(ht_search(ht, "tree", 4), "bush", "ht3");
	assert_str_equal(ht_search(ht, "hello", 5), NULL, "ht4");

	ht_insert(ht, "qwer", 4, "aaaa", 4);
	ht_insert(ht, "asdf", 4, "bbbb", 4);
	ht_insert(ht, "zxcv", 4, "cccc", 4);
	ht_insert(ht, "fdas", 4, "dddd", 4);
	ht_insert(ht, "fghj", 4, "eeee", 4);
	assert_str_equal(ht_search(ht, "fdas", 4), "dddd", "ht5");
	ht_delete(ht);
}

void test_linked_list()
{
	int answ[4];
	int expected[4] = {28,9,14,31};
	struct node *head;
	head = ll_init();

	ll_insert_front(head, 3);
	ll_insert_front(head, 9);
	ll_insert_end(head, 14);

	test_intequal(ll_search(head, 9), 1, "Linked list");
	test_intequal(ll_delete(head, 3), 3, "linked list");

	ll_insert_front(head, 28);
	ll_insert_end(head, 31);

	ll_to_a(head, answ, 4);
	test_intarray_eq(expected, answ, 4, "linked list");

	ll_free(head);
}

void test_stack_array()
{
	struct sa_stack *stack;
	stack = sa_init();

	test_intequal(sa_isempty(stack), 1, "stack isempty");
	test_intequal(sa_size(stack), 0, "stask size");
	test_intequal(sa_top(stack), -1, "stask top");

	test_intequal(sa_push(stack, 6), 0, "Stack push");
	test_intequal(sa_pop(stack), 6, "Stack pop");

	test_intequal(sa_push(stack, 2), 0, "Stack push");
	test_intequal(sa_push(stack, 51), 1, "Stack push");
	test_intequal(sa_push(stack, 7), 2, "Stack push");
	test_intequal(sa_pop(stack), 7, "Stack pop");

	test_intequal(sa_isempty(stack), 0, "stack isempty");
	test_intequal(sa_size(stack), 2,"stack size");
	test_intequal(sa_top(stack), 51, "stack top");
	
	test_intequal(sa_push(stack, 18), 2, "Stack push");
	test_intequal(sa_pop(stack), 18, "Stack pop");
	test_intequal(sa_pop(stack), 51, "Stack pop");
	test_intequal(sa_pop(stack), 2, "Stack pop");

	test_intequal(sa_isempty(stack), 1, "stack isempty");
	test_intequal(sa_size(stack), 0, "stack size");
	test_intequal(sa_top(stack), -1, "stask top");

	sa_free(stack);
}

void test_stack_ll()
{
	struct node *head;
	head = sll_init();

	sll_push(head, 6);
	test_intequal(sll_pop(head), 6, "Stack pop");

	sll_push(head, 2);
	sll_push(head, 51);
	sll_push(head, 7);
	test_intequal(sll_pop(head), 7, "Stack pop");
	
	sll_push(head, 18);
	test_intequal(sll_pop(head), 18, "Stack pop");
	test_intequal(sll_pop(head), 51, "Stack pop");
	test_intequal(sll_pop(head), 2, "Stack pop");
	sll_free(head);
}

void test_circular_linked_list()
{
	struct node *head;
	int answ2[5];
	int list_correct[5] = {6,7,8,9,3};

	head = init_cl(); 
	insert_cl(head, 3); 
	insert_cl(head, 9); 
	insert_cl(head, 8); 
	insert_cl(head, 7); 
	insert_cl(head, 6);
	clist_to_array(head, answ2, 5);
	test_intarray_eq(list_correct, answ2, 5, "Circular Linked List");

	cll_free(head);
}

void test_queue()
{
	struct queue *q;
	q = q_init();
	test_intequal(q_size(q), 0, "q size");
	test_intequal(q_isempty(q), 1, "q isempty");
	q_enqueue(q, 6);
	test_intequal(q_size(q), 1, "q size");
	test_intequal(q_first(q), 6, "q first");
	test_intequal(q_isempty(q), 0, "q isempty");

	q_enqueue(q, 3);
	test_intequal(q_first(q), 3, "q first");
	test_intequal(q_dequeue(q), 6, "q dequeue");
	test_intequal(q_size(q), 1, "q size");
	q_enqueue(q, 77);
	q_enqueue(q, 81);
	
	for(int i = 0; i < QUEUESIZE * 2; i++){
		q_enqueue(q, i);
		q_dequeue(q);
	}
	test_intequal(q_isempty(q), 0, "q isempty");
	test_intequal(q_size(q), 3, "q size");
	test_intequal(q_first(q), ((QUEUESIZE * 2) - 1), "q first");
	test_intequal(q_dequeue(q), ((QUEUESIZE * 2) - 3), "q dequeue");

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
	test_intequal(bt_search(root, 10), 1, "bt insert-search");

	bt_insert(root, 8);
	test_intequal(bt_search(root, 8), 1, "bt insert-search");
	test_intequal(bt_search(root, 73), 0, "bt insert-search");
	bt_insert(root, 17);
	bt_insert(root, 4);
	bt_insert(root, 13);
	test_intequal(bt_search(root, 4), 1, "bt insert-search");
	test_intequal(bt_search(root, 13), 1, "bt insert-search");
	test_intequal(bt_search(root, 73), 0, "bt insert-search");

	bt_traverse(root, 1, bt_trav, a_size);
	test_intarray_eq(bt_preotrav, bt_trav, 5, "Binary Tree - preorder");

	bt_traverse(root, 2, bt_trav, a_size);
	test_intarray_eq(bt_inotrav, bt_trav, 5, "Binary Tree - inorder");

	bt_traverse(root, 3, bt_trav, a_size);
	test_intarray_eq(bt_postotrav, bt_trav, 5, "Binary Tree - postorder");

	bt_insert(root, 6);
	bt_insert(root, 3);
	bt_traverse(root, 2, bt_trav, a_size);

	test_intarray_eq(bt_befdel, bt_trav, 7, "Binary Tree - 2 new elem");
	bt_delete_node(root, 6);

	bt_traverse(root, 2, bt_trav, a_size);
	test_intarray_eq(bt_del, bt_trav, 6, "Binary Tree - after delete");

	bt_delete_tree(root);
}

void run_data_structure_tests()
{
	//test_linked_list();
	//test_circular_linked_list();
	//test_stack_array();
	//test_stack_ll();
	//test_queue();
	//test_btree();
	test_hash_table();
	test_hashing();
}
