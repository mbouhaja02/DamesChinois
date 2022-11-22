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
>>>>>>> 740335a39d35f2bab07e010dc9bb9e02a1e8ef1d

%.o: src/%.c
	gcc -c $(CFLAGS) $<

%.o: tst/%.c
	gcc -c $(CFLAGS) $<

project: project.o $(OBJS)
	cc $(CFLAGS) project.o -o project

<<<<<<< HEAD
test_project: tests.o 
=======
test_project: tests.o $(OBJS)
>>>>>>> 740335a39d35f2bab07e010dc9bb9e02a1e8ef1d
	gcc $(CFLAGS) $^ -o test_project

clean:
	rm -f project test_project *.o *~
