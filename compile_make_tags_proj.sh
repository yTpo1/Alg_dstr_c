#!/bin/sh
gcc main_test.c lib_algorithms/array_questions.c lib_algorithms/str_questions.c lib_unittest/myunittest.c lib_algorithms/helper_func.c lib_algorithms/numbers.c lib_datastr/linked_list.c lib_datastr/circ_link_list.c
ctags -R
