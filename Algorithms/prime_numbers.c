#include <string.h>

#include "prime_numbers.h"

void sieve_of_eratosthenes(int n, int a[])
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

void prime_numbers(int n, int a[])
{
	sieve_of_eratosthenes(n, a);
}

// 1 is prime, 0 not prime
int isprime_trial_division(int n)
{
	int i = 5;	
	if (n <= 3 )
		return n > 1;
	else if ((n % 2 == 0) || (n % 3 == 0))
		return 0;

	while (i * i <= n) {
		//if (n % i != 0)
		//	return 0;
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
		i+=6;
	}
	return 1;
}

int find_closest_prime(int n)
{
	while (isprime_trial_division(n) == 0)
		n++;
	return n;
}
