#include "data_io.h"
#include "data_stat.h"

void main()
{
    double *data;
    int n;

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);
    
    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);
    
    printf("\nFINAL DECISION:\n\t");
    //make_decision(data, n);
    //...
    
}
