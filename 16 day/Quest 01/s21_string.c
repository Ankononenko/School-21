// Copyright 2022 finchren
#include "s21_string.h"

int s21_strlen_test(char *string) {
  char *pointer = string;
  while (*pointer!='\0')
    pointer++;
  return pointer - string;
}
