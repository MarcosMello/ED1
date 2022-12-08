CC=gcc

CFLAGS=-c -g -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 

all : main 

main : ponto.o lista.o no.o main.o
	$(CC) ponto.o lista.o no.o main.o -o main

main.o : main.c
	$(CC) $(CFLAGS) main.c

no.o : no.c no.h
	$(CC) $(CFLAGS) no.c

ponto.o : ponto.c ponto.h
	$(CC) $(CFLAGS) ponto.c

lista.o : no.o lista.c lista.h
	$(CC) $(CFLAGS) lista.c

clean : 
	rm *.o main	
