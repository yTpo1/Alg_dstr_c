#include "lib_unittest/myunittest.h"
#include "lib_algorithms/str_questions.h"
#include "lib_algorithms/array_questions.h"
#include "lib_algorithms/numbers.h"
#include "lib_datastr/linked_list.h"
#include "lib_datastr/circ_link_list.h"
#include "lib_datastr/binary_tree.h"

#define SIZEMAX 1000

void run_number_tests();
void run_array_tests();
void run_str_tests();
void run_data_structure_tests();
void reset_dummy_array(int *a);

int main(int argc, char* argv[]){
    run_array_tests();
    run_str_tests();
    run_data_structure_tests();

    print_test_status();
    return 0;
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
    test_int_array_equal(unsorted_a, sorted_answer, actual_size);
    // Unittest straight selection
    reset_dummy_array(unsorted_a);
    straignt_selection(unsorted_a, actual_size);
    test_int_array_equal(unsorted_a, sorted_answer, actual_size);
    // Unittest Quick Sort
    reset_dummy_array(unsorted_a);
    quick_sort(unsorted_a, 0, 9);
    test_int_array_equal(unsorted_a, sorted_answer, actual_size);
    // Unittest Merge Sort 
    reset_dummy_array(unsorted_a);
    merge_sort(unsorted_a, 0, 9);
    test_int_array_equal(unsorted_a, sorted_answer, actual_size);


    // Unittest bubble_sort
    reset_dummy_array(unsorted_a);
    bubble_sort(unsorted_a, actual_size);
    test_int_array_equal(unsorted_a, sorted_answer, actual_size);

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

void run_number_tests(){
    int a[SIZEMAX] = {2,1,4,76,2,7,26,8,9};
    int answ[2];
    int answ_correct[2] = {76,1};
    find_max_min(a, 9, answ);
    test_int_array_equal(answ_correct, answ, 2);
}

void run_data_structure_tests(){
    int answ[5];
    int list_correct[5] = {6,7,8,9,3};
    // Test linked list
    init_ll(3); insert_front(9); insert_front(8); insert_front(7); insert_front(6);
    list_to_array(answ, 5);
    test_int_array_equal(list_correct, answ, 5);

    int answ2[5];
    // Test circular linked list
    init_cl(); insert_cl(3); insert_cl(9); insert_cl(8); insert_cl(7); insert_cl(6);
    clist_to_array(answ2, 5);
    test_int_array_equal(list_correct, answ2, 5);
    /*traverse_list();*/

    int btree_answ[5] = {4,8,10,13,17};
    int *btree_trav;
    init_btree(10);
    insert_btree(8);
    insert_btree(17);
    insert_btree(4);
    insert_btree(13);
    btree_trav = traverse_btree();
    //traverse_btree_to_a(btree_trav);
    test_int_array_equal(btree_answ, btree_trav, 5);

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
