WIDTH ?= 5
HEIGHT ?= 4
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)
SRCS = world.c neighbors.c geometry.c
OBJS = $(SRCS:.c=.o)

<<<<<<< HEAD
all: test_project 
=======
all: test_project
>>>>>>> daa6ad809cd77752d7438fd9700478ae58f2b3fd

%.o: src/%.c
	gcc -c $(CFLAGS) $<

%.o: tst/%.c
	gcc -c $(CFLAGS) $<

project: project.o $(OBJS)
	cc $(CFLAGS) project.o -o project

<<<<<<< HEAD
test_project: tests.o $(OBJS)
=======
test_project: tests.o 
>>>>>>> daa6ad809cd77752d7438fd9700478ae58f2b3fd
	gcc $(CFLAGS) $^ -o test_project

clean:
	rm -f project test_project *.o *~
