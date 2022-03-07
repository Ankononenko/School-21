// Copyright 2022 finchren
/* 
Write a program in C to make such a pattern like a pyramid with numbers increased by 1. Go to the editor
   1 
  2 3 
 4 5 6 
7 8 9 10 

1. Take the input
2. Display the pyramid
3. Work around invalid input
4. Test
5. Cpplint test
6. Add and push
*/

#include <stdio.h>

int main() {
    int number;
    char endline;
    if (scanf("%d%c", &number, &endline) && ((endline == ' ') || (endline == '\n'))) {
        for (int i = 1; i <= number; i++) {
            for (int j = 1; j <= i; j++) {
                
            }      
        }
    } else {
        printf("n/a");
    }
    return 0;
}
