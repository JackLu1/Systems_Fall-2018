compile : cstring.o str.o
	gcc cstring.o str.o

run : 
	./a.out

cstring.o : cstring.c
	gcc -c cstring.c

str.o : str.c str.h
	gcc -c str.c

clean : 
	rm *.o
