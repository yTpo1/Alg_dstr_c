CC=gcc
CFLAGS = -g -Wall
MAIN = unit_tests.out
#LIBS=-lm

INCLUDES = -I/lib_algorithms/ -I/lib_datastr/ -I/lib_unittest/

SRCS = main_test.c $(ALGSRC) $(DSTRSRC) $(UNITSRC)
#ALGSRC = lib_algorithms/array_questions.c  lib_algorithms/numbers.c lib_algorithms/helper_func.c lib_algorithms/str_questions.c
ALGSRC = $(addprefix lib_algorithms/, array_questions.c  numbers.c helper_func.c str_questions.c)
DSTRSRC = lib_datastr/binary_tree.c lib_datastr/linked_list.c lib_datastr/circ_link_list.c
UNITSRC = lib_unittest/myunittest.c

OBJS = $(SRCS:.c=.o)

all: $(MAIN)
	@echo Unit tests on algoriths and datastructures has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

#.c.o:
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean

clean:
	find . -type f -name '*.o' -exec rm {} +
	rm -f $(MAIN)
