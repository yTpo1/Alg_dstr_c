struct fraction {
	int numerator;
	int denominator;
};

int gcd(int u, int v);
void find_max_min(int a[], int size, int answ[]);
struct fraction* fr_low_terms(struct fraction *x);
