// Copyright 2022 finchren
/*
Write a program in C to display the sum of the series [ 1+x+x^2/2!+x^3/3!+....].
Test Data :
Input the value of x :3
Input number of terms : 5
Expected Output :
The sum is : 16.375000

+ 1. Take the input of x
+ 2. Take the input of the number of terms
+ 3.0 Factorial and pow functions
+ 3. Write a function to count the sum
+ 4. Output
5. Invalid input
6. Test
7. Cpplint test
8. Add and push
*/

#include <stdio.h>

int input_x();
int input_n_terms();
int factorial(int number);
int power(int number, int exponent);
double count_sum(int x, int n_terms);
void print_sum(double count_sum_result);

int main() {
    int x = input_x();
    int n_terms = input_n_terms();
    double count_sum_result = count_sum(x, n_terms);
    print_sum(count_sum_result);
    return 0;
}

void print_sum(double count_sum_result) {
    printf("The sum is: %lf", count_sum_result);
}

double count_sum(int x, int n_terms) {
    double result = 1 + x;
    for (int i = 2; i < n_terms; i++) {
        result += power(x, i) / (double) factorial(i);
    }
    return result;
}

int power(int number, int exponent) {
    int result = number;
    for (int i = 2; i <= exponent; i++) {
        result *= number;
    }
    return result;
}

int factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

int input_x() {
    int *x;
    printf("Input the value of x:\n");
    while(!scanf("%d", x)) {
            printf("n/a");
            &x = NULL;
    }
    return *x;
}

int input_n_terms() {
    int n_terms;
    printf("Input number of terms:\n");
    scanf("%d", &n_terms);
    return n_terms;
}
