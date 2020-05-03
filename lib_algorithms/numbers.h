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
int char_to_int(char c);
int solve_equation_posfix(struct node *head, char *s);
