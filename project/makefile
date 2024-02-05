CC = gcc
CFLAGS = -Wall
GTK_FLAGS= -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/harfbuzz -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -pthread -L/usr/lib/x86_64-linux-gnu -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0

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
	$(CC) $(CFLAGS) -c $< -o $@ $(H_DIR) $(GTK_FLAGS)

# Link object files to create the executable
$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(OUT_DIR)
	$(CC) $^ -o $@ $(GTK_FLAGS)

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

