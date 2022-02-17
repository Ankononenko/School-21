#include "door_struct.h"

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    bubble_sort(doors);
    close_doors(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0)); 
    
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void bubble_sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j+1].id) {
                int temp = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = temp;
            }
        }
    }
}

void close_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (doors[i].status == 1) {
            doors[i].status = 0;
            }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        printf("%d, %d\n", doors[i].id, doors[i].status);
}