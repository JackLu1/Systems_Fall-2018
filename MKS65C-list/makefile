all : link.o test.o
	gcc test.o link.o

test.o : test.c 
	gcc -c test.c

link.o : link.c link.h
	gcc -c link.c

run : all
	./a.out

clean : 
	rm *.o
	rm a.out
