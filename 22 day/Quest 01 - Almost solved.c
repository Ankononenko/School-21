// Copyright 2022 finchren
#include <stdio.h>
#define NMAX 100

int get_mode();
void get_filename(char *filename);

int main() {

    int loop = 1, mode_num;
    char filename[NMAX];

    while (loop) {

        mode_num = get_mode();
        switch (mode_num) {
        
        case 1:
            get_filename(filename);
            FILE *file_to_open; 
            char string_to_output;
            file_to_open = fopen(filename, "r");
            if (file_to_open == NULL) {
                printf("n/a");
                printf("\n");
                break;
            }
            // Read from the file
            string_to_output = fgetc(file_to_open);
            while (string_to_output != EOF) {
                printf("%c", string_to_output);
                string_to_output = fgetc(file_to_open);
            }
            fclose(file_to_open);
            printf("\n");
            break;
        
        case -1: 
            loop = 0;
            break;
        
        default:
            printf("n/a\n");
            getchar();
            break;
        }
    }
    
    return 0;
}

int get_mode() {
    int mode_num_to_return;
    scanf("%d", &mode_num_to_return);
    return mode_num_to_return;
}

void get_filename(char *filename) {
    scanf("%s", filename);
}

/*
+ 1. Create a console menu for the program
+ 2. Learn how to open, read and output file to the console using c code
+ 3. Work around invalid input
+ 4. Work around empty file
+ 5. Work around any other invalid inpput
+ 6. Implement -1 to exit the program
+ 7. After executing each menu item there should me a newline.
8. Build the project using Makefile. Stage name - cipher, executable file name - cipher. Executable in build folder
*/

/* 
Create an src/cipher.c program. Add a console menu to the program and implement its first item – 
specifying the path to the text file via stdin, to open, read, and output it to the console. 
If the file is empty or does not exist or any other error, then output "n/a". 
If -1 is applied to the input, the program should exit. After executing each menu item, 
except -1, there should be a new line. Build the project using the Makefile. Stage name: cipher. 
Executable file name: cipher. The executable file must be located in the root of the repository in the build folder. ==
*/

// fopen - to open a file 
// FILE* fopen(const char* filename, const char* mode);
// void fclose(FILE *stream);
// int fscanf(FILE *stream, const char *format, ...) 
// int fprintf(FILE *stream, const char *format, ...)
