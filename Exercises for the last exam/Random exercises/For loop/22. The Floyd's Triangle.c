// Copyright 2022 finchren

/*
Write a program in C to print the Floyd's Triangle

1 
01
101 
0101 
10101

+ 0. Take input for the amount of rows to be printed
+ 1. Write for loop to print out the triangle
+ 2.0 Invalid input
+ 2.5 Test
+ 3. Cpplint test
+ 4. Add and push
*/

#include <stdio.h>

int input_number_of_rows();
void print_floyds_triagle(int rows);
void print_invalid_input();

int main() {
    int rows = input_number_of_rows();
    if (rows > 0) {
        print_floyds_triagle(rows);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_invalid_input() {
    printf("n/a");
}

void print_floyds_triagle(int rows) {
    int one = 1, zero = 0;
    for (int row_counter = 1; row_counter <= rows; row_counter++) {
        if (row_counter % 2 != 0) {
            for (int column_counter_odd = 1; column_counter_odd <= row_counter; column_counter_odd++) {
                if (column_counter_odd % 2 != 0) {
                    printf("%d", one);
                } else {
                    printf("%d", zero);
                }
            }
        } else {
            for (int column_counter_even = 1; column_counter_even <= row_counter; column_counter_even++) {
            if (column_counter_even % 2 == 0) {
                printf("%d", one);
            } else {
                printf("%d", zero);
            }
        }
        }
        printf("\n");
    }
}

int input_number_of_rows() {
    int rows;
    char endline;
    if (!scanf("%d%c", &rows, &endline) || endline != '\n') {
        rows = 0;
    }
    return rows;
}
