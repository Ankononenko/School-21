// Copyright 2022 finchren
/*
Write a program in C to display the n terms of square natural number and their sum. Go to the editor
1 4 9 16 ... n Terms
Test Data :
Input the number of terms : 5
Expected Output :
The square natural upto 5 terms are :1 4 9 16 25
The Sum of Square Natural Number upto 5 terms = 55

+ 1. Take input of number to the squares
+ 2. Write for loop to display the squares
+ 2.5 Display the sum
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int main() {
    int number, sum, square;
    char endline;
    printf("Enter a number of terms to display and count the sum of:\n");
    if (scanf("%d", &number)) {
        endline = getchar();
        if ((number > 0) && ((endline == ' ') || (endline == '\n'))) {
            printf("The square natural upto 5 terms are:");
            for (int i = 1; i <= number; i++) {
                square = i * i;
                sum += square;
                printf("%d", square);
                if (i != number) {
                    printf(" ");
                }
            }
            printf("\nThe Sum of Square Natural Number upto %d terms = %d", number, sum);
        } else {
        printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}
