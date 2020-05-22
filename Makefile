CC=clang
CFLAGS = -g -Wall -fsanitize=undefined
MAIN = main_test.out
LIBS=-lm

INCLUDES = -I/Algorithms/ -I/Dstr/ -I/lib_unittest/ -I/Test/ -I/Cryptography/

SRCS = main_test.c $(ALGSRC) $(DSTRSRC) $(CRYPTOGRAPHY) $(UNITSRC) $(TESTS)
ALGSRC = $(addprefix Algorithms/, array_questions.c  numbers.c helper_func.c \
	 str_questions.c hash_function.c)
DSTRSRC = $(addprefix Dstr/, binary_tree.c circ_link_list.c linked_list.c \
	  stack_array.c stack_ll.c queue.c hash_table.c hash_table_oaddr.c \
	  graph.c heap.c priority_queue.c red_black_trees.c)
CRYPTOGRAPHY = $(addprefix Cryptography/, caesar.c polyalphabetic.c)
UNITSRC = lib_unittest/myunittest.c
TESTS = $(addprefix Test/, test_numbers.c test_dstr.c test_cryptography.c test_array_alg.c)

OBJS = $(SRCS:.c=.o)

all: $(MAIN)
	@echo Unit tests on algoriths and datastructures has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

.PHONY: clean

clean:
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*.gch' -exec rm {} +
	rm -f $(MAIN)
