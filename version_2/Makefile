CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = src/my_morse.c
TARGET = my_morse
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET) output.txt
