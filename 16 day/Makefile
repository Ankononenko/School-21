# Copyright 2022 finchren
# Set build folder at the root of repository 
BUILDDIR=../build/

CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

all: clean strlen_tests strcmp_tests strcpy_tests

strlen_tests: s21_string.o s21_string_test_strlen.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILDDIR)Quest_1

s21_string_test_strlen.o: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_1

strcmp_tests: s21_string.o s21_string_test_strcmp.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILDDIR)Quest_2

s21_string_test_strcmp.o: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_2

strcpy_tests: s21_string.o s21_string_test_strcpy.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILDDIR)Quest_3

s21_string_test_strcpy.o: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -D Quest_2

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

rebuild:
	clean strlen_tests

clean: 
	rm -f *.o
	rm -f $(BUILDDIR)Q*