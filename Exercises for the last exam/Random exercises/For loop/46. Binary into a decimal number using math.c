// Copyright 2022 finchren
/*
Write a program in C to convert a binary number into a decimal number using math function
Test Data :
Input the binary number :1010100
Expected Output :
The Binary Number : 1010100
The equivalent Decimal Number is : 84

+ 1. Take input. Max range of int is 2,147,483,647, so I'm going to take the maximum binary number of
31 characters long. 1111111111111111111111111111111 ==  2,147,483,647
1.5 Invalid input
2. Figure out how to use math library to find the decimal number
3. Convert to decimal
4. Output
5. Test
6. Cpplint test
7. Add and push
*/

#include <stdio.h>
#include <math.h>

char input_binary();

int main() {
    char input_array = input_binary();
    printf("%c", input_array);
    return 0;
}

char input_binary() {
    int lenght = 31;
    char input_string_array[lenght];
    for (int i = 0; i <= lenght; i++) {
        scanf("%1c", &input_string_array[i]);
        if (input_string_array[i] == '\n') {
            lenght = i - 1;
            break;
        }
    }
    // for (int i = 0; i <= lenght; i++) {
    //     printf("%c", input_string_array[i]);
    // }
    return *input_string_array;
}
