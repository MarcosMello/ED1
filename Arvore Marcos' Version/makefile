CC=gcc

CFLAGS=-c -g -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all : main

main : ponto.o arvore.o no.o main.o
	$(CC) ponto.o arvore.o no.o main.o -o main

main.o : main.c
	$(CC) $(CFLAGS) main.c

no.o : no.c no.h
	$(CC) $(CFLAGS) no.c

ponto.o : ponto.c ponto.h
	$(CC) $(CFLAGS) ponto.c

arvore.o : no.o arvore.c arvore.h
	$(CC) $(CFLAGS) arvore.c

clean :
	rm *.o main
