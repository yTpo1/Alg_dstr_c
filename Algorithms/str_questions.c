#include "array_questions.h"
#include "helper_func.h"

#define AMAX 1000

char first_nonrep_char(char s[], int size)
{
	int nonrep = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (s[i] == s[j]) {
				nonrep = 1;
				break;
			}
		}
		if (nonrep == 0)
			return s[i];
		nonrep = 0;
	}
	return '0';
}

void rmv_char_from_str(char s[], char c, int size){
    int j=0, count_removed = 0;
    for(int i = 0; i<size; i++){
        if(s[i]!=c){
            s[j++]=s[i];
        }else{
            count_removed++;
        }
    }
    for(; count_removed>0; count_removed--)
        s[size-count_removed]='\0';
}
void rmv_char_from_str2(char s[], char c, int size){
    int count_removed = 0;
    for(int i = 0; i<size; i++){
        if(s[i]==c){
            for(int j = i; j<size; j++){
                s[j]=s[j+1];
            }
            i--;
            count_removed++;
        }
    }
    for(; count_removed>0; count_removed--)
        s[size-count_removed+1]='\0';
}

int check_string_anagram(char s1[], char s2[], int size){
    insertion_sort_char(s1, size);
    insertion_sort_char(s2, size);
    int i = 0;
    while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0')
        i++;
    return s1[i]==s2[i];
}

void find_duplicate_characters(char s[], char dup[]){
    int alphabet[26] = {0};
    int i = 0, j = 0;
    while(s[i]!='\0'){
        if(s[i]!=' ')
            alphabet[(s[i]-'a')]=alphabet[(s[i]-'a')]+1;
        i++;
    }
    i = 0;
    while(j<26){
        if(alphabet[j]>1)
            dup[i++]=97+j;
        j++;
    }
}

int str_size(char arr[]){
    int i=0;
    while(arr[i] != '\0')
        i++;
    return i;
}
int check_palindrome(char arr[]){
    int i=0, j=str_size(arr)-1;
    while(arr[i++]==arr[j--] && i<j)
        ;
    return arr[i]==arr[j];
}

void reverse_array(char arr[]){
    char cpyarr[AMAX];
    int i=0,j=0;
    while((cpyarr[i]=arr[i])!='\0')
        ++i;
    i=i-1;
    while(i>=0)
        arr[j++]=cpyarr[i--];
}
