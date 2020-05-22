#include <stdlib.h>
#include "test_numbers.h"
#include "../Dstr/stack_ll.h"

void test_matrix_mult(void)
{
	int **a = (int **) malloc(2 * sizeof(int *));
	int **b = (int **) malloc(2 * sizeof(int *));
	for (int i = 0; i <= 1; i++) {
		a[i] = (int *) malloc(2 *sizeof(int)); 
		b[i] = (int *) malloc(2 *sizeof(int)); 
	}
	int **c;
	int exp_answ[2][2] = {{4, 4}, {10,8}};
	a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
	b[0][0] = 2; b[0][1] = 0; b[1][0] = 1; b[1][1] = 2;
	c = matrix_mult(a, b);

	assert_int_eq(c[0][0], exp_answ[0][0], "matrix mult");
	assert_int_eq(c[0][1], exp_answ[0][1], "matrix mult");
	assert_int_eq(c[1][0], exp_answ[1][0], "matrix mult");
	assert_int_eq(c[1][1], exp_answ[1][1], "matrix mult");

	for (int i = 0; i <= 1; i++) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);
}

void test_horner(void)
{
	// 2x^3-6x^2+2x-1
	int poly1[4] = {2,-6, 2, -1};
	int poly2[4] = {-1,2,-6,2};
	assert_int_eq(horner(poly1, 4, 3), 5, "horner");
	assert_int_eq(horner(poly2, 4, 3), 5, "horner");
}

void test_posfix_equation(void)
{
	struct ll_node *head;
	char s[9] = "2 3 5 + *";
	head = sll_init();
	assert_int_eq(solve_equation_posfix(head, s), 16, "posfix equation using stack");
	sll_free(head);
}

void test_char_to_int(void)
{
	assert_int_eq(char_to_int('3'), 3, "char to int");
	assert_int_eq(char_to_int('9'), 9, "char to int");
}

void test_gcd()
{
	assert_int_eq(gcd(270, 192), 6, "gcd");
	assert_int_eq(gcd(461952, 116298), 18, "gcd");
}

void test_find_max_min()
{
    int a[9] = {2,1,4,76,2,7,26,8,9};
    int answ_correct[2] = {76, 1};
    //answ_correct[0] = 76;
    //answ_correct[1] = 1;
    int answ[2];
    find_max_min(a, 9, answ);
    assert_int_array_eq(answ_correct, answ, 2, "Number Find Min-Max");
}

void test_fraction_to_lowest_terms()
{
	struct fraction fr;
	fr.numerator = 178468;
	fr.denominator = 267702;
	fr_low_terms(&fr);
	assert_int_eq(fr.numerator, 2, "Fraction to lowest terms");
	assert_int_eq(fr.denominator, 3, "Fraction to lowest terms");
}

void test_b_to_d()
{
	char s[8];
	memset(s,'\0',8*sizeof(char));
	b_to_d(10, s);
	assert_str_eq(s,"1010", "Binary to decimal");

	memset(s,'\0',8*sizeof(char));
	b_to_d(31, s);
	assert_str_eq(s,"11111", "Binary to decimal");
}

void test_prime_numbers()
{
	int a[200];
	memset(a, 0, 200*sizeof(int));
	prime_numers(1000, a);
	assert_int_eq(a[10], 31, "Prime Numbers");
}

void test_isprime()
{
	assert_int_eq(isprime_trial_division(17), 1, "prime1");
	assert_int_eq(isprime_trial_division(5639), 1, "prime2");
	assert_int_eq(isprime_trial_division(7591), 1, "prime3");
	assert_int_eq(isprime_trial_division(9677), 1, "prime4");
	assert_int_eq(isprime_trial_division(22), 0, "prime5");
	assert_int_eq(isprime_trial_division(59875), 0, "prime6");
	assert_int_eq(isprime_trial_division(123212), 0, "prime7");
	assert_int_eq(isprime_trial_division(100100), 0, "prime8");
}

void test_fibonacci()
{
	assert_int_eq(fibonacci_r(1), 1, "fib");
	assert_int_eq(fibonacci_r(2), 1, "fib");
	assert_int_eq(fibonacci_r(3), 2, "fib");
	assert_int_eq(fibonacci_r(4), 3, "fib");
	assert_int_eq(fibonacci_r(5), 5, "fib");
	assert_int_eq(fibonacci_r(6), 8, "fib");
	assert_int_eq(fibonacci_r(7), 13, "fib");
}

void run_number_tests()
{
	test_gcd();
	test_find_max_min();
	test_fibonacci();
	test_fraction_to_lowest_terms();
	test_b_to_d();
	test_isprime();
	test_prime_numbers();
	test_char_to_int();
	test_posfix_equation();
	//test_horner();
	test_matrix_mult();
}
