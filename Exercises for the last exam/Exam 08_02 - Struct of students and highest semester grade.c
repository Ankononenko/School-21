// Copyright 2022 finchren
#include <stdio.h>
#define NMAX 20

struct Students {
    char first_name[NMAX];
    char last_name[NMAX];
    int semester_grade;
};

int input_number_of_students();
int input_names_and_grades(struct Students* array, int number_of_students);
int maximum_grade_of_students(struct Students* array, int number_of_students);
int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value);
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
int number_of_top_students, int maximum_grade_value);

int main() {
    int number_of_students = input_number_of_students();
    if (number_of_students > 0) {
        struct Students array[number_of_students];
        if (input_names_and_grades(array, number_of_students) == 0) {
            int maximum_grade_value = maximum_grade_of_students(array, number_of_students);
            int number_of_top_students = count_top_grade_students(array,
            number_of_students, maximum_grade_value);
            output_names_and_grades_of_top_students(array, number_of_students,
            number_of_top_students, maximum_grade_value);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int maximum_grade_of_students(struct Students* array, int number_of_students) {
    int maximum_grade_value = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (maximum_grade_value < array[i].semester_grade) {
            maximum_grade_value = array[i].semester_grade;
        }
    }
    return maximum_grade_value;
}

int count_top_grade_students(struct Students* array, int number_of_students, int maximum_grade_value) {
    int counter = 0;
    for (int j = 0; j < number_of_students; j++) {
        if (array[j].semester_grade == maximum_grade_value) {
            counter++;
        }
    }
    return counter;
}
void output_names_and_grades_of_top_students(struct Students* array, int number_of_students,
int number_of_top_students, int maximum_grade_value) {
    for (int i = 0; i < number_of_students; i++) {
        if (array[i].semester_grade == maximum_grade_value) {
            printf("%s %s %d", array[i].first_name, array[i].last_name, array[i].semester_grade);
            if (i < number_of_top_students) {
                printf(", ");
            }
        }
    }
}

int input_names_and_grades(struct Students* array, int number_of_students) {
    char endline;
    int return_case = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (!scanf("%s%c", array[i].first_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%s%c", array[i].last_name, &endline) || endline != '\n') {
            return_case = 1;
            break;
        }
        if (!scanf("%d%c", &array[i].semester_grade, &endline) ||
        array[i].semester_grade < 0 || endline != '\n') {
            return_case = 1;
            break;
        }
    }
    return return_case;
}

int input_number_of_students() {
    int number;
    char endline;
    if (!scanf("%d%c", &number, &endline) || endline != '\n') {
        number = -1;
    }
    return number;
}

/*
Build a structure of Students, there is name and lastname and grade of a student
Create a program to output the first and lastname of those students, whose grades are at the top
Output result - "First name, Last name, Second first name, Second last name"
In case of invalid input, output - "n/a"
Maximum length of a name is 20 chars long, total number of students is entered beforehand. The input in entered one line at a time - \n
Grade cannot be negative. Name is a string without spaces and with a newline at the end
*/

/*
+ 1. Build a structure of Students
+ 2. Take input - total number of Students
+ 3. Take input of names and grades 
+ 4. Write a function to count how many of top students are there
+ 5. Write a fucntion to output them to the screen
+ 6. Invalid input
+ 7. Test
+ 8. Cpplint check
+ 9. Push to Github
*/
