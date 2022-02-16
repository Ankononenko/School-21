// Copyright 2022 finchren
#include "s21_string.h"
#include "s21_string_test.h"

int main() {
    #ifdef Quest_1
        s21_strlen_test(normal_value_one_strlen, N1_EXPECTED_STRLEN);
        s21_strlen_test(normal_value_two_strlen, N2_EXPECTED_STRLEN);
        s21_strlen_test(&abnormal_value_one_strlen, N3_EXPECTED_STRLEN);
        s21_strlen_test(&boundary_value_min_strlen, N4_EXPECTED_STRLEN);
    #endif

    #ifdef Quest_2
        s21_strcmp_test(normal_value_one_strcmp, normal_value_two_strcmp, N1_EXPECTED_STRCMP);
        s21_strcmp_test(abnormal_value_one_strcmp, abnormal_value_two_strcmp, N2_EXPECTED_STRCMP);
        s21_strcmp_test(boundary_value_one_strcmp, boundary_value_two_strcmp, N3_EXPECTED_STRCMP);
    #endif

    #ifdef Quest_3
    s21_strcpy_test(destination_normal_value_one_strcpy, normal_value_one_strcpy);
    s21_strcpy_test(destination_abnormal_value_one_strcpy, abnormal_value_one_strcpy);
    s21_strcpy_test(destination_boundary_value_one_strcpy, boundary_value_one_strcpy);
    #endif

    char first[6] = "hello";
    char second[6] = "world";
    printf("%s", strcat(first, second));

    return 0;
}

void success() {
    printf("SUCCESS\n");
}

void fail() {
    printf("FAIL\n");
}

void s21_strlen_test(char *test_value, int n) {
    if (s21_strlen(test_value) == n - 1) {
        success();
    } else {
        fail();
    }
}

void s21_strcmp_test(char *first_string, char *second_string, int n) {
    if (s21_strcmp(first_string, second_string) == n) {
        success();
    } else {
        fail();
    }
}

void s21_strcpy_test(char* destination, const char* source) {
    if (s21_strcpy(destination, source)) {
        success();
    } else {
        fail();
    }
}
