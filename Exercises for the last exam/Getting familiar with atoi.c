// Copyright 2022 finchren
#include <stdio.h>
#include <stdlib.h>

int main() {
    char char_numbers[3] = "123";
    int num_numbers = atoi(char_numbers);
    printf("%d\n", num_numbers * 3);
    printf("%s\n", char_numbers);
    return 0;
}
