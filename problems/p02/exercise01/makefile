all: client

client: client.o IntegerSet.o
	gcc client.o IntegerSet.o -g -o client

client.o: client.c IntegerSet.h
	gcc -std=c99 -Wall -Werror -g -c client.c

Matrix.o: IntegerSet.c IntegerSet.h
	gcc -std=c99 -Wall -Werror -c IntegerSet.c
