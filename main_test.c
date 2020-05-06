#include <stdio.h>
#include <string.h>
#include "lib_unittest/myunittest.h"
#include "lib_algorithms/str_questions.h"
#include "lib_algorithms/array_questions.h"
#include "lib_algorithms/numbers.h"
#include "Dstr/linked_list.h"
#include "Dstr/node.h"
#include "Dstr/stack_array.h"
#include "Dstr/stack_ll.h"
#include "Dstr/queue.h"
#include "Dstr/circ_link_list.h"
#include "Dstr/binary_tree.h"

#define SIZEMAX 1000

void reset_dummy_array(int *a);

void test_posfix_equation()
{
	struct node *head;
	char s[9] = "2 3 5 + *";
	head = sll_init();
	test_intequal(solve_equation_posfix(head, s), 16, "posfix equation using stack");
	sll_free(head);
}

void test_char_to_int()
{
	test_intequal(char_to_int('3'), 3, "char to int");
	test_intequal(char_to_int('9'), 9, "char to int");
}

void test_gcd()
{
	test_intequal(gcd(270, 192), 6, "gcd");
	test_intequal(gcd(461952, 116298), 18, "gcd");
}

void test_find_max_min()
{
    int a[9] = {2,1,4,76,2,7,26,8,9};
    int answ_correct[2] = {76, 1};
    //answ_correct[0] = 76;
    //answ_correct[1] = 1;
    int answ[2];
    find_max_min(a, 9, answ);
    test_intarray_eq(answ_correct, answ, 2, "Number Find Min-Max");
}

void test_fraction_to_lowest_terms()
{
	struct fraction fr;
	fr.numerator = 178468;
	fr.denominator = 267702;
	fr_low_terms(&fr);
	test_intequal(fr.numerator, 2, "Fraction to lowest terms");
	test_intequal(fr.denominator, 3, "Fraction to lowest terms");
}

void test_b_to_d()
{
	char s[8];
	memset(s,'\0',8*sizeof(char));
	b_to_d(10, s);
	test_strequal(s,"1010", "Binary to decimal");

	memset(s,'\0',8*sizeof(char));
	b_to_d(31, s);
	test_strequal(s,"11111", "Binary to decimal");
}

void test_prime_numbers()
{
	int a[200];
	memset(a, 0, 200*sizeof(int));
	prime_numers(1000, a);
	test_intequal(a[10], 31, "Prime Numbers");
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
	//for (int i = 0; i < 7; i++)
	//	printf(" %d ", bt_trav[i]);
	test_intarray_eq(bt_befdel, bt_trav, 7, "Binary Tree - 2 new elem");
	bt_delete_node(root, 6);

	bt_traverse(root, 2, bt_trav, a_size);
	test_intarray_eq(bt_del, bt_trav, 6, "Binary Tree - after delete");

	//btree_trav = traverse_btree();
	////traverse_btree_to_a(btree_trav);
	//bt_free(root);
	
	bt_delete_tree(root);
}

void run_str_tests(){
    char polinome1[SIZEMAX] = "heeh";
    char polinome2[SIZEMAX] = "heyeh";
    char not_polinome1[SIZEMAX] = "heyeeh";
    test_intequal(1, check_palindrome(polinome1), "check_polinome");
    test_intequal(1, check_palindrome(polinome2), "check_polinome");
    test_intequal(0, check_palindrome(not_polinome1), "check_polinome");
    
    char arr[SIZEMAX] = "heey boss";
    char reverse[SIZEMAX] = "ssob yeeh";
    reverse_array(arr);
    test_strequal(reverse, arr, "reverse_array");
    
    char dup_init[SIZEMAX] = "heey boss";
    char dup[SIZEMAX];
    char dup_correct[SIZEMAX] = "es";
    find_duplicate_characters(dup_init, dup);
    test_strequal(dup_correct, dup, "find_duplicate");

    char anagram1[SIZEMAX] = "hey boss";
    char anagram2[SIZEMAX] = "yo sosyh";
    char anagram3[SIZEMAX] = "yo seshb";
    test_intequal(0, check_string_anagram(anagram1, anagram2, 9), "check_string_anagram1");
    test_intequal(1, check_string_anagram(anagram1, anagram3, 9), "check_string_anagram2");

    char rmvchar1[SIZEMAX] = "hey boss";
    char rmvchar1_answer[SIZEMAX] = "hy boss";
    char rmvchar2[SIZEMAX] = "hey boss";
    char rmvchar2_answer[SIZEMAX] = "hey bo";
    rmv_char_from_str(rmvchar1, 'e', 8);
    rmv_char_from_str(rmvchar2, 's', 8);
    test_strequal(rmvchar1_answer, rmvchar1, "rmv_char_from_str");
    test_strequal(rmvchar2_answer, rmvchar2, "rmv_char_from_str");
}

