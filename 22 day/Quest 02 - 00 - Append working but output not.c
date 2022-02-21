// Copyright 2022 finchren
#include "cipher.h"

int open_write_output (char *string_to_write, char *filename);

int main() {
    #ifdef cipher
    int loop = 1, mode_num;
    char filename[NMAX], string_to_add[NMAX];
    while (loop) {
        scanf("%d", &mode_num);
            if (mode_num == 1) {
                scanf("%s", filename);
                if (open_and_output(filename) == 1) {
                    printf("n/a\n");
                }
            } else if (mode_num == 2) {
                printf("Second opttion\n");
                scanf("%s", string_to_add);
                if (open_write_output(string_to_add, filename) == 1) {
                    printf("n/a\n");
                }
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

int open_write_output (char *string_to_write, char *filename) {
    printf("%s\n", string_to_write);
    FILE *file_to_open;
    char string_to_output;
    file_to_open = fopen(filename, "a");
    if (file_to_open == NULL) {
        return 1;
    }
    // Append to a file
    fprintf(file_to_open, "\n%s", string_to_write);
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
