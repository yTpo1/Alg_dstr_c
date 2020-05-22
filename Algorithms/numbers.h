#ifndef NUMBERS_H
#define NUMBERS_H

#include "../Dstr/stack_ll.h"

struct fraction {
	int numerator;
	int denominator;
};

int gcd(int u, int v);
void find_max_min(int a[], int size, int answ[]);
struct fraction* fr_low_terms(struct fraction *x);
void b_to_d(int nd, char *binary);
void prime_numers(int n, int a[]);
int isprime_trial_division(int n);
int char_to_int(char c);
int solve_equation_posfix(struct ll_node *head, char *s);
int fibonacci(int lim);
int fibonacci_r(int lim);
int fibonacci_i(int lim);
int horner(int poly[], int len, int x);
int **matrix_mult(int **a, int **b);

#endif
