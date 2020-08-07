#include "../lib_unittest/myunittest.h"
#include "../Algorithms/str_questions.h"

#define SIZEMAX 100

void test_first_nonrep_char()
{
	char s1[6] = "gergex";
	char s2[10] = "nuifnqiufa"; // n is looked at again before q
	char s3[5] = "abaab"; // last a is looked at at the end

	assert_char_eq('r', first_nonrep_char(s1,6), "first_nonrep_char");
	assert_char_eq('q', first_nonrep_char(s2,10), "first_nonrep_char");
	assert_char_eq('0', first_nonrep_char(s3,5), "first_nonrep_char");
}

void test_check_palindrome()
{
    char polinome1[5] = "heeh";
    char polinome2[6] = "heyeh";
    char not_polinome1[7] = "heyeeh";
    assert_int_eq(1, check_palindrome(polinome1), "check_polinome");
    assert_int_eq(1, check_palindrome(polinome2), "check_polinome");
    assert_int_eq(0, check_palindrome(not_polinome1), "check_polinome");
}

void test_reverse_array()
{
    char arr[10] = "heey boss";
    char reverse[10] = "ssob yeeh";
    reverse_array(arr);
    assert_str_eq(reverse, arr, "reverse_array");
}

//void test_duplicate_characters()
//{
//    char dup_init[9] = "heey boss";
//    char dup[9];
//    char dup_correct[9] = "es";
//    find_duplicate_characters(dup_init, dup);
//    assert_str_eq(dup_correct, dup, "find_duplicate");
//}

void test_anagram()
{
    char anagram1[9] = "hey boss";
    char anagram2[9] = "yo sosyh";
    char anagram3[9] = "yo seshb";
    assert_int_eq(0, check_string_anagram(anagram1, anagram2, 9), "check_string_anagram1");
    assert_int_eq(1, check_string_anagram(anagram1, anagram3, 9), "check_string_anagram2");
}

void test_remove_char()
{
    char rmvchar1[8] = "hey boss";
    char rmvchar1_answer[8] = "hy boss";
    char rmvchar2[8] = "hey boss";
    char rmvchar2_answer[8] = "hey bo";
    rmv_char_from_str(rmvchar1, 'e', 8);
    rmv_char_from_str(rmvchar2, 's', 8);
    assert_str_eq(rmvchar1_answer, rmvchar1, "rmv_char_from_str");
    assert_str_eq(rmvchar2_answer, rmvchar2, "rmv_char_from_str");

}

void run_string_tests()
{
	test_check_palindrome();
	test_reverse_array();
	//test_duplicate_characters();
	test_anagram();
	test_remove_char();
	test_first_nonrep_char();
}
