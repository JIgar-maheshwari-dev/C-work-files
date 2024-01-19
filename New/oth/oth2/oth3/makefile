CC=gcc
BIN=main
OBJ=main.o add.o sub.o mul.o
CF=main.c add.c sub.c mul.c
all:$(BIN)

MY=$(OBJ) $(CF)


$(BIN):$(OBJ)
	$(CC) -o $@ $^
	$(info "inside BIN  ")
	$(info $@ "this is /$/@" )
	$(info $? "this is /$/?")
	$(info $< "this is /$/<")
	$(info $^ "this is /$/^")


%.o:%.c
	$(CC) -c $?
	$(info "inside OBJ  ")
	$(info $@ "this is /$/@" )
	$(info $? "this is /$/?")
	$(info $< "this is /$/<")
	$(info $^ "this is /$/^")

clear:
	rm main *.o

print:
	$(info $(MY), this is just my)
	$(info $(filter %.c,$(MY)), this printing .c using filter)
	@echo `pwd`

hii::
	$(info this is hiii 1)

hii::
	$(info this is hii 2)

mymake:
	$(info $(J))
