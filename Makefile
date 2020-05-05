CC=clang
CFLAGS = -g -Wall
MAIN = main_test.out
#LIBS=-lm

INCLUDES = -I/lib_algorithms/ -I/lib_datastr/ -I/lib_unittest/

SRCS = main_test.c $(ALGSRC) $(DSTRSRC) $(UNITSRC)
ALGSRC = $(addprefix lib_algorithms/, array_questions.c  numbers.c helper_func.c str_questions.c)
DSTRSRC = $(addprefix Dstr/, binary_tree.c circ_link_list.c linked_list.c \
	  stack_array.c stack_ll.c queue.c)
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
