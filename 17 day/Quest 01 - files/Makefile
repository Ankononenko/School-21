# Copyright 2022 finchren
# Set build folder at the root of repository 
BUILDDIR=../build/

CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

all: clean door_struct

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(BUILDDIR)Quest_1

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

rebuild:
	clean door_struct

clean: 
	rm -f *.o
	rm -f $(BUILDDIR)Q*