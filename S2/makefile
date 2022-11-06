CC = gcc

CFLAGS = -c -g -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all : main

main : no.o lista.o main.o
	$(CC) no.o lista.o main.o -o main

main.o : main.c lista.o no.o
	$(CC) $(CFLAGS) main.c

lista.o : no.o lista.c lista.h
	$(CC) $(CFLAGS) lista.c

no.o : no.c no.h
	$(CC) $(CFLAGS) no.c

clean :
	rm *.o main