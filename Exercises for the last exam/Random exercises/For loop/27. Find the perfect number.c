// Copyright 2022 finchren
/* 
Write a c program to check whether a given number is a perfect number or not
Test Data :
Input the number : 56
Expected Output :
The positive divisor : 1 2 4 7 8 14 28
The sum of the divisor is : 64
So, the number is not perfect.

+ 1. Take the input
+ 2. Display the divisors
+ 2.5 Display the sum
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int main() {
    int input_number, sum = 0;
    char endline;
    if (scanf("%d%c", &input_number, &endline) &&
    ((endline == ' ') || (endline == '\n')) &&
    (input_number > 0)) {
        printf("The positive divisor: ");
        for (int i = 1; i < input_number; i++) {
            if (input_number % i == 0) {
                printf("%d ", i);
                sum += i;
            }
        }
        if (sum == 1) {
            printf("\nThe number %d is perfect", input_number);
        } else {
            printf("\nThe sum of the divisor is: %d", sum);
            printf("\nSo, the number %d is not perfect.", input_number);
        }
    } else {
        printf("n/a");
    }
    return 0;
}
