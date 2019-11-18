
TARGET=main

SOURCES=$(wildcard *.c)

OBJS=$(SOURCES:.c=.o)

INC_DIR=../include
CC=gcc

CFLAGS= -g -pedantic -Wall -Werror -Wconversion -ansi $(INC_FLAGS)
CXXFLAGS=$(CFLAGS)

LDFLAGS=-g

.PHONY: clean run gdb 


$(TARGET): $(OBJS)

include .depends
.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)


gdb: $(TARGET)
	gdb -q ./$(TARGET)


