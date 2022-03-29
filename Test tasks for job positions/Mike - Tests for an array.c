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
+ Decompose the code
+ 5. Write the test cases
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

void test(int array[], int expected, int array_size, int test_number);
int get_product(int array[], int array_size);

int main() {
    // Test for values in the middle of the array
    int array_1[10] = {1, 0, 0, 4, 5, 60, 7, 0, 0, 0};
    test(array_1, 420, 10, 1);
    // Test for values on the other sides of the array
    int array_2[10] = {70, 0, 0, 4, 5 , 60, 7, 0, 0, 80};
    test(array_2, 5600, 10, 2);
    // Duplicate value test
    int array_3[10] = {70, 70, 70, 70, 5 , 60, 80, 80, 80, 80};
    test(array_3, 5600, 10, 3);
    // Zeros and duplicate values
    int array_4[10] = {0, 0, 0, 0, 60, 60, 0, 10, 80, 80};
    test(array_4, 4800, 10, 4);
    // Failed test from the call with Mike
    int array_5[9] = {70, 0, 0 , 5, 5, 7, 7, 0, 10};
    test(array_5, 700, 9, 5);
    return 0;
}

void test(int array[], int expected, int array_size, int test_number) {
    int actual = get_product(array, array_size);
    if (expected == actual) {
        printf("\nSuccess");
        printf("\nTest number %d: Expected = %d, actual = %d", test_number, expected, actual);
    } else {
        printf("\nFailed");
        printf("\nTest number %d: Expected = %d, actual = %d", test_number, expected, actual);
    }
    printf("\n");
}

int get_product(int array[], int array_size) {
    int max = array[0], min = array[0];
    // For loop to find maximum value
    for (int i = 0; i < array_size; ++i) {
            if (array[i] > max) {
                max = array[i];
            }
    }
    // For loop to find minimum value to have a value for premax staring point
    for (int i = 0; i < array_size; ++i) {
            if (array[i] < min) {
                min = array[i];
            }
    }
    int premax = min;
    // For loop to find premaximum value
    for (int j = 0; j < array_size; ++j) {
        if (array[j] < max && array[j] > premax) {
            premax = array[j];
        }
    }
    printf("max - %d, min - %d, premax - %d", max, min, premax);
    return (max * premax);
}
