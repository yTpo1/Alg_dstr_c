#include <stdlib.h>
#include "../lib_unittest/myunittest.h"
#include "../Algorithms/array_questions.h"
#define SIZEMAX 10

void test_max_sub_array()
{
	struct tuple *t = NULL;
	int a[8] = {6, 8, -4, 10, 11, -10, 5, 2};

	t = max_sub_array_dnq(a, 0, 7);
	assert_int_eq(31, t->s, "max-sub-arr sum");
	assert_int_eq(0, t->li, "max-sub-arr start index");
	assert_int_eq(4, t->ri, "max-sub-arr end index");
	free(t);
}
/* wtf this is wrong
void test_max_sub_array()
{
	int cost[17] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	int cost2[5] = {10, 11, 7, 10, 6};

	int i = 0, j = 0;
	max_sub_array(cost, 17, &i, &j);
	assert_int_eq(i, 7, "max_sub_array");
	assert_int_eq(j, 11, "max_sub_array");
	assert_int_eq(cost[j] - cost[i], 43, "max_sub_array");

	//i = 0; j = 0;
	//max_sub_array(cost, 5, &i, &j);
	//assert_int_eq(i, 2, "max_sub_array");
	//assert_int_eq(j, 4, "max_sub_array");
	//assert_int_eq(cost[j] - cost[i], , "max_sub_array");
}
*/

void test_binary_search()
{
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};
    assert_int_eq(1, binary_search(sort_answ, 2, 0, 9), "binary_seach");
    assert_int_eq(1, binary_search(sort_answ, 10, 0, 10), "binary_seach");
    assert_int_eq(0, binary_search(sort_answ, 15, 0, 10), "binary_seach");
}

void test_bubble_sort()
{
    int unsort_a[SIZEMAX];
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};
    bubble_sort(unsort_a, SIZEMAX);
    assert_int_array_eq(unsort_a, sort_answ, SIZEMAX, "Bubble sort");
}

void test_straignt_selection_sort()
{
    int unsort_a[SIZEMAX];
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};
    
    straignt_selection_sort(unsort_a, SIZEMAX);
    assert_int_array_eq(unsort_a, sort_answ, SIZEMAX, "Straight Selection");
}

void test_insertion_sort()
{
    int unsort_a[SIZEMAX];
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};

    insertion_sort(unsort_a, SIZEMAX);
    assert_int_array_eq(unsort_a, sort_answ, SIZEMAX, "Insertion Sort");
}

void test_merge_sort()
{
    int unsort_a[SIZEMAX];
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};

    merge_sort(unsort_a, 0, 9);
    assert_int_array_eq(unsort_a, sort_answ, SIZEMAX, "Merge Sort");
}

void test_quick_sort()
{
    int unsort_a[SIZEMAX];
    int sort_answ[SIZEMAX] = {1,2,3,4,5,6,7,8,9,10};

    quick_sort(unsort_a, 0, 9);
    assert_int_array_eq(unsort_a, sort_answ, SIZEMAX, "Quick Sort");
}

void test_insertion_sort_char()
{
    char s1[SIZEMAX] = "hey boss";
    char s2[SIZEMAX] = " behossy";
    insertion_sort_char(s1, 9);
    assert_str_eq(s2, s1, "insertion_sort_char");

    // Unittest Heap sort
    //reset_dummy_array(unsorted_a);
    //heap_sort(unsorted_a, actual_size);
    //test_int_array_equal(unsorted_a, sorted_answer, actual_size);
    
    // Unittest Find Median
    // !Infinite loop
    //reset_dummy_array(unsorted_a);
    //int m = get_median(unsorted_a, actual_size);
    //assert_int_eq(5, m, "Find Median"); 

    // Unittest min heapify
    /*reset_dummy_array(unsorted_a);*/
    /*min_heapify(unsorted_a, actual_size);*/
    /*int min_heapity = {1,*/
}

void run_array_tests()
{
	test_binary_search();
	test_bubble_sort();
	test_straignt_selection_sort();
	test_insertion_sort();
	test_merge_sort();
	test_quick_sort();
	test_insertion_sort_char();
	test_max_sub_array();
}
