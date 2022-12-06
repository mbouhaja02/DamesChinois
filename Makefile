WIDTH ?= 10
HEIGHT ?= 10
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -Idir/src -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)
SRCS = world.c neighbors.c geometry.c ensemble.c movements.c board.c victoire.c partie.c
OBJS = $(SRCS:.c=.o)

all: test_project

%.o: src/%.c
	gcc -c $(CFLAGS) $<

%.o: tst/%.c
	gcc -c $(CFLAGS) $<

project: tests.o $(OBJS)
	gcc $(CFLAGS) tests.o -o project

test_project: tests.o $(OBJS)
	gcc $(CFLAGS) $^  -o test_project

test : test_project
	./test_project

clean:
	rm -f project test_project *.o *~
