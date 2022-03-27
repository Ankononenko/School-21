// Copyright 2022 ficnhren
/*
Write a C Program to display the pattern like pyramid using the alphabet

        A
      A B A 
    A B C B A
  A B C D C B A 

+ 1. Take input
+ 2. Figure out how to iterate through the letters = %d, 'A' == 65, %c, 65 == A
+ 3. Print pyramid
+ 4. Spaces
+ 5. Invalid input
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>

int input_n_rows();
void print_pyramid(int n_rows);
void print_spaces(int n_rows);
void print_invalid_input();

int main() {
    int n_rows = input_n_rows();
    if (n_rows > 0) {
        print_pyramid(n_rows);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_invalid_input() {
    printf("n/a");
}

void print_spaces(int n_rows) {
    for (int i = n_rows; i > 0; i--) {
        printf(" ");
    }
}

void print_pyramid(int n_rows) {
    // temp_n_rows is used to print out the spaces
    // We cannot change the main variable, so we use a temperary one
    // "+ (n_rows - 1)" is used to account for the spaces in between the letters
    int capital_letter_num_value, temp_n_rows = n_rows + (n_rows - 1);
    // First for loop is used to iterate over the rows
    for (int i_rows = 0; i_rows < n_rows; i_rows++) {
        capital_letter_num_value = 65;
        print_spaces(temp_n_rows);
        temp_n_rows -= 2;
        // Second for loop is used to go up the alphabet
        for (int i_row_element_up = 0; i_row_element_up <= i_rows; i_row_element_up++) {
            printf("%c ", capital_letter_num_value);
            capital_letter_num_value++;
            }
        capital_letter_num_value--;
        // Second for loop is used to go down the alphabet
        for (int i_row_element_down = i_rows; i_row_element_down > 0; i_row_element_down--) {
            capital_letter_num_value--;
            printf("%c ", capital_letter_num_value);
        }
        printf("\n");
    }
}

int input_n_rows() {
    int n_rows;
    char endline;
    printf("Input how many rows do you wish for the pyramid of letters to have:\n");
    if (!scanf("%d%c", &n_rows, &endline) || n_rows < 1 || endline != '\n') {
        n_rows = 0;
    }
    return n_rows;
}
