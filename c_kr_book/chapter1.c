#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

void copy_input_to_output(){
    int c;
    while((c=getchar()) != EOF)
        putchar(c);
}

void count_characters(){
    /* Count characters in input */
    long nc = 0;

    while(getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
}

void count_lines(){
    int c, nl;
    nl = 0;
    while((c = getchar())!=EOF)
        if(c == '\n')
            nl++;
    printf("%d\n", nl);
}

void word_count(){
    int c, nw, nl, nc;
    int state = OUT;
    nl = nw = nc = 0;
    while((c=getchar())!=EOF){
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
           state = OUT;
        else if(state==OUT){
            state = IN;
            ++nw;
        }
    }
    printf("nc-%d nw-%d nl-%d\n", nc, nw, nl);
}

void count_characters2(){
    int c, i, n_white, n_other;
    int ndigit[10];
    n_white = n_other = 0;
    for(i = 0; i<10; ++i)
        ndigit[i]=0;

    while((c = getchar()) != EOF)
        if(c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if(c == '\n' || c == ' ' || c == '\t')
            ++n_white;
        else
            ++n_other;

    for(i=0;i<10;++i)
        printf(" *%d-%d ",i,ndigit[i]);
    
    printf("\nwhite-%d, other-%d \n",n_white, n_other);
}

void print_longest_input_line(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = my_getline(line, MAXLINE)) > 0)
        if(len>max){
            max = len;
            copy(longest, line);
            }
    if(max > 0)
        printf("%s", longest);
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim){
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to; assume to is big enough */
void copy(char to[], char from[]){
    int i=0;
    while((to[i]=from[i])!='\0')
        i++;
}

int power2(int m, int n){
    int p = 1;
    for(; n>0;--n)
        p = p * m;
    return p;
}

int power(int m, int n){
    int p = 1;
    for(int i=1;i<=n;++i)
        p = p * m;
        //m = m * m;
    return p;
}
