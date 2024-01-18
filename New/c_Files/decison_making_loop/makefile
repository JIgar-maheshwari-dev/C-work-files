CC=gcc
C=$(wildcard ./*.c)
OBJ=$(patsubst %.c,%.o,$(C))
DIR=./build
LS != ls

all:$(OBJ) main

$(OBJ):$(C)
	$(CC) -c $?

%:%.o
	$(CC) -o $@ $?
	./$@
	mv $@ ./out/
	make mv

clear:
	rm *.o

mv:
	mv *.o ./build

list:
	echo $(LS)
