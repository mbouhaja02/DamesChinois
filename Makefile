WIDTH ?= 10
HEIGHT ?= 10
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -I src -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)
SRCS = world.c neighbors.c geometry.c set.c movements.c board.c victoire.c game.c prison.c
OBJS = $(SRCS:.c=.o)

all: project 

%.o: src/%.c
	gcc -c $(CFLAGS) $<

%.o: tst/%.c
	gcc -c $(CFLAGS) $<

project: tests.o $(OBJS)
	gcc $(CFLAGS) $^ -o project


test_project: tests.o $(OBJS)
	gcc $(CFLAGS) $^  -o test_project

test : test_project
	./test_project

clean:
	rm -f project test_* *.o *~

test_moves : test_moves.o $(OBJS)
	gcc $(CFLAGS) $^  -o movements
	./movements

test_board : test_board.o $(OBJS)
	gcc $(CFLAGS) $^ -o test_board

test_victory : test_victory.o $(OBJS)
	gcc $(CFLAGS) $^ -o test_victory

test_set : test_set.o $(OBJS)
	gcc $(CFLAGS) $^ -o test_set

test_captures : test_captures.o $(OBJS)
	gcc $(CFLAGS) $^ -o test_captures

test_distance: test_distance.o $(OBJS)
	gcc $(CFLAGS) $^ -o test_distance

