#!/bin/sh
gcc main_test.c lib_algorithms/array_questions.c lib_algorithms/array_questions.h lib_algorithms/str_questions.c lib_algorithms/str_questions.h lib_unittest/myunittest.h lib_unittest/myunittest.c lib_algorithms/helper_func.c lib_algorithms/helper_func.h lib_algorithms/numbers.c lib_algorithms/numbers.h
ctags -R
