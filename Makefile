WIDTH ?= 5
HEIGHT ?= 4
MANSUBA_FLAGS = -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MANSUBA_FLAGS)


all: project

%.o: %.c
	gcc -c $(CFLAGS) $<

<<<<<<< HEAD
project: project.o
	gcc $(CFLAGS) project.o -o project
=======
project: # (Add your dependency here, e.g "project.o")
	# (Add your compile command here, e.g "gcc $(CFLAGS) project.o -o project")
geometry: geometry.o
	gcc $(CFLAGS) geometry.o -o geometry

wolrd: wolrd.o
	gcc $(CFLAGS) world.o -o world

neighbors: neighbors.o
	gcc $(CFLAGS) neighbors.o -o neighbors
>>>>>>> b5e1fa5d20a94e9d0b9e8906809ec5f5ec7e89fb

test_project: test.o
	gcc $(CFLAGS) test.o -o test_project

	rm -f project test_project *.o *~
