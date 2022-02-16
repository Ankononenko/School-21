#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_
#include <stdio.h>

#define N1_EXPECTED_STRLEN 11
#define N2_EXPECTED_STRLEN 13
#define N3_EXPECTED_STRLEN 1
#define N4_EXPECTED_STRLEN 1

#define N1_EXPECTED_STRCMP 0
#define N2_EXPECTED_STRCMP -1
#define N3_EXPECTED_STRCMP 0

char expected_normal_value_one_strcat[12] = "helloworld";

char normal_value_one_strlen[11] = "test value";
char normal_value_two_strlen[13] = "7337 test\n \t";
char abnormal_value_one_strlen = 0;
char boundary_value_min_strlen = '\0';

char normal_value_one_strcmp[6] = "first";
char normal_value_two_strcmp[6] = "first";
char abnormal_value_one_strcmp[4] = "one";
char abnormal_value_two_strcmp[4] = "two";
char boundary_value_one_strcmp[2] = " ";
char boundary_value_two_strcmp[2] = " ";

char normal_value_one_strcpy[6] = "hello";
char destination_normal_value_one_strcpy[6];
char abnormal_value_one_strcpy[3] = "he";
char destination_abnormal_value_one_strcpy[4];
char boundary_value_one_strcpy[6] = "hello";
char destination_boundary_value_one_strcpy[4];

void success();
void fail();
void s21_strlen_test(char *test_value, int n);
void s21_strcmp_test(char *first_string, char *second_string, int n);
void s21_strcpy_test(char* destination, const char* source);
void s21_strcat_test(char *first_string, char *second_string, char *result);

#endif  // SRC_S21_STRING_TEST_H_
