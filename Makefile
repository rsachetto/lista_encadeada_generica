CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -g3

all: main

main: main.c lista_encadeada.c
	$(CC) $(CFLAGS) main.c lista_encadeada.c -o main

test: testes_runner
	./testes_runner

testes_runner: testes/testes_lista.c lista_encadeada.c
	$(CC) $(CFLAGS) testes/testes_lista.c lista_encadeada.c -lcriterion -o testes_runner

clean:
	rm -f *.o main testes_runner

.PHONY: all clean test

