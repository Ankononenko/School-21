#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_
#include <stdio.h>

#define N1 11
#define N2 13
#define N3 1
#define N4 1
// #define N6

char normal_value_one[11] = "test value";
char normal_value_two[13] = "7337 test\n \t";
char abnormal_value_one = 0;
char boundary_value_min = '\0';

void success();
void fail();
void test_module(char *test_value, int N);

#endif  // SRC_S21_STRING_TEST_H_