// Copyright 2022 finchren
/*
Write a program in C to display the first n terms of Fibonacci series
Fibonacci series 0 1 2 3 5 8 13 .....
Test Data :
Input number of terms to display : 10
Expected Output :
Here is the Fibonacci series upto to 10 terms :
0 1 1 2 3 5 8 13 21 34

+ 1. Take input
+ 2. Write a function to find Fibonacci series
+ 3. Display output in range of n terms
+ 4. Invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_n_terms();
int find_fibonacci(int first, int second);
void print_result(int n_terms);
void invalid_input();

int main() {
  int n_terms = input_n_terms();
  if (n_terms >= 1) {
    print_result(n_terms);
  } else {
    invalid_input();
  }
  return 0;
}

void invalid_input() {
  printf("n/a");
}

void print_result(int n_terms) {
  int first = 0, second = 1;
  printf("Here is the Fibonacci series upto to 10 terms:\n");
  if (n_terms == 1) {
    printf("0");
  } else {
      for (int terms = 2; terms <= n_terms; terms += 2) {
        printf("%d %d ", first, second);
        first = find_fibonacci(first, second);
        second = find_fibonacci(first, second);
        if (terms + 1 == n_terms) {
          printf("%d", first);
        }
      }
    }
}

int find_fibonacci(int first, int second) {
  int result = first + second;
  return result;
}

int input_n_terms() {
  int n_terms;
  char endline;
  printf("Input number of terms to display:\n");
  if (!scanf("%d%c", &n_terms, &endline) || n_terms < 1 || endline != '\n') {
    n_terms = 0;
  }
  return n_terms;
}
