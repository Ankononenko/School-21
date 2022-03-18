// Copyright 2022 finchren
/*
Write a c program to find the perfect numbers within a given number of range. 
Test Data :
Input the starting range or number : 1
Input the ending range of number : 50
Expected Output :
The Perfect numbers within the given range : 6 28

+ 1. Take input of start and end
+ 2. Write a function to find perfect numbers in that range and display them
+ 3. Invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int input_start();
int input_end();
void find_perfect_numbers(int start, int end);
void print_invalid();

int main() {
    int start = input_start();
    if (start > 0) {
        int end = input_end();
        if (end > 0) {
            find_perfect_numbers(start, end);
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

void find_perfect_numbers(int start, int end) {
    printf("The Perfect numbers within the given range:\n");
    for (int number_of_range = start; number_of_range <= end; number_of_range++) {
        int temp_for_perfect_check = 0;
        for (int perfect_check = 1; perfect_check < number_of_range; perfect_check++) {
            if (number_of_range % perfect_check == 0) {
                temp_for_perfect_check += perfect_check;
            }
        }
        if (temp_for_perfect_check == number_of_range) {
            printf("%d ", number_of_range);
        }
    }
}

int input_start() {
    int start;
    char endline;
    printf("Input the starting range or number:\n");
    if (!scanf("%d%c", &start, &endline) || endline != '\n' || start < 1) {
        start = 0;
    }
    return start;
}

int input_end() {
    int end;
    char endline;
    printf("Input the ending range of number:\n");
    if (!scanf("%d%c", &end, &endline) || endline != '\n' || end < 1) {
        end = 0;
    }
    return end;
}
