// Copyright 2022 ficnhren
/* 
Write a program in C to find LCM of any two numbers using HCF
Test Data :
Input 1st number for LCM: 15
Input 2nd number for LCM: 20
Expected Output :
The LCM of 15 and 20 is : 60

+ 1. Figure out what LCM is = It is lowest common multiple value
    Ex: LCM of 4 and 6
    4 8 12 16 20 24 28 32
    6 12 18 24 30 36 42 48
    The LCM is 12
+ 2. Figure out how to use the HCF to find LCM - Multiply the absolute value of fist and second number and divide it by HCF
    Ex: HCF of 4 and 6 is 2
    4 * 6 / 2 = 24 / 12
    Ex: HCF of 15 and 20 is 5
    15 * 20 / 5 = 60
+ 3. Take input
+ 4. Invalid input - If one of the numbers is zero - we print out n/a, since division of integers by zero is undefined
+ 5.0 Write function to find HCF
+ 5.5 Find the LCM
+ 6. Output the found value
+ 7. Test
+ 8. Cpplint test
+ 9. Add and push
*/

#include <stdio.h>
// I use math.h to find the remainder of a double number. It is used in my code to work around invalid input
#include <math.h>

// Here I use double for first and second to work around the invalid input
double input_first();
double input_second();
void print_invalid_input();
int find_hcf(int first, int second);
int find_lcm(int first, int second, int hcf);
void print_lcm(int first, int second, int lcm);
void test(int first, int second, int expected, int test_number);

int main() {
    double first = input_first();
    double first_remainder = remainder(first, 1);
    if (first_remainder == 0.0) {
        double second = input_second();
        double second_remainder = remainder(second, 1);
        if (second_remainder == 0.0) {
            int int_first = (int)first;
            int int_second = (int)second;
            int hcf = find_hcf(int_first, int_second);
            int lcm = find_lcm(int_first, int_second, hcf);
            print_lcm(int_first, int_second, lcm);
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    // Here go tests
    // int first, int second, int expected, int test_number
    // Test - normal values
    test(4, 6, 12, 1);
    // Test - max values
    test(2147483646, 1073741823, 2147483646, 2);
    // Test - min values
    test(-2147483646, -1073741823, 2147483646, 3);
    // Test - ones
    test(1, 1, 1, 4);
    return 0;
}

void test(int first, int second, int lcm_expected, int test_number) {
    int hcf = find_hcf(first, second);
    int lcm_actual = find_lcm(first, second, hcf);
    if (lcm_actual == lcm_expected) {
        printf("Test #%d: first = %d, second = %d, lcm_expected = %d, lcm_actual = %d\n",
        test_number, first, second, lcm_expected, lcm_actual);
        printf("Success\n");
    } else {
        printf("Test #%d: first = %d, second = %d, lcm_expected = %d, lcm_actual = %d\n",
        test_number, first, second, lcm_expected, lcm_actual);
        printf("Failed\n");
    }
}

void print_lcm(int first, int second, int lcm) {
    printf("The LCM of %d and %d is: %d\n", first, second, lcm);
}

int find_lcm(int first, int second, int hcf) {
    long long int multiply_first_second = (long long int)first * (long long int)second;
    int lcm;
    if (multiply_first_second < 0) {
        multiply_first_second *= -1;
    }
    lcm = multiply_first_second / hcf;
    return lcm;
}

int find_hcf(int first, int second) {
    int hcf;
    if (first < 0) {
        first *= -1;
    }
    if (second < 0) {
        second *= -1;
    }
    for (int i = first; i > 0; --i) {
        if (first % i == 0 && second % i == 0) {
            hcf = i;
            break;
        }
    }
    return hcf;
}

void print_invalid_input() {
    printf("n/a");
}

double input_first() {
    double first;
    char endline;
    printf("Input 1st number for LCM:\n");
    if (!scanf("%lf%c", &first, &endline) || endline != '\n' || first == 0) {
        // This is used to sort out the invalid input
        first = 0.666;
    }
    return first;
}

double input_second() {
    double second;
    char endline;
    printf("Input 2nd number for LCM:\n");
    if (!scanf("%lf%c", &second, &endline) || endline != '\n' || second == 0) {
        second = 0.666;
    }
    return second;
}
