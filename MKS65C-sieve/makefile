all : driver.o sieve.o sieve.h
	gcc sieve.o driver.o -lm

run : 
	./a.out $(args)

sieve.o : sieve.c sieve.h
	gcc -c sieve.c -lm

driver.o : driver.c
	gcc -c driver.c

clean :
	rm *.o

debug: driver.o sieve.o sieve.h
	gcc -g sieve.o driver.o -lm
	gdb ./a.out

mem: all
	valgrind --leak-check=yes ./a.out -v
