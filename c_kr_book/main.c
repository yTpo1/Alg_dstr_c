#include <stdio.h>
#include "chapter2.h"
#include "chapter3.h"

int main(){
    /*char s[3] = "357";*/
    /*printf("%d", atoi(s));*/
    /*printf("%d", isdigit('6'));*/
    /*printf("%d", isdigit('g'));*/
    /*printf("%d", rand());*/
    /*char c;*/
    /*while((c = getchar()) != '\n' && c != EOF)*/
        /*printf("%c",lower(c));*/
    int size = 10;
    int unsorted[] = {5,2,7,9,3,6,2,7,6,2};
    shellsort(unsorted, size);
    for(int i=0; i<size; i++)
        printf("%d,",unsorted[i]);
    printf("\n");

    return 0;
}
