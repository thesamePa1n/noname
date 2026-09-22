CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../../build
TARGET = $(BUILD)/Quest_13

all: text_processor

text_processor: $(TARGET)

$(TARGET): text_processor.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) text_processor.c -o $(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean text_processor