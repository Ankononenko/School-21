#include <stdio.h>
#define NMAX 20
struct Person {
        char first_name[NMAX];
        char last_name[NMAX];
        int height;
    };
void input(struct Person* people, int number_of_elements);
void output(struct Person* people, int number_of_elements, int h_number);
int main() {
    // Declaration of array named "people" of structure Person
    struct Person people[NMAX];
    int number_of_elements = 0;
    scanf("%d", &number_of_elements);
    input(people, number_of_elements);
    int h_number = 0;
    scanf("%d", &h_number);
    output(people, number_of_elements, h_number);
    
    return 0;
}
void input(struct Person* people, int number_of_elements) {
    for (int i = 0; i < number_of_elements; i++) {
        scanf("%s", people[i].first_name);
        scanf("%s", people[i].last_name);
        scanf("%d", &people[i].height);
    }
}
void output(struct Person* people, int number_of_elements, int h_number) {
    for (int i = 0; i < number_of_elements; i++) {
        if (people[i].height >= h_number) {
            printf("%s ", people[i].first_name);
            printf("%s", people[i].last_name);
            }
        if (i < number_of_elements - 2) {
            printf(", ");
        }
    }
}
