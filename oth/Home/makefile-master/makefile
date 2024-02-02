CC=gcc
INC= -I /home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/header \
-I /home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/libs

LIB_INC= -L /home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/libs/lib_my.a
CSRC=/home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/cf
OSRC=
ODST=/home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/build
BDST=/home/jigar/Downloads/training/jigar_maheshwari_idp/oth/Home/makefile-master/out

CFILES=$(foreach D,$(CSRC),$(wildcard $(D)/*.c)) main.c 
OBJ3=$(foreach D,$(ODST),$(wildcard $(D)/*.o)) 

OBJ=$(patsubst %.c,%.o,$(CFILES)) main.o
OBJ2=$(patsubst %/cf,%/build,$(OBJ)) 

DEPS=$(patsubst %.c,%.d,$(CFILES))
BIN=main

all:$(BIN)

$(BIN):$(OBJ) 
	$(CC) -o $@ $(OBJ3) $(INC) $(LIB_INC)
	mv $@ $(BDST)

$(OBJ):$(CFILES) 
	$(CC) -c $? $(INC)
	mv *.o $(ODST)

clear:
	rm *.o main
	
pritf:
	$(info $(OBJ3))