void reset_dummy_array(int *a){
    int tmp[10] = {4,3,8,7,2,9,1,5,6,10};
    for(int i=0; i<10; i++)
        a[i] = tmp[i];
}

void run_array_tests(){
    int actual_size = 10;
    int unsorted_a[SIZEMAX];
    int sorted_answer[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};

    char s1[SIZEMAX] = "hey boss";
    char s2[SIZEMAX] = " behossy";
    insertion_sort_char(s1, 9);
    test_strequal(s2, s1, "insertion_sort_char");

    test_intequal(1, binary_search(sorted_answer, 2, 0, 9), "binary_seach");
    test_intequal(1, binary_search(sorted_answer, 10, 0, 10), "binary_seach");
    test_intequal(0, binary_search(sorted_answer, 15, 0, 10), "binary_seach");
   
    // Unittest Insertion Sort
    reset_dummy_array(unsorted_a);
    insertion_sort(unsorted_a, actual_size);
    test_intarray_eq(unsorted_a, sorted_answer, actual_size, "Insertion Sort");
    /*t_iarray_eq(unsorted_a, sorted_answer, "Insertion Sort");*/

    // Unittest straight selection
    reset_dummy_array(unsorted_a);
    straignt_selection(unsorted_a, actual_size);
    test_intarray_eq(unsorted_a, sorted_answer, actual_size, "Straight Selection");

    // Unittest Quick Sort
    reset_dummy_array(unsorted_a);
    quick_sort(unsorted_a, 0, 9);
    test_intarray_eq(unsorted_a, sorted_answer, actual_size, "Quick Sort");

    // Unittest Merge Sort 
    reset_dummy_array(unsorted_a);
    merge_sort(unsorted_a, 0, 9);
    test_intarray_eq(unsorted_a, sorted_answer, actual_size, "Merge Sort");

    // Unittest bubble_sort
    reset_dummy_array(unsorted_a);
    bubble_sort(unsorted_a, actual_size);
    test_intarray_eq(unsorted_a, sorted_answer, actual_size, "Bubble sort");

    // Unittest Heap sort
    //reset_dummy_array(unsorted_a);
    //heap_sort(unsorted_a, actual_size);
    //test_int_array_equal(unsorted_a, sorted_answer, actual_size);
    
    // Unittest Find Median
    // !Infinite loop
    //reset_dummy_array(unsorted_a);
    //int m = get_median(unsorted_a, actual_size);
    //test_intequal(5, m, "Find Median"); 

    // Unittest min heapify
    /*reset_dummy_array(unsorted_a);*/
    /*min_heapify(unsorted_a, actual_size);*/
    /*int min_heapity = {1,*/
}

void run_data_structure_tests()
{
	test_linked_list();
	test_circular_linked_list();
	test_stack_array();
	test_stack_ll();
	test_queue();
	test_btree();
}
void run_number_tests()
{
	test_gcd();
	test_find_max_min();
	test_fraction_to_lowest_terms();
	test_b_to_d();
	test_prime_numbers();
	test_char_to_int();
	test_posfix_equation();
}
int main(int argc, char* argv[]){
    run_array_tests();
    run_str_tests();
    run_data_structure_tests();
    run_number_tests();

    print_test_status();
    return 0;
}
