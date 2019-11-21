
/* used by random function */
unsigned long int next = 1;

/* atoi: Convert a string of digits to integer */
int atoi(char s[]){
    int n = 0;
    for(int i=0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c){
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

/* isdigit: check if c is a digit */
int isdigit(int c){
    if(c >= '0' && c <= '9') //(c>=0 && c<=9)
        return 1;
    else
        return 0;
}

/* rand: return pseudo-random integer on 0..32767 */
int rand(){
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed){
    next = seed;
}
