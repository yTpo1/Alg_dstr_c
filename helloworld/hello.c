#include <stdio.h>

// https://johnloomis.org/ece537/notes/hello/hello.html

int main(int argc, char* argv[]){
    char *sal = "world";
    if (argc>1) sal = argv[1];
    printf("Hello, %s!\n", sal);
    return 0;
}
