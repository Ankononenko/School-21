// Copyright 2022 finchren
#include "s21_string.h"

int s21_strlen(char *string) {
  char *pointer = string;
  while (*pointer != '\0')
    pointer++;
  return pointer - string;
}

int s21_strcmp(char *first_string, char *second_string) {
    int char_compare_status = 0;
    while ((*first_string != '\0' && *second_string != '\0') && (*first_string == *second_string)) {
        first_string++;
        second_string++;
    }
    // Compare the mismatching character
    char_compare_status = (*first_string == *second_string)?0:(*first_string > *second_string)?1:-1;
    return char_compare_status;
}

char *s21_strcpy(char* destination, const char *source) {
    // take a pointer pointing to the beginning of the destination string
    char *pointer = destination;
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    // include the terminating null character
    *destination = '\0';
    // the destination is returned by standard `strcpy()`
    return pointer;
}

char *(strcat) (char *s1, const char *s2) {
    char *s;
    for (s = s1; *s != '\0'; ++s) 
    for (; (*s = *s2) != '\0'; ++s, ++s2)
    return s1;
}