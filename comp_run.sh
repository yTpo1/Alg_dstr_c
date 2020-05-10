#!/bin/bash

make
./main_test.out
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main_test.out
