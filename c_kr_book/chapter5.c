#include <stdio.h>
#include <ctype.h>

int getch();
int ungetch();
void swap(int &a, int &b);
int getint(int *pn);

int main(){

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;
    /* skip white space */
    while(isspace(c=getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for(*pn = 0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}



void swap(int &a, int &b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
