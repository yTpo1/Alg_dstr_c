#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "myunittest.h"

static int count_test_run = 0;
static int count_test_failed = 0;

void print_int_array(int a[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void assert_char_eq(char a, char b, char *t_name)
{
	if (a != b) {
		printf("Test %s: char equal. \033[0;31m Failed \033[0m \n", t_name);
		printf("%c!=%c\n", a, b);
		count_test_failed++;
	}
	count_test_run++;
}

// TODO: this function is absolute shit. fix it and then start using cmocka or
// a normal unit test library. FUCK
void test_intarray_eq(int *a, int *b, int size, char *title)
{
	int error = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) {
			error = 1;
			break;
		}
	}
	if (error){
		printf("Test \"%s\": int array comparison. \033[0;31m Failed \033[0m \n", title);
		//printf("a[%d]:%d != b[%d]:%d\n", i, a[i], i, b[i]);
		//printf("Original size: %d, traversed i: %d. a[i]!=b[i] %d!=%d\n", size, i, a[i], b[i]);
		printf("Array 1: ");
		print_int_array(a, size);
		printf("Array 2: ");
		print_int_array(b, size);
		count_test_failed++;
	}
	count_test_run++; 
}

/* strlen: return lenght of string s */
int my_strlen(char *s){
    int n;
    for(n=0; *s != '\0'; s++)
        n++;
    return n;
}

//int my_strequal(char *s1, char *s2){
//	if (s1 == NULL
//
//	for(; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
//		if(*s1 != *s2)
//			return 0;
//	if(*s1 == '\0' && *s2 == '\0')
//		return 1;
//	else
//		return 0;
//}

void assert_str_equal(char *s1, char *s2, char *testname)
{
	int diff = 0;
	int isnull = 0;
	if (s1 == NULL && s2 != NULL) {
		diff = 1;
		isnull = 1;
	}
	else if (s2 == NULL && s1 != NULL) {
		diff = 1;
		isnull = 1;
	}
	else if (s1 == NULL && s2 == NULL)
		diff = 0;
	else
		diff = strcmp(s1, s2);

	if (diff) {
		if (isnull)
			printf("Test \"%s\" failed, one of the stings is null\n", testname);
		else {
			printf("Test \"%s\": String comparison. \033[0;31m Failed \033[0m \n", testname);
			printf("Diff: %d. %s != %s s1-size:%d s2-size:%d\n", diff, s1, s2, my_strlen(s1), my_strlen(s2));
		}
		count_test_failed++;
	}
	count_test_run++;
}

void test_intequal(int a, int b, char *testname){
    if(a != b){
        printf("Test \"%s\": int comparison \033[0;31m Failed \033[0m \n", testname);
        printf("%d!=%d\n",a,b);
        count_test_failed++;
    }
    count_test_run++;
}

void print_test_status(){
    printf("--------------------------\n");
    if(count_test_failed > 0)
        printf("Tests \033[0;31m failed \033[0m: %d\n", count_test_failed);
    printf("Tests run: %d\n", count_test_run);

}

double get_time(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}
