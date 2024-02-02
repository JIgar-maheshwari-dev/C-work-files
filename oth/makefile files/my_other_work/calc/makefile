CC=gcc
CFILES=calc.c add.c sub.c
LIB_C=mul.c div.c
OBJS=calc.o add.o sub.o
LIB_OBJ=mul.o div.o
LIB=lib_div_mul.a
OPT=-o
LIB_OPT=-L.

main:$(OBJS) $(LIB_OBJ) $(LIB)
	$(CC) $(OPT) main $(OBJS) $(LIB_OPT) $(LIB)
	 cp $(OBJS) $(LIB_OBJ) ./obj
	 cp $@ ./exec
	 make clear

$(OBJS):$(CFILES)
	$(CC) -c $(CFILES)

$(LIB_OBJ):$(LIB_C)
	$(CC) -c $(LIB_C)

$(LIB):$(LIB_OBJ)
	ar -rc $(LIB) $(LIB_OBJ) 
	
clear:
	rm main *.o
	

