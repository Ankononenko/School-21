// Copyright 2022 finchren
/*
Write a program in C to convert a decimal number into binary without using an array
Test Data :
Input a decimal number: 25
Binary number equivalent to said decimal number is: 0000000000011001

+ 1. Take the input of decimal number
+ 2. Figure out how to convert decimal to binary: 
26 -> 16 08 04 02 01
26 == 1  1  0  1  0 (16 + 8 + 2 == 26)
25 -> 16 08 04 02 01
25 == 1  1  0  0  1 (16 + 8 + 1 == 25)
^ That is regular binary. Now we need to figure out how to use 2's complement
Turns out it's just 16 places for numbers, where empty spaces are filled with zeros.
Ex: 26 == 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0
32768 16384 8192 4096 2048  1024 512 256 128 64 32 16 8 4 2 1
+ 2. Write the function to convert number to binary
To do that we write a for loop where the number is being devided by the numbers of 1*2 until i <= 16
+ 2.2 Convert it to 16-digit binary
+ 2.6 Print out the result
+ 3. Work around invalid input
+ 3.5 Decompose main a little bit for testing
4. Test
5. Cpplint test
6. Add and push
*/

#include <stdio.h>
// Math import to work around invalid input - I need to find remainder from a double
#include <math.h>

// Double input number is used to get rid of invalid input
double input_number();
void convert_to_binary(int number);
void print_invalid_input();
void run_convert_to_binary(int number, double number_remainder);
void test_binary(int number, char expected[]);

int main() {
    double number = input_number();
    // Value for invalid input
    double number_remainder = remainder(number, 1);
    run_convert_to_binary(number, number_remainder);
    // Tests to run will be here

    return 0;
}

// void test_binary(int number, char expected[]) {
//     double test_number_remainder = remainder(number, 1);
//     char current[] = run_convert_to_binary(number, test_number_remainder);
// }

void run_convert_to_binary(int number, double number_remainder) {
    if (number_remainder == 0) { 
        convert_to_binary(number);
    } else {
        print_invalid_input();
    }
}

void print_invalid_input() {
    printf("n/a");
}

void convert_to_binary(int number) {
    int divisor = 32768, result;
    printf("Binary number equivalent to said decimal number is:\n");
    for (int i = 1; i <= 16; i++) {
        result = number / divisor;
        if (result >= 1) {
            printf("1");
            number -= divisor * result;
            divisor /= 2;
        } else {
            printf("0");
            divisor /= 2;
        }
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
