CC=gcc

hello:hellomake.h hellomake.o hellofunc.o
	$(CC) -o hello hellomake.o hellofunc.o

hellofunc.o:hellofunc.c hellomake.h
	$(CC) -c hellofunc.c

hellomake.o:hellomake.c hellomake.h
	$(CC) -c hellomake.c

o_all:hellomake.o hellofunc.o


.c.o:   
	$(CC) -c $<

#.c.out:
#	$(CC) -o make.out $<

clear:
	rm *.o 
