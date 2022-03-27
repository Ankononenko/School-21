// Copyright 2022 ficnhren
/*
Write a program in C to find the number and sum of all integer between 100 and 200 which are divisible by 9
Expected Output :
Numbers between 100 and 200, divisible by 9 :
108 117 126 135 144 153 162 171 180 189 198
The sum : 1683

+ 1. Write a function to count and output
+ 2. Test
+ 3. Cpplint test
+ 4. Add and push
*/

#include <stdio.h>

void count_and_print_inrange_divisible_by(int start, int end, int divisor);

int main() {
    int start =  100, end = 200, divisor = 9;
    count_and_print_inrange_divisible_by(start, end, divisor);
    return 0;
}

void count_and_print_inrange_divisible_by(int start, int end, int divisor) {
    printf("Numbers between %d and %d, divisible by %d:\n", start, end, divisor);
    for (int i = start; i <= end; i++) {
        if (i % 9 == 0) {
            printf("%d ", i);
        }
    }
}
