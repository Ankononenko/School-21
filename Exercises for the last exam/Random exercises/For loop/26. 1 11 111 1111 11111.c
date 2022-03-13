// Copyright 2022 finchren
/*
 Write a program in C to find the sum of the series 1 +11 + 111 + 1111 + .. n terms. Go to the editor
Test Data :
Input the number of terms : 5
Expected Output :
1 + 11 + 111 + 1111 + 11111
The Sum is : 12345

+ 1. Take input of terms to count the series of numbers
+ 2. Write for loop to display the addition operation
+ 2.5 Display the sum
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int main() {
    int number_of_terms, starting_point = 1, square_of_ten = 10, sum = 0;
    char endline;
    printf("Input the number of terms:\n");
    if (scanf("%d%c", &number_of_terms, &endline) &&
    ((endline == ' ') || (endline == '\n')) &&
    (number_of_terms > 0)) {
        for (int i = 0; i <= number_of_terms; i++) {
            printf("%d", starting_point);
            sum += starting_point;
            starting_point += square_of_ten;
            square_of_ten *= 10;
            if (i != number_of_terms) {
                printf(" ");
            }
        }
        printf("\nThe Sum is: %d", sum);
    } else {
        printf("n/a");
    }
    return 0;
}
