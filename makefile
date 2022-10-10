CC=gcc

CFLAGS=-O0 -c -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all : exercicio3

exercicio3 : lista.o exercicio3.o
	$(CC) lista.o exercicio3.o -o programa

exercicio3.o : exercicio3.c
	$(CC) $(CFLAGS) exercicio3.c

lista.o : lista.c lista.h
	$(CC) $(CFLAGS) lista.c

clean :
	rm *.o programa
