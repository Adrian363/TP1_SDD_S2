CC=gcc
OPT= -c -ansi -pedantic -Wall
tp1 : tp1.o basics.o matrix.o
	$(CC) -o tp1 Tp1.o basics.o matrix.o
tp1.o : Tp1.c
	$(CC) $(OPT) Tp1.c 
basics.o : basics.c basics.h
	$(CC) $(OPT) basics.c 
matrix.o : matrix.c matrix.h
	$(CC) $(OPT) matrix.c
clair :
	rm tp1.o basics.o matrix.o
propre : clair
	rm tp1
