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
    // Check if input is a number and there isn't any characters at the end except for space or a newline
    if (scanf("%d%c", &input_number, &endline) && ((endline == ' ') || (endline == '\n'))) {
        rows = number_of_rows(input_number) - 1;
        // Check to see if we can build a symmetric pyramid out of the input number
        if (rows > 0) {
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
        printf("The symmetric pyramid cannot be build out of that number \n"
        "Allowed numbers are 10, 15, 21, 28, 36, 45, 55, 66, 78 etc \n"
        "Int the pyramid each row is begger than previos by one digit \n");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void print_spaces(int number_of_rows) {
    for (int i = number_of_rows; i > 0; i--) {
        printf(" ");
        }
}

// The function returns zero in case of invalid input
// Invalid input - symmetric piramid cannot be build
int number_of_rows(int number) {
  int result = 0, counter = 0, temp = 0;
    for (int i = 1; i <= number; i ++) {
        temp += i;
        counter++;
        if (temp == number) {
        result = counter;
        }
        if (temp > number) {
          break;
        }
    }
    return result;
}
