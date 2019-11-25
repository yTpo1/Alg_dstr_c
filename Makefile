CC=gcc
CFLAGS=-I.
DEPS = lib_algorithms/array_questions.h lib_algorithms/helper_func.h lib_algorithms/numbers.h lib_algorithms/str_questions.h lib_datastr/binary_tree.h lib_datastr/circ_link_list.h lib_datastr/linked_list.h lib_datastr/node.h lib_unittest/myunittest.h
OBJ = main_test.o lib_algorithms/array_questions.o lib_algorithms/helper_func.o lib_algorithms/numbers.o lib_algorithms/str_questions.o lib_datastr/binary_tree.o lib_datastr/circ_link_list.o lib_datastr/linked_list.o lib_unittest/myunittest.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

unit_tests: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
