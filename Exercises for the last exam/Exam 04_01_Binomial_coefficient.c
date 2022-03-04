// Copyright 2022 finchren

#include <stdio.h>

int factorial(int number);
int c_formula(int number, int k);

int main() {
    int number;
    scanf("%d", &number);
    for (int k = 0; k <= number; k++) {
        printf("%d", c_formula(number, k));
        if (k != number) {
            printf(" ");
        }
    }
    return 0;
}

int factorial(int number) {
    int number_to_return = 1;
    for (int i = 1; i <= number; i++) {
        number_to_return *= i;
    }
    return number_to_return;
}

int c_formula(int number, int k) {
    int result = factorial(number) / (factorial(k) * factorial(number - k));
    return result;
}
