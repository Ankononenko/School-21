// Copyright 2022 finchren
/*
Write a C program to find HCF (Highest Common Factor) of two numbers
Test Data :
Input 1st number for HCF: 24
Input 2nd number for HCF: 28
Expected Output :
HCF of 24 and 28 is : 4

+ 1. Input numbers
+ 2. Find the HCF
+ 3. Print it out
+ 3.5 Invalid input
+ 4. Test
+ 5. Cpplint test
6. Add and push
*/

#include <stdio.h>

int input_first();
int input_second();
int find_hcf(int first, int second);
void print_invalid_input();
void print_hcf(int hcf);
void test(int first, int second, int hcf_expected, int test_num);

int main() {
    int first = input_first();
    if (first > 0) {
        int second = input_second();
        if (second > 0) {
            int hcf = find_hcf(first, second);
            print_hcf(hcf);
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    // Here we run the tests
    // Test 1 - mininum possible values
    test(1, 1, 1, 1);
    // Test 2 - maximum possible values
    test(2147483647, 2147483647, 2147483647, 2);
    // Test 3 - normal value
    test(35, 7, 7, 3);
    // Test 4 - normal value
    test(1, 35, 1, 4);
    // Test 5 - normal value - zero to retur
    test(0, 99, 0, 5);
    // Test 6 - prime number test
    test(127, 251, 1, 6);
    // Test 7 - double test
    test(0.5, 9.9, 0, 7);
    return 0;
}

void test(int first, int second, int hcf_expected, int test_num) {
    int hcf_actual = find_hcf(first, second);
    if (hcf_actual == hcf_expected) {
        printf("Test #%d: first = %d, second = %d, hcf_expected = %d, hcf_actual = %d\n",
        test_num, first, second, hcf_expected, hcf_actual);
        printf("Test passed\n");
    } else {
        printf("Test #%d: first = %d, second = %d, hcf_expected = %d, hcf_actual = %d\n",
        test_num, first, second, hcf_expected, hcf_actual);
        printf("Test Failed\n");
    }
}

void print_hcf(int hcf) {
    printf("%d\n", hcf);
}

void print_invalid_input() {
    printf("n/a");
}

int find_hcf(int first, int second) {
    int result;
    for (int i = first; i >= 1; i--) {
        if (first % i == 0 && second % i == 0) {
            result = i;
            break;
        }
    }
    return result;
}

int input_first() {
    int first;
    char endline;
    printf("Input 1st number for HCF:\n");
    if (!scanf("%d%c", &first, &endline) || first < 1 || endline != '\n') {
        first = 0;
    }
    return first;
}
int input_second() {
    int second;
    char endline;
    printf("Input 2nd number for HCF:\n");
    if (!scanf("%d%c", &second, &endline) || second < 1 || endline != '\n') {
        second = 0;
    }
    return second;
}
