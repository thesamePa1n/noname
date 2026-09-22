CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../../build
TARGET = $(BUILD)/Quest_7

all: strcmp_tests

strcmp_tests: $(TARGET)

$(TARGET): s21_string.c s21_string_test.c s21_string.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean strcmp_tests