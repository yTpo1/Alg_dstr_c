#ifndef ARRAY_QUESTIONS_H
#define ARRAY_QUESTIONS_H

struct tuple {
	int li;
	int ri;
	int s;
};

void insertion_sort(int a[], int size);
void insertion_sort_char(char s[], int size);
int binary_search(int a[], int x, int l, int r);
void quick_sort(int a[], int l, int r); 
void merge_sort(int a[], int l, int r);
void bubble_sort(int *a, int size);
void straignt_selection_sort(int* a, int size);
void heap_sort(int *a,int size);
int get_median(int *a, int size);
void min_heapify(int *heap, int size);
void max_sub_array(int cost[], int asize, int *i, int *j);
struct tuple *max_sub_array_dnq(int a[], int l, int h);

#endif
