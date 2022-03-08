// Copyright 2022 finchren
/* 
Write a program in C to make such a pattern like a pyramid with numbers increased by 1. As input it takes the number of elements
   1 
  2 3 
 4 5 6 
7 8 9 10 

+ 1. Take the input
+ 2. Display the numbers of the pyramid
+ 2.5 Display the spaces of the pyramid
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int number_of_rows(int number);
void print_spaces(int number_of_rows);

int main() {
    int input_number, output_number = 1, rows;
    char endline;
    if (scanf("%d%c", &input_number, &endline) && ((endline == ' ') || (endline == '\n'))) {
        rows = number_of_rows(input_number);
        for (int i = 1; i <= input_number; i++) {
            print_spaces(rows);
            for (int j = 0; j < i; j++) {
                printf("%d ", output_number);
                input_number -= 1;
                output_number++;
            }
            printf("\n");
            rows -= 1;
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void print_spaces(int number_of_rows) {
    for (int i = number_of_rows - 1; i > 0; i--) {
        printf(" ");
        }
}

int number_of_rows(int number) {
    int result = 0;
    for (int i = 1; i <= number; i++) {
        for (int j = 0; j < i; j++) {
                number -= j;
            }
        result++;
    }
    return result;
}
