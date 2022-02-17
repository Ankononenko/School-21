#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#define DOORS_COUNT 15
#define MAX_ID_SEED 1000

struct door {
    int id;
    int status;
};

void initialize_doors(struct door* doors);
void bubble_sort(struct door* doors);
void close_doors(struct door* doors);
void output(struct door* doors);

#endif  // SRC_DOOR_STRUCT_H_