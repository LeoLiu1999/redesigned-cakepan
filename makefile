clean: 
	rm *~ ./rando

run:
	gcc -o rando c.c
	./rando

all: clean run
	clean
	run
