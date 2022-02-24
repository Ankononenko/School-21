// Copyright 2022 finchren
#include <stdio.h>

int main() {
    int n, counter_for_output;
    if (scanf("%d", &n)) {
        if (n > 0) {
            int array_of_numbers[n];
            counter_for_output = n;
            for (int i = 0; i < n; i++) {
                if (!scanf("%d", &array_of_numbers[i])) {
                    printf("n/a");
                    return 1;
                }
            }
            printf("Array of numbers after input:\n");
            for (int i = 0; i < n; i++) {
                printf("%d", array_of_numbers[i]);
                if (i < n - 1) {
                    printf(" ");
                }
                else if (i == n - 1) {
                    printf("\n");
                }
            }
            printf("Array of numbers multiplied:\n");
            for (int j = 0; j < n; j++) {
                printf("%d", array_of_numbers[j] * counter_for_output);
                counter_for_output--;
                if (j < n - 1) {
                    printf(" ");
                }
            }
        } else {
        printf("n/a");
    }
    } else {
        printf("n/a");
    }
}

/*
Задание №2
Дана последовательность целых чиселЧисло nСимвол конца -1
Вывести x1 xn x2 xn-1 x3 xn-2 и так далее
*/
