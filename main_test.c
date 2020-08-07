#include <stdio.h>
#include <string.h>
#include "lib_unittest/myunittest.h"
#include "Algorithms/array_questions.h"

#include "Test/test_numbers.h"
#include "Test/test_dstr.h"
#include "Test/test_cryptography.h"
#include "Test/test_array_alg.h"
#include "Test/test_string.h"


int main(int argc, char *argv[])
{
	int all = 0;

	if (argc == 2 && strcmp(argv[argc - 1], "-h") == 0) {
		printf("Options: array dstr str num crypto\n");
		return 0;
	}

	if(argc == 1)
		all = 1;
	while (argc > 1 || all) {
		if (strcmp(argv[argc - 1], "array") == 0 || all)
			run_array_tests();
		if (strcmp(argv[argc - 1], "dstr") == 0 || all)
			run_data_structure_tests();
		if (strcmp(argv[argc - 1], "crypto") == 0 || all)
			run_test_cryptography();
		if (strcmp(argv[argc - 1], "num") == 0 || all)
			run_number_tests();
		if (strcmp(argv[argc - 1], "str") == 0 || all)
			run_string_tests();
		if (all)
			all--;
		argc--;
	}		
	print_test_status();
	return 0;
}
