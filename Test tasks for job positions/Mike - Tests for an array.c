// Copyright 2022 finchren
/*
Дан массив чисел [1, 2, 3, 4 ,5]. 
Найти максимальное и предмаксимальное значение и перемножить их, вывести результат
Например, [1, 2, 3, 4 ,5] -> 4 * 5 = 20

+ 0. Remember how to use max and min values in math.h - #include <limits.h> INT_MIN INT_MAX
+ 1. Write a loop to find max
+ 2. Write a fucntion to find pre-max
+ 3. Multiply
+ 4. Output the result
5. Test
6. Cpplint test
7. Add and push
*/

#include <stdio.h>

void test();
int get_product(int *array, int array_size);

int main() {
    test();
    return 0;
}

void test() {
    int array_1[10] = {1, 0, 0, 4 ,5, 60, 7, 0, 0, 0};
    int array_size_1 = (int)sizeof(array_1) / 4;

    int expected_1 = 420;
    int actual_1 = get_product(array_1, array_size_1);
    if (expected_1 == actual_1) {
        printf("Success");
    } else {
        printf("Failed");
        printf("Expected = %d, actual = %d\n", expected_1, actual_1);
    }
    printf("\n");
    
    int array_2[9] = {70, 0, 0, 5 ,5, 7, 7, 0, 100};
    int array_size_2 = (int)sizeof(array_2) / 4;

    int expected_2 = 7000;
    int actual_2 = get_product(array_2, array_size_2);
    if (expected_2 == actual_2) {
        printf("Success");
    } else {
        printf("Failed");
        printf("Expected = %d, actual = %d\n", expected_2, actual_2);
    }
    printf("\n");

    int array_3[9] = {70, 0, 0, 5 ,5, 7, 7, 0, 10};
    int array_size_3 = (int)sizeof(array_3) / 4;

    int expected_3 = 700;
    int actual_3 = get_product(array_3, array_size_3);
    if (expected_3 == actual_3) {
        printf("Success");
    } else {
        printf("Failed\n");
        printf("Expected = %d, actual = %d\n", expected_3, actual_3);
    }
    printf("\n");
}

int get_product(int *array, int array_size) {
    int max = array[0], premax = array[0];
    for (int i = 0; i <= array_size - 1; ++i) {
            if (array[i] > max) {
                max = array[i];
            }
    }
    for (int j = 0; j <= array_size - 1; ++j) {
        if (array[j] < max && premax < array[j]) {
            premax = array[j];
        }
    }
    return (max * premax);
}
