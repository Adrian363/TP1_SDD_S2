CC=gcc
OPT= -c -ansi -pedantic -Wall
tp1 : tp1.o basics.o matrix.o linked_list.o
	$(CC) -o tp1 Tp1.o basics.o matrix.o linked_list.o
tp1.o : Tp1.c
	$(CC) $(OPT) Tp1.c 
basics.o : basics.c basics.h
	$(CC) $(OPT) basics.c 
matrix.o : matrix.c matrix.h
	$(CC) $(OPT) matrix.c
linked_list.o : linked_list.c linked_list.h
	$(CC) $(OPT) linked_list.c
clair :
	rm tp1.o basics.o matrix.o linked_list.o
propre : clair
	rm tp1
	
 