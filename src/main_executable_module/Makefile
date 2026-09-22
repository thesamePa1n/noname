CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm

TARGET = ../../build/Quest_3

SOURCES = main_executable_module.c \
          ../data_libs/data_io.c \
          ../data_libs/data_stat.c \
          ../data_module/data_process.c \
          ../yet_another_decision_module/decision.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p ../../build
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

rebuild: clean all