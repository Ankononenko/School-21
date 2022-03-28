// Copyright 2022 finchren
/* 
Write a program in C to find the sum of the series [ 1-X^2/2!+X^4/4!- .........]
Test Data :
Input the Value of x :2
Input the number of terms : 5
Expected Output :
the sum = -0.415873
Number of terms = 5
value of x = 2.000000
+ 1. Take the input of x and number of terms
+ 2. Write factorial function
+ 2.1 Write pow function
2.3 Write function for counting the sum
+ 2.5 Display the sum, number of term and value of x
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
+ 7. Rework considering the Misha's comments
+ 8. Fix the error in the code
+ 9. Add and push fixed and reworked version
*/

#include <stdio.h>

int input_value_of_x();
int input_number_of_terms();
int factorial(int number);
int power(int base, int exponent);
double count_sum(int x, int number_of_terms);
void print_sum(double sum);
void print_number_of_terms(int number_of_terms);
void print_value_of_x(int x);
void print_invalid_input();

int main() {
    int x = input_value_of_x();
    if (x > 0) {
        int number_of_terms = input_number_of_terms();
        if (number_of_terms > 0) {
            print_sum(count_sum(x, number_of_terms));
            print_number_of_terms(number_of_terms);
            print_value_of_x(x);
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

void print_value_of_x(int x) {
    printf("Value of x = %f\n", (double)x);
}

void print_number_of_terms(int number_of_terms) {
    printf("Number of terms = %d\n", number_of_terms);
}

void print_sum(double sum) {
    printf("The sum = %f\n", sum);
}

double count_sum(int x, int number_of_terms) {
    double sum = 1.0;
    int multiplier = 2, sign = -1;
    for (int i = 1; i < number_of_terms; ++i) {
        sum += sign * power(x, multiplier) / (double)factorial(multiplier);
        multiplier += 2;
        sign *= (-1);
    }
    return sum;
}

int power(int base, int exponent) {
    int result = base;
    for (int i = 2; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}

int input_number_of_terms() {
    int number_of_terms;
    char endline;
    printf("Input the number of terms:\n");
    if (!scanf("%d%c", &number_of_terms, &endline) || (endline != '\n') || (number_of_terms <= 0)) {
        number_of_terms = 0;
    }
    return number_of_terms;
}

int input_value_of_x() {
    int x;
    char endline;
    printf("Input the value of x:\n");
    if (!scanf("%d%c", &x, &endline) || endline != '\n') {
        x = 0;
    }
    return x;
}

int factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; ++i) {
        result *= i;
    }
    return result;
}
