#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int size){
  printf("\n");
  for(int i=0; i<size; i++)
    printf("%d ", a[i]);
}

void swap(int *a, int *b){
  int tmp = *a;
  *a=*b;
  *b=tmp;
}

int partition(int *a, int low, int high){
  int pivot = a[high];
  int i = (low -1);

  for(int j=low;j<=high-1;j++){
    if(a[j]<=pivot){
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i+1], &a[high]);

  return (i+1);
}

void quickSort(int *a, int low, int high){
  if(low<high){
    int p = partition(a, low, high);
    quickSort(a, low, p-1);
    quickSort(a, p+1, high);
  }

}

int main(){

  int a[] = {2,5,16,34,1,6,73,6,7,3};
  int size = sizeof(a)/sizeof(a[0]);

  printf("\n size-%d", size);
  quickSort(a, 0, size-1);
  printArray(a, size);

  return 0;
}
