#include "test_numbers.h"

void test_horner()
{
	// 2x^3-6x^2+2x-1
	int poly1[4] = {2,-6, 2, -1};
	int poly2[4] = {-1,2,-6,2};
	test_intequal(horner(poly1, 4, 3), 5, "horner");
	test_intequal(horner(poly2, 4, 3), 5, "horner");
}

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
	assert_str_equal(s,"1010", "Binary to decimal");

	memset(s,'\0',8*sizeof(char));
	b_to_d(31, s);
	assert_str_equal(s,"11111", "Binary to decimal");
}

void test_prime_numbers()
{
	int a[200];
	memset(a, 0, 200*sizeof(int));
	prime_numers(1000, a);
	test_intequal(a[10], 31, "Prime Numbers");
}

void test_fibonacci()
{
	test_intequal(fibonacci_r(1), 1, "fib");
	test_intequal(fibonacci_r(2), 1, "fib");
	test_intequal(fibonacci_r(3), 2, "fib");
	test_intequal(fibonacci_r(4), 3, "fib");
	test_intequal(fibonacci_r(5), 5, "fib");
	test_intequal(fibonacci_r(6), 8, "fib");
	test_intequal(fibonacci_r(7), 13, "fib");
}

void run_number_tests()
{
	test_gcd();
	test_find_max_min();
	test_fibonacci();
	test_fraction_to_lowest_terms();
	test_b_to_d();
	test_prime_numbers();
	test_char_to_int();
	test_posfix_equation();
	test_horner();
}
