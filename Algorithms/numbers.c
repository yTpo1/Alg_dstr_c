#include <stdio.h>
#include <string.h>
#include "numbers.h"

// Time: O(2^n). Space: O(n)
int fibonacci_r(int lim)
{
	if (lim <= 1)
		return 1;
	return fibonacci(lim - 1) + fibonacci(lim - 2);
}

// Time: O(n). Space: O(1)
int fibonacci_i(int lim)
{
}

// Euclidean algorithm by subtraction
// Time: O(n)
static int gcd_classic(int u, int v)
{
	int t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

static int gcd_modulo(int u, int v)
{
	int t;
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u % v;
	}
	return v;
}

int gcd(int u, int v)
{
	//return gcd_classic(int u, int v)
	return gcd_modulo(u, v);
}

// Reduce a given fraction to its lowest terms
struct fraction* fr_low_terms(struct fraction *x)
{
	int g = gcd(x->numerator, x->denominator);
	x->numerator = x->numerator / g;
	x->denominator = x->denominator / g;
	return x;
}

// Conver Binary to Decimal
void b_to_d(int nd, char *binary)
{
	char tmp[8];
	int i = 0;
	while(nd > 0){
		tmp[i++] = (char)(nd % 2) + 48;
		nd = nd / 2;
	}
	i--;
	int j = 0;
	while(i >= 0){
		binary[j] = tmp[i];
		j++;
		i--;
	}
}

// Find max and min numbers in array
void find_max_min(int a[], int size, int answ[])
{
	//int min = -65535, max = 65535;
	int min=a[0], max=a[0];
	for(int i=0; i<size; i++){
		if(a[i]>max)
			max = a[i];
		if(a[i]<min)
			min = a[i];
	}
	answ[0]=max;
	answ[1]=min;
}

void seive_of_eratosthenes(int n, int a[])
{
	int t[n], i, j;
	memset(t, 1, n*sizeof(int));	
	t[0] = 0;
	for(i = 2; i < n/2; i++){
		for(j=2; j < n/i; j++)
			t[i*j] = 0;
	}
	j = 0;
	for(i=2; i < n; i++){
		if(t[i])
			a[j++] = i;
	}
}

void prime_numers(int n, int a[])
{
	seive_of_eratosthenes(n, a);
}

int char_to_int(char c)
{
	return (int) c - 48;
}

int solve_equation_posfix(struct node *head, char *s)
{
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] == '+')
			sll_push(head, sll_pop(head) + sll_pop(head));
		if(s[i] == '*')
			sll_push(head, sll_pop(head) * sll_pop(head));
		while(s[i] >= '0' && s[i] <= '9'){
			sll_push(head, char_to_int(s[i]));
			i++;
		}
	}
	return sll_pop(head);
}
