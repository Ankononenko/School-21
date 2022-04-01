// Copyright 2022 ficnhren
/*
Write a program in C to find LCM of any two numbers
Test Data :
Input 1st number for LCM: 15
Input 2nd number for LCM: 20
Expected Output :
The LCM of 15 and 20 is : 60

+ 1. Take input
+ 2. Invalid input
+ 3. Write function to find LCM
+ 4. Output
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/ 

#include <stdio.h>

int input_first();
int input_second();
void print_invalid_input();
int find_lcm(int first, int second);
void print_lcm(int first, int second, int lcm);
void test(int first, int second, int expected, int test_number);

int main() {
    int first = input_first();
    if (first != 0) {
        int second = input_second();
        if (second != 0) {
            int lcm = find_lcm(first, second);
            print_lcm(first, second, lcm);
        } else {
        print_invalid_input();
    }
    } else {
        print_invalid_input();
    }
    // Test for normal values
    test(15, 20, 60, 1);
    // Test big primal numbers
    test(7919, 7907, 62615533, 2);
    // Test min numbers
    test(1, 1, 1, 3);
    // Zeros
    test(0, 0, 0, 4);
    // Max number
    test(46340, 46339, 2147349260, 5);
    return 0;
}

void test(int first, int second, int lcm_expected, int test_number) {
    int lcm_actual = find_lcm(first, second);
    if (lcm_expected == lcm_actual) {
        printf("Test #%d: first = %d, second = %d, lcm_actual = %d, lcm_expected = %d\nSuccess\n",
        test_number, first, second, lcm_actual, lcm_expected);
    } else {
        printf("Test #%d: first = %d, second = %d, lcm_actual = %d, lcm_expected = %d\nFailed\n",
        test_number, first, second, lcm_actual, lcm_expected);
    }
}

void print_lcm(int first, int second, int lcm) {
    printf("The LCM of %d and %d is: %d\n", first, second, lcm);
}

int find_lcm(int first, int second) {
    int lcm, product_first_second = first * second, temp_first = first, temp_second = second;
    for (int i = 0; i <= product_first_second; i++) {
        if (temp_first > temp_second) {
            temp_second += second;
        }
        if (temp_first < temp_second) {
            temp_first += first;
        }
        if (temp_first == temp_second) {
            lcm = temp_first;
            break;
        }
    }
    return lcm;
}

void print_invalid_input() {
    printf("n/a");
}

int input_first() {
    int first;
    char endline;
    printf("Input 1st number for LCM:\n");
    if (!scanf("%d%c", &first, &endline) || endline != '\n') {
        first = 0;
    }
    return first;
}

int input_second() {
    int second;
    char endline;
    printf("Input 2nd number for LCM:\n");
    if (!scanf("%d%c", &second, &endline) || endline != '\n') {
        second = 0;
    }
    return second;
}
