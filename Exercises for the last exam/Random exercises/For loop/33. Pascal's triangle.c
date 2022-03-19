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
4. Write funciton to display the pyramid
5. Spaces inside the pyramid
6. Invalid input
7. Test
8. Cpplint test
9. Add and push
*/

#include <stdio.h>

int input_rows();
int factorial(int number);
int n_choose_k(int n, int k);

int main() {
  int number_of_rows = input_rows();
  
  return 0;
}

int n_choose_k(int n, int k) {
  int result = factorial(n) / factorial(k) * factorial((n - k));
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
  scanf("%d", &number_of_rows);
  return number_of_rows;
}
