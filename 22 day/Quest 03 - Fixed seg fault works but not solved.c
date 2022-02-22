// Copyright 2022 finchren
#include "cipher.h"

void open_dir_call_encrypt(char *dir_path);
void encrypt(char *filename);
const char *get_filename_ext(const char *filename);

int main() {
    #ifdef cipher
    int loop = 1, mode_num;
    char filename[NMAX], dir_path[NMAX];
    while (loop) {
        scanf("%d", &mode_num);
            if (mode_num == 1) {
                scanf("%s", filename);
                if (check_if_empty(filename) == 1 || open_and_output(filename) == 1) {
                    char ch = getc(stdin);
                    while (ch != EOF && ch != '\n') {
                    ch = getc(stdin);
                    }
                    printf("n/a\n");
                }
            } else if (mode_num == 2) {
                if (write_to_a_file(filename) == 1) {
                    char ch = getc(stdin);
                    while (ch != EOF && ch != '\n') {
                    ch = getc(stdin);
                    }
                    printf("n/a\n");
                }
                open_and_output(filename);
            } else if (mode_num == 3) {
                scanf("%s", dir_path);
                open_dir_call_encrypt(dir_path);
            } else if (mode_num == -1) {
                loop = 0;
            } else {
                char c = getc(stdin);
                while (c != EOF && c != '\n') {
                c = getc(stdin);
                }
                printf("n/a\n");
            }
    }
    #endif
    return 0;
}

void open_dir_call_encrypt(char *dir_path){
    printf("open_dir_call_encrypt\n");
    DIR *directory;
    // Pointer for directory entry
    struct dirent *dir;
    directory = opendir(dir_path);
    while ((dir = readdir(directory)) != NULL) {
        printf("%s\n", dir->d_name);
        encrypt(dir->d_name);
    }
    closedir(directory);
}

void encrypt(char *filename) {
    printf("encrypt\n");
    printf("filename - %s\n", filename);
    printf("get_filename_ext(filename) - %s\n", get_filename_ext(filename));
    if ((strncmp((get_filename_ext(filename)), "c", 1)) == 0) {
        printf("c - file\n");
    } else if ((strncmp((get_filename_ext(filename)), "h", 1)) == 0) {
        printf("h - file\n");
    } else {
        printf("not expected file - file\n");
    }
}

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int check_if_empty(char *filename) {
    FILE *file_to_open;
    file_to_open = fopen(filename, "r");
    if (file_to_open != NULL) {
        int size;
        fseek(file_to_open, 0, SEEK_END);
        size = ftell(file_to_open);
        if (size == 0) {
            fclose(file_to_open);
            return 1;
        }
    }
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
