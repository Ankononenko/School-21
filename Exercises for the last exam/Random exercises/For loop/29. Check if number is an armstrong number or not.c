// Copyright 2022 ficnhren
/*
Write a C program to check whether a given number is an armstrong number or not. Go to the editor
Test Data :
Input a number: 153
// (1^3 + 5^3 + 3^3) = 153
Expected Output :
153 is an Armstrong number.

+ 1. Take input
+ 2.0 Function to count the digits
* 2.2 Function to return pow
+ 2.5 Write function to check the number
+ 2.8 Output the result
+ 3. Invalid input
+ 4. Test
+ 5. Add and push
*/

#include <stdio.h>

int input_number();
int find_the_number_of_digits(int number);
int power(int number, int exponent);
int check_if_armstrong(int number, int number_of_digits);
void print_result(int number, int result);
void print_invalid_input();

int main() {
    int number = input_number();
    if (number != 0) {
        int number_of_digits = find_the_number_of_digits(number);
        int is_armstrong = check_if_armstrong(number, number_of_digits);
        print_result(number, is_armstrong);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_invalid_input() {
    printf("n/a");
}

void print_result(int number, int is_armstrong) {
    if (is_armstrong) {
        printf("%d is an Armstrong number", number);
    } else {
        printf("%d isn't an Armstrong number", number);
    }
}

int check_if_armstrong(int number, int number_of_digits) {
    int sum_result = 0, current_digit, condition_to_return = 0, temp_number = number;
    for (int i = number_of_digits - 1; i > 0; i--) {
        current_digit = temp_number / power(10, i);
        sum_result += power(current_digit, number_of_digits);
        temp_number -= current_digit * power(10, i);
        if (i == 1) {
            current_digit = temp_number / 1;
            sum_result += power(current_digit, number_of_digits);
        }
    }
    if (number == sum_result) {
        condition_to_return = 1;
    }
    return condition_to_return;
}

int power(int number, int exponent) {
    int result = number;
    for (int i = 2; i <= exponent; i++) {
        result *= number;
    }
    return result;
}

int find_the_number_of_digits(int number) {
    int number_of_digits = 0;
    for (int i = number; i > 0; i /= 10) {
        number_of_digits++;
    }
    return number_of_digits;
}

int input_number() {
    int number;
    char endline;
    if(!scanf("%d%c", &number, &endline) || endline != '\n' || number < 1) {
        number = 0;
    }
    return number;
}
