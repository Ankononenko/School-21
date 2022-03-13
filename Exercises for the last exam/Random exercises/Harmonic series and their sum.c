// Copyright 2022 finchren
/* 
Write a program in C to display the n terms of harmonic series and their sum.
1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms
Test Data :
Input the number of terms : 5
Expected Output :
1/1 + 1/2 + 1/3 + 1/4 + 1/5 +
Sum of Series upto 5 terms : 2.283334

+ 1. Take the input of n
+ 2. Write a function to display expected output 
+ 3. Write a function to count sum
+ 4. Display the sum
+ 5. Invalid input
+ 6. Test
+ 7. Cpplint test
8. Add and push
*/

#include <stdio.h>

int input_n();
void display_expected(int n);
double count_sum(int n);
void display_sum(double sum, int n);
void invalid_input();

int main() {
    int n = input_n();
    if (n > 0) {
        display_expected(n);
        double sum = count_sum(n);
        display_sum(sum, n);
    } else {
        invalid_input();
    }
    return 0;
}

void invalid_input() {
    printf("n/a");
}

void display_sum(double sum, int n) {
    printf("Sum of Series upto %d terms: %lf", n, sum);
}

double count_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

void display_expected(int n) {
    for (int i = 1; i <= n; i++) {
        printf("1/%d", i);
        if (i != n) {
            printf(" + ");
        }
    }
    printf("\n");
}

int input_n() {
    int n;
    char endline;
    printf("Input the number of terms:\n");
    if ((!scanf("%d%c", &n, &endline)) || (endline != '\n')) {
        n = 0;
    }
    return n;
}
