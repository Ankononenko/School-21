# Copyright 2022 finchren
# Set build folder at the root of repository 
BUILDDIR=../build/

CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

all: Quest_1 clean

Quest_1: s21_string.o s21_string_test.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILDDIR)Quest_1

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

s21_string_test.o: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c

rebuild:
	clean Quest_1

clean: 
	rm -f *.o