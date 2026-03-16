CC = gcc
CFLAGS = -Wall -O2

V1_BIN = ../version_1/my_morse
V2_BIN = ../version_2/my_morse
TEST_BIN = test

all: $(TEST_BIN)

$(TEST_BIN): test.c
	$(CC) $(CFLAGS) test.c -o $(TEST_BIN)
run: all
	@./$(TEST_BIN)
clean:
	rm -f $(TEST_BIN) output.txt
