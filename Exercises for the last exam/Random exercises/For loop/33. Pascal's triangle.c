// Copyright 2022 finchren
/*
Write a C program to display Pascal's triangle
 Test Data :
Input number of rows: 5
Expected Output :

        1
      1   1 
    1   2   1 
  1   3   3   1
1   4   6   4   1 

+ 1. Figure out how to count the elements of Pascal's triangle
  The formula is the one that I used one the last exam: 
  factorial(n) / factorial(k)*factorial((n - k))
  Where 'n' is the number of row, starting from 0
  and 'k' is the column number, starts also from 0
+ 2. Take input
+ 3. Write factorial function
+ 3.5 Function to count the formula
+ 4. Write funciton to display the pyramid
+ 5. Spaces inside the pyramid
+ 6. Invalid input
+ 7. Test
+ 8. Cpplint test
+ 9. Add and push
*/

#include <stdio.h>

int input_rows();
int factorial(int number);
int n_choose_k(int n, int k);
void print_pyramid(int rows);
void print_spaces(int number_of_spaces);
void print_invalid_input();

int main() {
  int number_of_rows = input_rows();
  if (number_of_rows > 0) {
    print_pyramid(number_of_rows);
  } else {
    print_invalid_input();
  }
  return 0;
}

void print_invalid_input() {
  printf("n/a");
}

void print_spaces(int number_of_spaces) {
  for (int i = 1; i <= number_of_spaces; i++) {
    printf(" ");
  }
}

void print_pyramid(int rows) {
  int counter_for_rows = 1;
  // First for loop in the row of the pyramid
  for (int n = 0; n < rows; n++) {
    print_spaces(rows - counter_for_rows);
    // Second for loop in the column of the pyramid
    for (int k = 0; k < counter_for_rows; k++) {
      printf("%d ", n_choose_k(n, k));
    }
    counter_for_rows++;
    printf("\n");
  }
}

int n_choose_k(int n, int k) {
  int result = 0;
  result = factorial(n) / (factorial(k) * factorial((n - k)));
  return result;
}

int factorial(int number) {
  int result = 1;
  for (int i = 2; i <= number; i++) {
    result *= i;
  }
  return result;
}

int input_rows() {
  int number_of_rows;
  char endline;
  if (!scanf("%d%c", &number_of_rows, &endline) || endline != '\n' || number_of_rows < 1) {
    number_of_rows = 0;
  }
  return number_of_rows;
}
