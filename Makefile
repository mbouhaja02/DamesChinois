WIDTH ?= 5
HEIGHT ?= 4
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)
<<<<<<< HEAD


=======
SRCS = wolrd.c neighbors.c
OBJS = $(SRCS:.c = .o)
>>>>>>> 23f39cdc9dbbda23d98f24b1513f775f44921786
all: project

%.o: %.c
	gcc -c $(CFLAGS) $<

project: # (Add your dependency here, e.g "project.o")
	# (Add your compile command here, e.g "gcc $(CFLAGS) project.o -o project")
geometry: geometry.o
	gcc $(CFLAGS) geometry.o -o geometry

wolrd: wolrd.o
	gcc $(CFLAGS) world.o -o world

neighbors: neighbors.o
	gcc $(CFLAGS) neighbors.o -o neighbors

<<<<<<< HEAD
test_project: test.o
	gcc $(CFLAGS) test.o -o test_project
=======
tests: tests.o 
	gcc $(CFLAGS) tests.o -o tests

test_project: # (Add your dependency here, e.g "test.o")
	# (Add your compile command here, e.g "gcc $(CFLAGS) test.o -o test_project")
>>>>>>> 23f39cdc9dbbda23d98f24b1513f775f44921786

	rm -f project test_project *.o *~
