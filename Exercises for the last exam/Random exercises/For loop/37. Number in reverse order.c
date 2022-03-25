// Copyright 2022 finchren
/*
Write a program in C to display the number in reverse order.
Test Data :
Input a number: 12345
Expected Output :
The number in reverse order is : 54321

+ 1. Take input
+ 2.0 Count the digits, so I know how many to reverse
+ 2. Write a function to display the reversed number
+ 3. Invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int input_number();
int count_digits(int number);
void reverse_number(int number, int n_of_digits);
void print_invalid_input();

int main() {
  int number = input_number();
  if (number >= 0) {
    int n_of_digits = count_digits(number);
    reverse_number(number, n_of_digits);
  } else {
    print_invalid_input();
  }
  return 0;
}

void print_invalid_input() {
  printf("n/a");
}

void reverse_number(int number, int n_of_digits) {
  int temp_number = number, result;
  printf("%d", number % 10);
  for (int i = 1; i <= n_of_digits; i++) {
    temp_number /= 10;
    result = temp_number % 10;
    if (result > 0) {
      printf("%d", result);
    }
  }
}

int count_digits(int number) {
  int how_many_digits = 0;
  for (int i = number; i > 0; i /= 10) {
    how_many_digits++;
  }
  return how_many_digits;
}

int input_number() {
  int number;
  char endline;
  if (!scanf("%d%c", &number, &endline) || number < 1 || endline != '\n') {
    number = -1;
  }
  return number;
}
