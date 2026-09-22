CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../../build
TARGET = $(BUILD)/Quest_8

all: strcpy

strcpy: $(TARGET)

$(TARGET): s21_string.c s21_string.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c s21_string.c -o $(BUILD)/s21_string.o
	$(CC) $(CFLAGS) $(BUILD)/s21_string.o -o $(TARGET)

clean:
	rm -f $(TARGET) $(BUILD)/s21_string.o

rebuild: clean strcpy