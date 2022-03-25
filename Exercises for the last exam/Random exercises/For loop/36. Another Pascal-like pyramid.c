// Copyright 2022 finchren
/*
Write a program in C to display the such a pattern for n number of rows
using a number which will start with the number 1 and the first 
and a last number of each row will be 1

  1
 121
12321

+ 1. Take input
+ 2. Write a function to display the rows
+ 3. Spaces
+ 4. Invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_n_rows();
void print_pyramid(int n_rows);
void print_spaces(int n_rows);
void print_invalid_input();

int main() {
  int n_rows = input_n_rows();
  if (n_rows >=1) {
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
  for (int i = 1; i <= n_rows; i++) {
    printf(" ");
    }
}

void print_pyramid(int n_rows) {
  int temp_rows_for_spaces = n_rows - 1;
  for (int n_of_elements_in_row = 1; n_of_elements_in_row <= n_rows; n_of_elements_in_row++) {
    print_spaces(temp_rows_for_spaces);
    temp_rows_for_spaces--;
    for (int elements_up = 1; elements_up <= n_of_elements_in_row; elements_up++) {
      printf("%d ", elements_up);
      if (elements_up == n_of_elements_in_row && elements_up != 1) {
        for (int elements_down = elements_up - 1; elements_down >= 1; elements_down--) {
          printf("%d ", elements_down);
        }
      }
    }
    printf("\n");
  }
}

int input_n_rows() {
  int n_rows;
  char endline;
  if (!scanf("%d%c", &n_rows, &endline) || n_rows < 1 || endline != '\n') {
    n_rows = 0;
  }
  return n_rows;
}
