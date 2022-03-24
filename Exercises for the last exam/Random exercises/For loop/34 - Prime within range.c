// Copyright 2022 finchren
/*
Write a program in C to find the prime numbers within a range of numbers
Test Data :
Input starting number of range: 1
Input ending number of range : 50
Expected Output :
The prime number between 1 and 50 are :
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

+ 1. Take input
+ 2. Write a function to find prime
+ 3. Display output in range
+ 4. Invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_start_range();
int input_end_range(int start);
int is_prime(int number);
void print_prime_range(int start, int end);
void print_invalid_input();

int main() {
  int start = input_start_range();
  if (start != 0) {
    int end = input_end_range(start);
    if (end != 0) {
      print_prime_range(start, end);
    } else {
    print_invalid_input();
  }
  } else {
    print_invalid_input();
  }
  return 0;
}

void print_invalid_input() {
  printf("n/a");
}

void print_prime_range(int start, int end) {
  printf("The prime number between %d and %d are:\n", start, end);
  for (int i = start; i <= end; i++) {
    if (is_prime(i) == 2) {
      printf("%d ", i);
    }
  }
}

int is_prime(int number) {
  int division_counter = 0;
  for (int start = 1; start <= number; start++) {
    if (number % start == 0) {
      division_counter++;
    }
  }
  return division_counter;
}

int input_start_range() {
  int start;
  char endline;
  printf("Input starting number of range:\n");
  if (!scanf("%d%c", &start, &endline) || start < 1 || endline != '\n') {
    start = 0;
  }
  return start;
}

int input_end_range(int start) {
  int end;
  char endline;
  printf("Input ending number of range:\n");
  if (!scanf("%d%c", &end, &endline) || end < start || endline != '\n') {
    end = 0;
  }
  return end;
}
