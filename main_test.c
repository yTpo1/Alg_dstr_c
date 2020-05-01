#include <stdio.h>
#include <string.h>
#include "lib_unittest/myunittest.h"
#include "lib_algorithms/str_questions.h"
#include "lib_algorithms/array_questions.h"
#include "lib_algorithms/numbers.h"
#include "Dstr/linked_list.h"
#include "Dstr/node.h"
#include "Dstr/linked_list_w_trailer.h"
#include "Dstr/stack_array.h"
#include "Dstr/stack_ll.h"
#include "Dstr/circ_link_list.h"
#include "Dstr/binary_tree.h"

#define SIZEMAX 1000

void reset_dummy_array(int *a);

void test_gcd()
{
	//int a1 = 0;
	//a1 = gcd(270, 192);
	//test_intequal(a1, 6, "gcd");
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

void run_number_tests()
{
	test_gcd();
	test_find_max_min();
	test_fraction_to_lowest_terms();
	test_b_to_d();
	test_prime_numbers();
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
}

void test_linked_list_w_trailer()
{
	int answ[5];
	int list_correct[5] = {6,7,8,9,3};
	int l_after_del[5] = {6,7,9,3,0};

	llwt_init(); 
	llwt_insert_front(3); 
	llwt_insert_front(9); 

	test_intequal(llwt_getfirstv(), 9, "Linked List gethead");

	llwt_insert_front(8); 
	llwt_insert_front(7); 
	
	// test search
	test_intequal(llwt_search(9), 2, "Linked list search index");
	test_intequal(llwt_search(7), 0, "Linked list search index");
	test_intequal(llwt_search(50), -1, "Linked list search index");

	llwt_insert_front(6);
	llwt_to_a(answ, 5);
	test_intarray_eq(list_correct, answ, 5, "Linked List");

	// Test deletion of a node
	memset(answ, 0, 5*sizeof(int));
	test_intequal(llwt_delete(8), 8, "Linked list. Delete node success");
	llwt_to_a(answ, 5);
	test_intarray_eq(l_after_del, answ, 5, "Linked list");

	test_intequal(llwt_delete(21), -1, "Linked list. Delete node fail");

	// Test inserion at the end
	llwt_insert_end(44);
	l_after_del[4] = 44;
	llwt_to_a(answ, 5);
	test_intarray_eq(l_after_del, answ, 5, "Linked list");
}

void test_stack_array()
{
	test_intequal(sa_push(6), 0, "Stack push");
	test_intequal(sa_pop(), 6, "Stack pop");

	test_intequal(sa_push(2), 0, "Stack push");
	test_intequal(sa_push(51), 1, "Stack push");
	test_intequal(sa_push(7), 2, "Stack push");
	test_intequal(sa_pop(), 7, "Stack pop");
	
	test_intequal(sa_push(18), 2, "Stack push");
	test_intequal(sa_pop(), 18, "Stack pop");
	test_intequal(sa_pop(), 51, "Stack pop");
	test_intequal(sa_pop(), 2, "Stack pop");
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
}

void run_data_structure_tests()
{
	test_linked_list();
	test_linked_list_w_trailer();

	int answ2[5];
	int list_correct[5] = {6,7,8,9,3};

	// Test circular linked list
	init_cl(); insert_cl(3); insert_cl(9); insert_cl(8); insert_cl(7); insert_cl(6);
	clist_to_array(answ2, 5);
	test_intarray_eq(list_correct, answ2, 5, "Circular Linked List");

	test_stack_array();
	test_stack_ll();

	/*
	int btree_answ[5] = {4,8,10,13,17};
	int *btree_trav;
	init_btree(10);
	insert_btree(8);
	insert_btree(17);
	insert_btree(4);
	insert_btree(13);
	btree_trav = traverse_btree();
	//traverse_btree_to_a(btree_trav);
	test_intarray_eq(btree_answ, btree_trav, 5, "Binary Tree");
	*/
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

int main(int argc, char* argv[]){
    run_array_tests();
    run_str_tests();
    run_data_structure_tests();
    run_number_tests();

    print_test_status();
    return 0;
}
