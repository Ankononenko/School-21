// Copyright 2022 finchren
#include <stdio.h>

int main() {
    int kArrayLenght, counter_for_output, temp;
    if (scanf("%d", &kArrayLenght)) {
        if (kArrayLenght > 0) {
            int array_of_numbers[kArrayLenght];
            counter_for_output = kArrayLenght;
            for (int i = 0; i < kArrayLenght; i++) {
                if (!scanf("%d", &temp)) {
                    printf("n/a");
                    return 1;
                } else if (temp == -1) {
                    kArrayLenght = i;
                } else {
                    array_of_numbers[i] = temp;
                    }
            }
            printf("Array of numbers after input:\n");
            for (int i = 0; i < kArrayLenght; i++) {
                printf("%d", array_of_numbers[i]);
                if (i < kArrayLenght - 1) {
                    printf(" ");
                } else if (i == kArrayLenght - 1) {
                    printf("\n");
                }
            }
            printf("Array of numbers multiplied:\n");
            for (int j = 0; j < kArrayLenght; j++) {
                printf("%d", array_of_numbers[j] * counter_for_output);
                counter_for_output--;
                if (j < kArrayLenght - 1) {
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
