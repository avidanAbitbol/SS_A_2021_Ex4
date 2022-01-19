CC=gcc
FLAGS= -Wall -g

all: Graph

Graph: main.o
	$(CC) $(FLAGS) -o Graph main.c

main.o: main.c Algo.o Graph.o
	$(CC) $(FLAGS) -c main.c

Algo.o: Algo.h Algo.c
	$(CC) $(FLAGS) -c Algo.c


Graph.o: Graph.h Graph.c
	$(CC) $(FLAGS) -c Graph.c



clean:
	rm -f *.o *.a *.so Graph


.PHONY: clean all