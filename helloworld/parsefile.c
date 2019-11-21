#include <stdio.h>
#define MAXCHAR 1000

int datasize = 100;
char* filename = "100nums.csv";

void file_data_to_array(int a[]){
    FILE *fp;
    fp = fopen(filename, "r");
    char str[MAXCHAR];

    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        a[i++]=
//printf("%s", str);
    fclose(fp);
}
 
int main() {
 
    
    return 0;
}
