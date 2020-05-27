#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numbers.h"

// O(n^3)
int **matrix_mult(int **a, int **b)
{
	int **c = (int **) malloc(2 * sizeof(int *));
	for (int i = 0; i <= 1; i++)
		c[i] = (int *) malloc(2 *sizeof(int)); 

	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			for (int k = 0; k <= 1; k++)
				c[i][j] += a[i][k] * b[k][j];
	return c;
}

// Time: O(2^n). Space: O(n)
int fibonacci_r(int n)
{
	if (n <= 1)
		return n;
	return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

// Time: O(n). Space: O(1)
int fibonacci_i(int n)
{
	return 0;
}

// polynomial
// Time: O(n)
int horner(int poly[], int len, int x)
{
	int res = poly[0];
	for (int i = 1; i < len; i++) {
		printf("%dres = %dres * %dx + %dpoly[i];\n", res, res, x, poly[i]);
		res = res * x + poly[i];
	}
	printf("%d\n", res);
	return res;
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

int char_to_int(char c)
{
	return (int) c - 48;
}

int solve_equation_posfix(struct ll_node *head, char *s)
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
