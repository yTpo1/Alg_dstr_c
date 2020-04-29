#define ASIZE 1000

void test_intequal(int a, int b, char *testname);
void test_strequal(char *s1, char *s2, char *testname);
void test_intarray_eq(int *a, int *b, int size, char *title);
//void t_iarray_eq(int *, int *, char *);
//void test_int_array_equal(int a[], int b[], int size);
void print_test_status();
void print_int_array(int a[], int size);

int my_strequal(char *s1, char *s2);
double get_time();
