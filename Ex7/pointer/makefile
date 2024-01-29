CC = gcc
CFLAGS = -Wall
SRC_DIR = src
OBJ_DIR = obj
OUT_DIR = out
EXECUTABLE = $(OUT_DIR)/main
H_DIR=-I header

# List all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate object file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
# Default target
all: $(EXECUTABLE)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(H_DIR)

# Link object files to create the executable
$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	$(CC) $^ -o $@

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)

# Phony targets
.PHONY: all clean

print:
	@echo $(EXECUTABLE) "executables"
	@echo $(SRC_FILES) "src files"
	@echo $(OBJ_FILES) "OBJ files"

