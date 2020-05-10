#include <stdio.h>
#include <string.h>
#include "lib_unittest/myunittest.h"
#include "Algorithms/str_questions.h"
#include "Algorithms/array_questions.h"

#include "Test/test_numbers.h"
#include "Test/test_dstr.h"
#include "Test/test_cryptography.h"

#define SIZEMAX 1000

void reset_dummy_array(int *a);

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
    assert_str_equal(reverse, arr, "reverse_array");
    
    char dup_init[SIZEMAX] = "heey boss";
    char dup[SIZEMAX];
    char dup_correct[SIZEMAX] = "es";
    find_duplicate_characters(dup_init, dup);
    assert_str_equal(dup_correct, dup, "find_duplicate");

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
    assert_str_equal(rmvchar1_answer, rmvchar1, "rmv_char_from_str");
    assert_str_equal(rmvchar2_answer, rmvchar2, "rmv_char_from_str");
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
    assert_str_equal(s2, s1, "insertion_sort_char");

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



int main(int argc, char *argv[])
{
	//run_array_tests();
	//run_str_tests();
	run_data_structure_tests();
	//run_number_tests();
	//run_test_cryptography();

	print_test_status();
	return 0;
}
