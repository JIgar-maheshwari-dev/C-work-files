CC=gcc
SRC=$(wildcard ./source/*.c)
E_DIR=./out/
O_DIR=./obj/


OBJS=$(patsubst %.c,%.o,$(SRC))
export $(OBJS)

OBJ !=  echo $(OBJS) | cut -d '/' -f 3

all:$(E_DIR)main

$(E_DIR)main:$(O_DIR)$(OBJ)
	$(CC) -o $@ $^

$(O_DIR)$(OBJ):$(SRC)
	$(CC) -c $?
	mv *.o $(O_DIR)


print:
	$(info $(SRC))
	$(info $(OBJ))
	$(info $(OBJS))
	
