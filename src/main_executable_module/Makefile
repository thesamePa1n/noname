CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm

BUILD = ../../build
TARGET = $(BUILD)/Quest_3
TARGET_STATIC = $(BUILD)/Quest_4
STATIC_LIB = $(BUILD)/data_stat.a
STATIC_OBJ = $(BUILD)/data_stat.o

SOURCES = main_executable_module.c \
          ../data_libs/data_io.c \
          ../data_libs/data_stat.c \
          ../data_module/data_process.c \
          ../yet_another_decision_module/decision.c

SOURCES_STATIC = main_executable_module.c \
                 ../data_libs/data_io.c \
                 ../data_module/data_process.c \
                 ../yet_another_decision_module/decision.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

data_stat.a: $(STATIC_LIB)

$(STATIC_LIB): $(STATIC_OBJ)
	ar rcs $(STATIC_LIB) $(STATIC_OBJ)

$(STATIC_OBJ): ../data_libs/data_stat.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o $(STATIC_OBJ)

build_with_static: $(STATIC_LIB)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(SOURCES_STATIC) $(STATIC_LIB) -o $(TARGET_STATIC) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(TARGET_STATIC) $(STATIC_LIB) $(STATIC_OBJ)

rebuild: clean all