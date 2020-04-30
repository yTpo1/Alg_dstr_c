#include "numbers.h"
#include <stdio.h>
static int gcd_classic(int u, int v)
{
	int t;
	while(u > 0){
		if(u < v){
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
	while(u>0){
		if(u < v){
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

// Find max and min numbers in array
void find_max_min(int a[], int size, int answ[]){
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
