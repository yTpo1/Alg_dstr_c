#include <stdio.h>
#include <stdlib.h>
#include "helper_func.h"
#include "array_questions.h"

static struct tuple *max_crossing_subarray(int *a, int l, int m, int h);
static int partition(int a[], int l, int r);
static void merge(int a[], int l, int m, int r);
// shit elements for heap sort
//static void sift(int *a, int l, int r);

/* Max sub array */
// bruteforce - O(n^2)
// this is wrong
void max_sub_array(int cost[], int asize, int *ai, int *aj)
{
	int sum = 0;
	for (int i = 0; i < asize; i++)
		for (int j = i + 1; j < asize; j++) {
			if (cost[j] - cost[i] > sum) {
				sum = cost[j] - cost[i];
				*ai = i;
				*aj = j;
			}
		}
}

static struct tuple *max_crossing_subarray(int *a, int l, int m, int h)
{
	struct tuple *t = (struct tuple *) malloc(sizeof(struct tuple));
	t->li = 0, t->ri = 0, t->s = 0;
	int s = 0, ls = -60000, rs = -60000, li = -1, ri = -1;
	for (int i = m; i >= 0; i--) {
		s = s + a[i];
		if (s > ls) {
			ls = s;
			li = i;
		}
	}
	s = 0;
	for (int j = m + 1; j <= h; j++) {
		s = s + a[j];
		if (s > rs) {
			rs = s;
			ri = j;
		}
	}
	//printf("li %d ri %d ls+rs %d", li, ri, ls+rs);
	t->li = li;
	t->ri = ri;
	t->s = ls + rs;
	return t;
}

/* Max sub array */
// devide and conquer
struct tuple *max_sub_array_dnq(int a[], int l, int h)
{
	if (l == h) {
		struct tuple *t = (struct tuple *) malloc(sizeof(struct tuple));
		t->li = l;
		t->ri = h;
		t->s = a[l];
		return t;
	}
	else {
		int m = (l+h)/2;
		struct tuple *lt, *rt, *ct;
		lt = max_sub_array_dnq(a, l, m);
		rt = max_sub_array_dnq(a, m+1, h);
		ct = max_crossing_subarray(a, l, m, h);
		if (lt->s >= rt->s && lt->s >= ct->s) {
			free(rt);
			free(ct);
			return lt;
		}
		else if (rt->s >= lt->s && rt->s >= ct->s) {
			free(lt);
			free(ct);
			return rt;
		}
		else {
			free(lt);
			free(rt);
			return ct;
		
		}
	}
}

/* Sorting algorithm */
void quick_sort(int a[], int l, int r)
{
    int p=0;
    if(l<r){
        p = partition(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

static int partition(int a[], int l, int r){
    int pivot = a[r];
    int j = l-1;
    for(int i = l; i<r; i++)
        if(pivot > a[i])
            swap_var_int_array(a, i, ++j);
    swap_var_int_array(a, j+1, r);
    return j+1;
}

/* Sorting algorithm */
void merge_sort(int a[], int l, int r)
{
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

static void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int sizel = m-l+1;
    int sizer = r - m;
    int tmpl[sizel], tmpr[sizer];
    
    for(i=0; i<sizel; i++)
        tmpl[i] = a[l+i];
    
    for(i=0; i<sizer; i++)
        tmpr[i] = a[m+i+1];

    k=l, i=0, j=0;
    while(i<sizel && j<sizer){
        if(tmpl[i]<=tmpr[j]){
            a[k++] = tmpl[i++];
        }else{
            a[k++] = tmpr[j++];
        }
    }
    
    while(i<sizel)
        a[k++]=tmpl[i++];

    while(j<sizer)
        a[k++]=tmpr[j++];
}

void insertion_sort(int a[], int size){
    for(int i=0; i<size;i++)
        for(int j=i; j>0; j--)
            if(a[j]<a[j-1])
                swap_var_int_array(a, j, j-1);
}
void straignt_selection_sort(int* a, int size){
    for(int i=0; i<size; i++){
        int min = a[i];
        int min_indx = i;
        for(int j=i+1; j<size; j++){
            if(a[j]<min){
                min = a[j];
                min_indx = j;
            }
        }
        swap_var_int_array(a, i, min_indx);
    }
}
// sorting by Straight Exchange
void bubble_sort(int *a, int size){
    for(int i=0; i<size; i++){
        for(int j=size-1; j>i; j--){
            if(a[j-1]>a[j])
                swap_var_int_array(a, j, j-1);
        }
    }
}
/*
// Straight insertion considers in each step only the one next item of the source sequence and all items of the destination array to find the insertion point
void insertion_sort(int a[], int size){
    for(int i = 1; i<size; i++)
        for(int j = i-1; j>0 && a[j-1]>a[j]; j--)
            swap_var_int_array(a, j, j-1);
}


// straight selection considers all items of the source array to find the one with the least key and to be deposited as the one next item of the destination sequence
void straignt_selection(int* a, int size){
    for(int i=0; i<size-1; i++){
        int sm_indx=i, sm_num=a[i];
        for(int j=i+1; j<size; j++){
            if(a[j]<sm_num){
                sm_indx=j;
                sm_num=a[j];
            }
        }
        a[sm_indx] = a[i];
        a[i]=sm_num;
    }
}
*/
void insertion_sort_char(char s[], int size){
    for(int i = 1; i<size; i++)
        for(int j = i-1; j>0 && s[j-1]>s[j]; j--)
            swap_var_char_array(s, j, j-1);
}
int binary_search(int a[], int x, int l, int r){
    if(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==x)
            return 1;
        else if(a[mid]>x)
            return binary_search(a, x, l, mid-1);
        else
            return binary_search(a, x, mid+1, r);
    }
    return 0;
}

/* The idea of shellsort is that is early stages, far-apart elements are compared, rather than adjacent ones as in simpler interchange sorts */
/* Time complexity: O(n log n^2) */
void shellsort(int v[], int n){
    int gap, i, j, temp;

    for(gap = n/2; gap>0; gap /= 2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

// Tree sort. Straight selection
//void heap_sort(int *a, int size){
//    int l = size/2,r = size-1;
//    while(l>0){
//        l--;
//        sift(a,l,r);
//    }
//    while(r>0){
//        swap_var_int_array(a, 0, r);
//        //swap_vars(a, 0, r);
//        r--;
//        sift(a, l, r);
//    }
//}
//
//void sift(int *a, int l, int r){
//    int largest=l; // init largest as root
//    int j=2*largest+1, x=a[largest];
//    if(j<r && a[j+1]<a[j])
//        j=j+1;
//    while(j<=r && a[j]<x){
//        a[largest]=a[j];
//        largest=j;
//        j=2*j;
//        if(j<r && a[j+1] < a[j])
//            j=j+1;
//        a[largest]=x;
//    }
//}
//
//void min_heapify(int *heap, int size){
//    int i = size - 1;
//    while(i>0 && heap[i] < heap[(i-1)/2]){
//        swap_var_int_array(heap, i, (i-1)/2);
//        i=(i-1)/2;
//    }
//}

int get_median(int *a, int size){
    int l = 0, r = size - 1;
    int x, i, j, k=size/2;
    while(l<r-1){
        x = a[k];
        i = l;
        j = r;
        do{
            while(a[i]<x)
                i++;
            while(x<a[j])
                j--;
            if(i<=j)
                swap_var_int_array(a, i++, j--);
        }while(i>j);
        if(j<k)
            l=i;
        if(k<i)
            r=j;
    }
    return a[k];
}
        
