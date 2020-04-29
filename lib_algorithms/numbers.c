// source: Sedgewick R. - Algorithms in C
int gcd(int u, int v)
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
