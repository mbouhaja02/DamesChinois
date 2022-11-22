WIDTH ?= 5
HEIGHT ?= 4
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)
SRCS = wolrd.c neighbors.c
OBJS = $(SRCS:.c = .o)

all: test_project

%.o: src/%.c
	gcc -c $(CFLAGS) $<

%.o: tst/%.c
	gcc -c $(CFLAGS) $<

project: project.o
	cc $(CFLAGS) project.o -o project
tests: tests.o 
	gcc $(CFLAGS) $^ -o tests

test_project: tests.o 
	gcc $(CFLAGS) $^ -o test_project

clean:
	rm -f project test_project *.o *~
