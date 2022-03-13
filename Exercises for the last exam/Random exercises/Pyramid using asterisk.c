// Copyright 2022 ficnhren
/*
Write a program in C to display the pattern like a pyramid using asterisk and each row contain an odd number of asterisks

   *
  ***
 *****

 + 1. Take input for a number of rows to be created
 + 2. Create a function for output of the pyramid
 + 3. Invalid input
 + 4. Test
 + 5. Cpplint test
 6. Add and push
*/

#include <stdio.h>

int input();
void print_pyramid(int rows);
void print_spaces(int number_of_spaces);
void print_stars(int number_of_stars);
void print_newline();
void print_invalid_input();

int main() {
    int rows = input();
    if (rows > 0) {
        print_pyramid(rows);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_invalid_input() {
    printf("n/a");
}

void print_pyramid(int rows) {
    int stars = 1;
    for (int spaces = rows; spaces > 0; spaces--) {
        print_spaces(spaces);
        print_stars(stars);
        print_newline();
        stars += 2;
    }
}

void print_newline() {
    printf("\n");
}

void print_stars(int number_of_stars) {
    for (int i = number_of_stars; i > 0; i--) {
        printf("*");
    }
}

void print_spaces(int number_of_spaces) {
    for (int i = number_of_spaces; i > 0; i--) {
        printf(" ");
    }
}

int input() {
    int rows;
    char endline;
    if (!scanf("%d%c", &rows, &endline) || (endline != '\n')) {
        rows = 0;
    }
    return rows;
}
