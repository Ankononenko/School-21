// Copyright 2022 finchren
/* 
Write a program in C to find the sum of the series [ 1-X^2/2!+X^4/4!- .........]. Go to the editor
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
+ 2.3 Write function for counting the sum
+ 2.5 Display the sum, number of term and value of x
3. Work around invalid input
4. Test
5. Cpplint test
6. Add and push
*/

#include <stdio.h>

float input_value_of_x();
float input_number_of_terms();
float factorial(float number);
float power(float number, float power);
float count_sum(float x, float number_of_terms);
void print_sum(float sum);
void print_number_of_terms(float number_of_terms);
void print_value_of_x(float x);

int main() {
    float x = input_value_of_x();
    float number_of_terms = input_number_of_terms();
    print_sum(count_sum(x, number_of_terms));
    print_number_of_terms(number_of_terms);
    print_value_of_x(x);
    return 0;
}

void print_value_of_x(float x) {
    printf("Value of x = %f\n", x);
}

void print_number_of_terms(float number_of_terms) {
    printf("Number of terms = %d\n", (int) number_of_terms);
}

void print_sum(float sum) {
    printf("The sum = %f\n", sum);
}

float count_sum(float x, float number_of_terms) {
    float sum = 1.0, multiplier = 2.0;
    for (int i = 1; i <= number_of_terms; i++) {
        if (i % 2 == 0) {
            sum += power(x, multiplier) / factorial(multiplier);
            multiplier += 2.0;
        } else if (i % 2 != 0) {
            sum -= power(x, multiplier) / factorial(multiplier);
            multiplier += 2.0;
        }
    }
    return sum;
}

float power(float number, float power) {
    float result = number;
    for (float i = 2; i <= power; i++) {
        result *= number;
    }
    return result;
}

float input_number_of_terms() {
    float number_of_terms;
    printf("Input the number of terms:\n");
    scanf("%f", &number_of_terms);
    return number_of_terms;
}

float input_value_of_x() {
    float x;
    printf("Input the value of x:\n");
    scanf("%f", &x);
    return x;
}

float factorial(float number) {
    float result = 1.0;
    for (float i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}
