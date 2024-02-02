CC=gcc
BIN=main
OBJ=main.o add.o sub.o mul.o
CF=main.c add.c sub.c mul.c
all:$(BIN)

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
