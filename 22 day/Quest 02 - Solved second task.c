// Copyright 2022 finchren
#include "cipher.h"

int main() {
    #ifdef cipher
    int loop = 1, mode_num;
    char filename[NMAX];
    while (loop) {
        scanf("%d", &mode_num);
            if (mode_num == 1) {
                scanf("%s", filename);
                if (open_and_output(filename) == 1) {
                    printf("n/a\n");
                }
            } else if (mode_num == 2) {
                if (write_to_a_file(filename) == 1) {
                    char ch = getc(stdin);
                    while (ch != EOF && ch != '\n' && ch != ' ') {
                    ch = getc(stdin);
                    }
                    printf("n/a\n");
                }
                open_and_output(filename);
            } else if (mode_num == -1) {
                loop = 0;
                } else {
                char c = getc(stdin);
                while (c != EOF && c != '\n' && c != ' ') {
                c = getc(stdin);
                }
                printf("n/a\n");
            }
    }
    #endif
    return 0;
}

int write_to_a_file(char *filename) {
    char string_to_add[NMAX], word;
    word = getchar();
    FILE *file_to_open;
    file_to_open = fopen(filename, "r");
    if (file_to_open == NULL) {
        return 1;
    }
    file_to_open = fopen(filename, "a");
    // Append to a file
    for (int i = 0; (word = getchar()) != '\n'; i++) {
       string_to_add[i] = word;
       fprintf(file_to_open, "%c", word);
    }
    fclose(file_to_open);
    return 0;
}

int open_and_output(char *filename) {
    FILE *file_to_open;
    char string_to_output;
    file_to_open = fopen(filename, "r");
    if (file_to_open == NULL) {
        return 1;
    }
    // Read from the file
    string_to_output = fgetc(file_to_open);
    while (string_to_output != EOF) {
        printf("%c", string_to_output);
        string_to_output = fgetc(file_to_open);
    }
    fclose(file_to_open);
    printf("\n");
    return 0;
}
