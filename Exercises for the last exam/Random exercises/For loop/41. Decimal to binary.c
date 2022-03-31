// Copyright 2022 finchren
/*
Write a program in C to convert a decimal number into binary without using an array
Test Data :
Input a decimal number: 25
Binary number equivalent to said decimal number is: 11001

Input a decimal number: -25
Binary number equivalent to said decimal number is: -11001

+ 1. Take the input of decimal number
+ 2. Figure out how to convert decimal to binary: 
26 -> 16 08 04 02 01
26 == 1  1  0  1  0 (16 + 8 + 2 == 26)
25 -> 16 08 04 02 01
25 == 1  1  0  0  1 (16 + 8 + 1 == 25)
32768 16384 8192 4096 2048  1024 512 256 128 64 32 16 8 4 2 1
+ 2. Write the function to convert number to binary
+ 2.6 Print out the result
+ 3. Work around invalid input
+ 3.5 Decompose main a little bit
+ 4. Test:
+ 4.1 Fix the mistake where the max input number allowed
+ 4.2 Fix negative numbers
+ 5. Cpplint test
6. Add and push
*/

#include <stdio.h>
// Math import to work around invalid input - I need to find remainder from a double
#include <math.h>

// Double input number is used to get rid of invalid input
double input_number();
void convert_to_binary(int number, int division_by_two, int is_negative);
void print_invalid_input();
void run_convert_to_binary(int number, double number_remainder, int division_by_two, int is_negative);
int division_by_two(int number);
int power(int bast, int exponent);
int negative_number_convert(int number);
int is_negative_check(int number);

int main() {
    double number = input_number();
    int is_negative = is_negative_check(number);
    // Work around negative number
    number = negative_number_convert(number);
    // Value for invalid input
    double number_remainder = remainder(number, 1);
    int division_by_two_result = division_by_two(number);
    run_convert_to_binary(number, number_remainder, division_by_two_result, is_negative);
    return 0;
}

int is_negative_check(int number) {
    int is_negative = 0;
    if (number < 0) {
        is_negative = 1;
    }
    return is_negative;
}

int negative_number_convert(int number) {
    if (number < 0) {
        number *= -1;
    }
    return number;
}

int power(int base, int exponent) {
    int result = base;
    for (int i = 2; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}

int division_by_two(int number) {
    int division_by_two = 0;
    for (int i = number; i > 0; i /= 2) {
        ++division_by_two;
    }
    return division_by_two;
}

void run_convert_to_binary(int number, double number_remainder, int division_by_two, int is_negative) {
    if (number_remainder == 0) {
        convert_to_binary(number, division_by_two, is_negative);
    } else {
        print_invalid_input();
    }
}

void print_invalid_input() {
    printf("n/a");
}

void convert_to_binary(int number, int division_by_two, int is_negative) {
    int base = 2, exponent = division_by_two - 1;
    printf("Binary number equivalent to said decimal number is:\n");
    // Work around negative input
    if (is_negative) {
        printf("-");
        }
    // Binary output
    for (int i = 1; i < division_by_two; ++i) {
        if (number / power(base, exponent)) {
            printf("1");
            number -= power(base, exponent);
        } else {
            printf("0");
        }
        --exponent;
    }
    // If case to work with the last number in the series. For loop goes through powers of two
    if (number == 1) {
        printf("1");
    } else {
        printf("0");
    }
}

double input_number() {
    double number;
    char endline;
    printf("Input a decimal number:\n");
    if (!scanf("%lf%c", &number, &endline) || endline != '\n') {
        number = 6.6;
    }
    return number;
}
