// Copyright 2022 finchren
#include "s21_string.h"
#include "s21_string_test.h"

int main () {

    // printf("%d\n", s21_strlen_test(normal_value_one));
    test_module(normal_value_one, N1);
    // printf("%d\n", s21_strlen_test(normal_value_two));
    test_module(normal_value_two, N2);
    // printf("%d\n", s21_strlen_test(&abnormal_value_one));
    test_module(&abnormal_value_one, N3);
    // printf("%d\n", s21_strlen_test(boundary_value_min));
    test_module(&boundary_value_min, N4);

    return 0;
}

void success() {
    printf("SUCCESS\n");
}

void fail() {
    printf("FAIL\n");
}

void test_module(char *test_value, int N) {
    // printf("%d", s21_strlen_test(test_value));
    // printf("%d", N);
    if (s21_strlen_test(test_value) == N - 1) {
        success();
    } else {
        fail();
    }
}