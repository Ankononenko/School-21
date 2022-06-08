// Here I'm going to learn how to use structures in C
/*
+ 1. Learn how to initialize the structure
+ 2. How to write to the structure
+ 3. Read values
+ 4. Pass to the functions
+ 5. Modify the values in the functions
*/

#include <stdio.h>
#include <string.h>

struct students {
    char nickname[50];
    int level;
    char passed[4];
};

void write_to_the_structure(struct students *school21);
void print_out_the_structure(const struct students *school21);

int main() {
    struct students school21;
    write_to_the_structure(&school21);
    print_out_the_structure(&school21);
    return 0;
}

void write_to_the_structure(struct students *school21) {
    strcpy(school21->nickname, "elviaatt");
    school21->level = 1;
    strcpy(school21->passed, "Yes");
}

void print_out_the_structure(const struct students *school21) {
    printf("School21 student %s is %d level high.\n"
        "Has he passed the final exam of the first month?\n"
        "%s.\n", school21->nickname, school21->level, school21->passed);
}
