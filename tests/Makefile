CC = gcc
CFLAGS = -Wall -O2

V1_BIN = ../version_1/my_morse
V2_BIN = ../version_2/my_morse
TEST_BIN = testRunner

all: $(TEST_BIN)

$(TEST_BIN): testRunner.c
	$(CC) $(CFLAGS) testRunner.c -o $(TEST_BIN)
run: all
	@./$(TEST_BIN)
clean:
	rm -f $(TEST_BIN) output.txt
