#include <stdio.h>
#include <string.h>
#include "lib_unittest/myunittest.h"
#include "Algorithms/str_questions.h"
#include "Algorithms/array_questions.h"

#include "Test/test_numbers.h"
#include "Test/test_dstr.h"
#include "Test/test_cryptography.h"
#include "Test/test_array_alg.h"

#define SIZEMAX 100

void reset_dummy_array(int *a);

void run_str_tests(){
    char polinome1[SIZEMAX] = "heeh";
    char polinome2[SIZEMAX] = "heyeh";
    char not_polinome1[SIZEMAX] = "heyeeh";
    assert_int_eq(1, check_palindrome(polinome1), "check_polinome");
    assert_int_eq(1, check_palindrome(polinome2), "check_polinome");
    assert_int_eq(0, check_palindrome(not_polinome1), "check_polinome");
    
    char arr[SIZEMAX] = "heey boss";
    char reverse[SIZEMAX] = "ssob yeeh";
    reverse_array(arr);
    assert_str_eq(reverse, arr, "reverse_array");
    
    char dup_init[SIZEMAX] = "heey boss";
    char dup[SIZEMAX];
    char dup_correct[SIZEMAX] = "es";
    find_duplicate_characters(dup_init, dup);
    assert_str_eq(dup_correct, dup, "find_duplicate");

    char anagram1[SIZEMAX] = "hey boss";
    char anagram2[SIZEMAX] = "yo sosyh";
    char anagram3[SIZEMAX] = "yo seshb";
    assert_int_eq(0, check_string_anagram(anagram1, anagram2, 9), "check_string_anagram1");
    assert_int_eq(1, check_string_anagram(anagram1, anagram3, 9), "check_string_anagram2");

    char rmvchar1[SIZEMAX] = "hey boss";
    char rmvchar1_answer[SIZEMAX] = "hy boss";
    char rmvchar2[SIZEMAX] = "hey boss";
    char rmvchar2_answer[SIZEMAX] = "hey bo";
    rmv_char_from_str(rmvchar1, 'e', 8);
    rmv_char_from_str(rmvchar2, 's', 8);
    assert_str_eq(rmvchar1_answer, rmvchar1, "rmv_char_from_str");
    assert_str_eq(rmvchar2_answer, rmvchar2, "rmv_char_from_str");
}

void reset_dummy_array(int *a){
    int tmp[10] = {4,3,8,7,2,9,1,5,6,10};
    for(int i=0; i<10; i++)
        a[i] = tmp[i];
}

int main(int argc, char *argv[])
{
	int all = 0;

	if (argc == 2 && strcmp(argv[argc - 1], "-h") == 0) {
		printf("Options: array dstr str num crypto\n");
		return 0;
	}

	if(argc == 1)
		all = 1;
	while (argc > 1 || all) {
		if (strcmp(argv[argc - 1], "array") == 0 || all)
			run_array_tests();
		if (strcmp(argv[argc - 1], "dstr") == 0 || all)
			run_data_structure_tests();
		if (strcmp(argv[argc - 1], "crypto") == 0 || all)
			run_test_cryptography();
		if (strcmp(argv[argc - 1], "num") == 0 || all)
			run_number_tests();
		if (strcmp(argv[argc - 1], "str") == 0 || all)
			run_str_tests();
		if (all)
			all--;
		argc--;
	}		
	print_test_status();
	return 0;
}
