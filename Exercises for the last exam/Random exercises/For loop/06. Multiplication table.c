// Copyright 2022 finchren
/* 
Write a program in C to display the multiplication table of a given integer. Go to the editor
Test Data :
Input the number (Table to be calculated) : 15
Expected Output :
15 X 1 = 15
...
...
15 X 10 = 150

+ 1. Take the input
+ 2. Display the multiplication table
+ 3. Work around invalid input
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int main() {
    int number, result;
    char endline;
    if (scanf("%d%c", &number, &endline) && ((endline == ' ') || (endline == '\n'))) {
        for (int i = 1; i <= 10; i++) {
            result = number * i;
            printf("%d x %d = %d\n", number, i, result);
        }
    } else {
        printf("n/a");
    }
    return 0;
}
