PROG = Day1
CC = gcc
CFLAGS = -g -Wall -Werror
DEPS = puzzle.h
SRC = main.c  # Add the source file to the list

# Use wildcard function to automatically find all .c files in the directory
SRCS = $(wildcard *.c)

# Use patsubst to replace .c with .o in the list of source files
OBJ = $(patsubst %.c, %.o, $(SRCS))

# The default target is 'all'
all: $(PROG)

# Pattern rule to build .o files from corresponding .c files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# The final target is the executable, which depends on all object files
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
