CC=gcc

CFLAGS=-O0 -c -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all : exercicio2

exercicio2 : lista.o exercicio2.o
	$(CC) lista.o exercicio2.o -o programa

exercicio2.o : exercicio2.c
	$(CC) $(CFLAGS) exercicio2.c

lista.o : lista.c lista.h
	$(CC) $(CFLAGS) lista.c

clean :
	rm *.o programa
