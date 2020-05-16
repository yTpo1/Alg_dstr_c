#ifndef UNIT_TEST_H_INCLUDED
#define UNIT_TEST_H_INCLUDED

#define ASIZE 1000

void assert_int_eq(int a, int b, char *testname);
void assert_char_eq(char c, char x, char *t_name);
void assert_str_eq(char *s1, char *s2, char *testname);
void assert_int_array_eq(int *a, int *b, int size, char *title);
void print_test_status();
void print_int_array(int a[], int size);

int my_strequal(char *s1, char *s2);
double get_time();

#endif
