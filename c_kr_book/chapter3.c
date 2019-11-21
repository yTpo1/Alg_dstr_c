#include <ctype.h>
#include <string.h>

/* atoi: convert s to int; version 2 */
int atoi_v2(char s[]){
    int i, n, sign;

    // skip white spaces
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    // skip sign
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(n=0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* The idia of shellsort is that is early stages, far-apart elements are compared, rather than adjacent ones as in simpler interchange sorts */
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

/* reverse: reverse string s in place */
void reverse(char s[]){
    int c, i, j;

    for(i=0, j=strlen(s)-1; i<j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;

    if((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    do{ // generate digits in reverse order
        s[i++] = n % 10 + '0'; // get next digit
    }while((n /= 10) > 0); // delete it
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
