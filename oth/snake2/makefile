CC = gcc
CFLAGS = -Wall -I/usr/include/SDL2 -I/usr/include/SDL2 -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2main -lm -ldl -lpthread -lrt
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
all: create_dirs $(EXECUTABLE)

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

# Create required directories in the current directory
create_dirs:
	@mkdir -p $(CURDIR)/$(SRC_DIR) $(CURDIR)/$(OBJ_DIR) $(CURDIR)/$(OUT_DIR)

