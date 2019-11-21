#include <stdio.h>
/* 
 * TODO: fix shell_sort, shaker_sort
 */


void partition_qsort(int *a, int size);

// Insertion sort by diminishing increment
void shell_sort(int *a, int size);

void swap_vars(int *a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void shaker_sort(int *a, int size){
    int L = 0, R=size-1, k = R;
    while(L>R){
        for(int j=R; j<=L; j--){
            if(a[j-1]>a[j]){
                swap_vars(a, j-1, j);
                k=j;
            }
            L = k+1;
            for(j=L; j<=R; j++){
                if(a[j-1]>a[j]){
                    swap_vars(a, j-1, j);
                    k=j;
                }
            }
        R = k-1;
        }
    }
}



void binary_insertion(int *a,int size){
    for(int i=0; i<size; i++){
        int x = a[i], L=0,R=i;
        // Insertion position is found if L=R
        while(L<R){
            int m;
            m = (L+R)/2;
            if(a[m]<=x)
            {
                //printf("%d", L);
                L = m+1;
            }
            else{
                R=m;
                //printf("%d", R);
            }
            //printf("\n");
        }
        printf("L=%d R=%d\n",L,R); 
        for(int j=i;j>=R+1;j--){
            a[j]=a[j-1];
        }
        a[R]=x;
    }
}

void straight_insertion(int* a, int size){

    for(int i=0; i<size; i++){
        int x = a[i];
        int j = i;
        while(j>0 && x<a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        a[j]=x;
    }
}

void print_array(int *a, int size){
    for(int i=0; i<size; i++)
        printf(" %d ", a[i]);
    printf("\n");
}

int main(){
    int a[] = {44,55,12,42,94,18,6,67};
    int size = 8;
    printf("Orig: 44,55,12,42,94,18,6,67\n");
    //straight_insertion(a,8);
    //binary_insertion(a, 8);
    //straignt_selection(a, 8);
    //bubble_sort(a, 8);
    //shaker_sort(a, size);
    //shell_sort(a, size);
    //heap_sort(a, size);
    partition_qsort(a, size);
    print_array(a, size);
    return 0;
}


void shell_sort(int *a, int size){
    int i, j, k, m, s, x;
    int h[] = {9,5,3,1};
    for(m=0;m<=4;m++){
        k=h[m];
        for(i=k+1;i<size;i++){
            x=a[i];
            j=i-k;
            while(j>=k && x<a[j]){
                a[j+k] = a[j];
                j=j-k;
            a[j+k] = x;
            }
            print_array(a, size);
        }
    }
}

// Partition sort. Based on principle of exchange
void partition_qsort(int *a, int size){
   int i=0, j=size-1, w, x;
   do{
       x=j;
       while(a[i]<x)
           i++;
       while(x<a[j])
           j--;
       if(i<=j){
           swap_vars(a,i,j);
           i++;
           j--;
       }
   }while(i>j);
}


