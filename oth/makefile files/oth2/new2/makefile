VPATH=$(PWD)/src

SRC=$(wildcard $(VPATH)/*.c)
HDR= -I $(PWD)/hed

OBJ_DIR= $(PWD)/obj
OUT_DIR=$(PWD)/out
OBJ=$(patsubst $(VPATH)/%.c,$(OBJ_DIR)/%.o,$(SRC))

$(OUT_DIR)/main:$(OBJ)
	gcc -o $@ $^ 



$(OBJ):$(SRC)
	gcc -c $? $(HDR)
	-mv *.o $(OBJ_DIR)

print:
	@echo "SRC FILES        " $(SRC) 
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "OBJ FILES        " $(OBJ) 
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "     "
	@echo "NOT DIR"  $(notdir $(SRC))

clear:
	rm $(OBJ_DIR)/*.o $(OUT_DIR)/main
