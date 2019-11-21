#include <stdio.h>
#include <stdlib.h>

struct MaxHeap{
  int size;
  int *arr;
};

void swap(int *a, int *b){ int t=*a; *a=*b;*b=t;}

void maxHeapify(struct MaxHeap* maxHeap, int idx){
  int largest = idx;
  int left = (idx << 1)+1; // left = 2*idx+1
  int right = (idx +1)<<1; //right = 2*idx+2

  if(left < maxHeap->size &&
    maxHeap->arr[left] > maxHeap->arr[largest])
    largest=left;

  if(right < maxHeap->size &&
    maxHeap->arr[right] > maxHeap->arr[largest])
    largest=right;

    if(largest != idx){
      swap(&maxHeap->arr[largest], &maxHeap->arr[idx]);
      maxHeapify(maxHeap, largest);
    }
}


struct MaxHeap* createAndBuildHeap(int *arr, int size){
  int i;
  struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
  maxHeap->size = size;
  maxHeap->arr = arr;

  for(i =(maxHeap->size-2)/2; i>=0; --i)
    maxHeapify(maxHeap, i);
  return maxHeap;
}

void printArray(int *a, int size){
  printf("\n");
  for(int i=0; i<size; i++)
    printf("%d ", a[i]);
}

void heapSort(int *a, int size){
  struct MaxHeap* maxHeap = createAndBuildHeap(a, size);
  printf("/nMaxHeap Created and build: ");
  printArray(a, size);

  while(maxHeap->size > 1){
    swap(&maxHeap->arr[0], &maxHeap->arr[maxHeap->size-1]);
    --maxHeap->size;
    maxHeapify(maxHeap, 0);
  }

}

int main(){
  int a[] = {2,5,16,34,1,6,73,6,7,3};
  int size = sizeof(a)/sizeof(a[0]);

  heapSort(a, size);
  printArray(a, size);

  return 0;
}
