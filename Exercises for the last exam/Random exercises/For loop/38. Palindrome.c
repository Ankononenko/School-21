// Copyright 2022 finchren
/*
Write a program in C to check whether a number is a palindrome or not
Test Data :
Input a number: 121
Expected Output :
121 is a palindrome number.

+ 1. Take input
+ 2 Count the digits, so I know how many to iterate over
+ 2.5 Write pow function
+ 3. Write a function to check if palindrome
+ 4. Invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_number();
int count_digits(int number);
int power(int number, int exponent);
void check_if_palindrome(int number, int how_many_digits);
void print_invalid_input();

int main() {
  int number = input_number();
  if (number > 0) {
    int how_many_digits = count_digits(number);
    check_if_palindrome(number, how_many_digits);
  } else {
    print_invalid_input();
  }
  return 0;
}

void print_invalid_input() {
  printf("n/a");
}

void check_if_palindrome(int number, int how_many_digits) {
  int n_of_iterations = how_many_digits / 2,
  power_of_ten = how_many_digits - 1,
  temp_number = number,
  is_palindrome = how_many_digits / 2,
  palindrome_counter = 0;
  for (int i = 1; i <= n_of_iterations; i++) {
    if ((temp_number % 10) == (temp_number / power(10, power_of_ten))) {
      palindrome_counter++;
      // Here we remove the first number from the left from the temp number
      temp_number -= (temp_number / power(10, power_of_ten)) * power(10, power_of_ten);
      power_of_ten -= 2;
      // Here we remove the first number on the right to keep comparing the numbers
      temp_number /= 10;
    }
  }
  if (palindrome_counter == is_palindrome) {
    printf("%d is a palindrome number", number);
  } else {
      printf("%d isn't a palindrome number\n", number);
    }
}

int power(int number, int exponent) {
  int result = number;
  for (int i = 2; i <= exponent; i++) {
    result *= number;
  }
  return result;
}

int count_digits(int number) {
  int result = 0;
  for (int i = number; i > 0; i /= 10) {
    result++;
  }
  return result;
}

int input_number() {
  int number;
  char endline;
  printf("Input a number:\n");
  if (!scanf("%d%c", &number, &endline) || number < 0 || endline != '\n') {
    number = 0;
  }
  return number;
}
