CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/src/%.o)
TARGET = controleAerio

all: $(TARGET)

build/src/%.o: src/%.c
	mkdir -p build/src
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -rf build $(TARGET)
