// Copyright 2022 finchren
/*
Write a program in C to find the sum of the series [ x - x^3 + x^5 + ......].
Test Data :
Input the value of x :2
Input number of terms : 5
Expected Output :
The values of the series:
2
-8
32
-128
512

+ 1. Take the input of the number of terms
+ 2. Write a function to count the sum
+ 3. Output
+ 4. Invalid input
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_x();
int input_n_terms();
int power(int number, int exponent);
void print_result(int x, int n_terms);
void print_invalid();

int main() {
    int x = input_x();
    if (x != 0) {
        int n_terms = input_n_terms();
        if (n_terms > 0) {
            print_result(x, n_terms);
        } else {
        print_invalid();
    }
    } else {
        print_invalid();
    }
    return 0;
}

void print_invalid() {
    printf("n/a");
}

void print_result(int x, int n_terms) {
    // x - x^3 + x^5 + ......
    int result = x, counter = 3;
    printf("The values of the series:\n%d", result);
    for (int i = 2; i <= n_terms; i++) {
        if (i % 2 == 0) {
            result = power(x, counter) * -1;
            printf("\n%d", result);
        } else {
            result = power(x, counter);
            printf("\n%d", result);
        }
        counter += 2;
    }
}

int power(int number, int exponent) {
    int result = number;
    for (int i = 2; i <= exponent; i++) {
        result *= number;
    }
    return result;
}

int input_x() {
    int x;
    char endline;
    printf("Input the value of x:\n");
    if (!scanf("%d%c", &x, &endline) || endline != '\n') {
        x = 0;
    }
    return x;
}

int input_n_terms() {
    int n_terms;
    char endline;
    printf("Input number of terms:\n");
    if (!scanf("%d%c", &n_terms, &endline) || n_terms < 1 || endline != '\n') {
        n_terms = 0;
    }
    return n_terms;
}
