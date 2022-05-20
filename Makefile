all:
	gcc -g3 -fsanitize=address *.c -o teste
