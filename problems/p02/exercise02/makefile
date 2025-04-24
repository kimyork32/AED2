all: client

client: client.o Matrix.o
	gcc client.o Matrix.o -g -o client

client.o: client.c Matrix.h
	gcc -std=c99 -Wall -Werror -g -c client.c

Matrix.o: Matrix.c Matrix.h
	gcc -std=c99 -Wall -Werror -c Matrix.c
