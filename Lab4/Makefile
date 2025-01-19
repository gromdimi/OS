# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Executable names
EXECUTABLES = example1 example2 example3 example4 example5

# Default target
all: $(EXECUTABLES)

# Targets for each executable
example1: example1.c
	$(CC) $(CFLAGS) -o $@ $<

example2: example2.c
	$(CC) $(CFLAGS) -o $@ $<

example3: example3.c
	$(CC) $(CFLAGS) -o $@ $<

example4: example4.c
	$(CC) $(CFLAGS) -o $@ $<

example5: example5.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove compiled files
clean:
	rm -f $(EXECUTABLES)

